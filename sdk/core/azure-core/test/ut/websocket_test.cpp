// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

#include "../../src/http/websockets/websocketsimpl.hpp"
#include "azure/core/http/websockets/websockets.hpp"
#include "azure/core/internal/json/json.hpp"
#include <chrono>
#include <gtest/gtest.h>
#include <list>
#include <thread>
#if defined(BUILD_CURL_HTTP_TRANSPORT_ADAPTER)
#include "azure/core/http/websockets/curl_websockets_transport.hpp"
#endif
// cspell::words closeme flibbityflobbidy

using namespace Azure::Core;
using namespace Azure::Core::Http::WebSockets;
using namespace std::chrono_literals;

class WebSocketTests : public testing::Test {
private:
protected:
  // Create
  static void SetUpTestSuite() {}
  static void TearDownTestSuite()
  {
    //    GTEST_LOG_(INFO) << "Shut down test server" << std::endl;
    //    WebSocket controlSocket(Azure::Core::Url("http://localhost:8000/control"));
    //    controlSocket.Open();
    //    controlSocket.SendFrame("close", true);
    //    auto controlResponse = controlSocket.ReceiveFrame();
    //    EXPECT_EQ(controlResponse->ResultType, WebSocketResultType::TextFrameReceived);
  }
};

TEST_F(WebSocketTests, CreateSimpleSocket)
{
  {
    WebSocket defaultSocket(Azure::Core::Url("http://localhost:8000"));
    defaultSocket.AddHeader("newHeader", "headerValue");
    EXPECT_THROW(defaultSocket.GetChosenProtocol(), std::runtime_error);
  }
}

TEST_F(WebSocketTests, OpenSimpleSocket)
{
  {
    WebSocketOptions options;
    WebSocket defaultSocket(Azure::Core::Url("http://localhost:8000/openclosetest"), options);
    defaultSocket.AddHeader("newHeader", "headerValue");

    defaultSocket.Open();

    EXPECT_THROW(defaultSocket.AddHeader("newHeader", "headerValue"), std::runtime_error);

    // Close the socket without notifying the peer.
    defaultSocket.Close();
  }

  {
    WebSocketOptions options;
    WebSocket defaultSocket(Azure::Core::Url("http://microsoft.com/index.htm"), options);
    defaultSocket.AddHeader("newHeader", "headerValue");

    // When running this test locally, the call times out, so drop in a 5 second timeout on
    // the request.
    Azure::Core::Context requestContext = Azure::Core::Context::ApplicationContext.WithDeadline(
        std::chrono::system_clock::now() + 15s);
    EXPECT_THROW(defaultSocket.Open(requestContext), std::runtime_error);
  }
}

TEST_F(WebSocketTests, OpenAndCloseSocket)
{
  if (false)
  {
    WebSocket defaultSocket(Azure::Core::Url("http://localhost:8000/openclosetest"));
    defaultSocket.AddHeader("newHeader", "headerValue");

    defaultSocket.Open();

    // Close the socket without notifying the peer.
    defaultSocket.Close(4500);
  }

  {
    WebSocket defaultSocket(Azure::Core::Url("http://localhost:8000/openclosetest"));
    defaultSocket.AddHeader("newHeader", "headerValue");

    defaultSocket.Open();

    // Close the socket without notifying the peer.
    defaultSocket.Close(4500, "This is a good reason.");

    //
    // Now re-open the socket - this should work to reset everything.
    defaultSocket.Open();
    EXPECT_THROW(defaultSocket.Open(), std::runtime_error);
    defaultSocket.Close();
  }
}

TEST_F(WebSocketTests, SimpleEcho)
{
  {
    WebSocket testSocket(Azure::Core::Url("http://localhost:8000/echotest"));

    testSocket.Open();

    testSocket.SendFrame("Test message", true);

    auto response = testSocket.ReceiveFrame();
    EXPECT_EQ(WebSocketResultType::TextFrameReceived, response->ResultType);
    EXPECT_THROW(response->AsBinaryFrame(), std::logic_error);
    auto textResult = response->AsTextFrame();
    EXPECT_EQ("Test message", textResult->Text);

    // Close the socket gracefully.
    testSocket.Close();
  }
  {
    WebSocket testSocket(Azure::Core::Url("http://localhost:8000/echotest?delay=20"));

    testSocket.Open();

    std::vector<uint8_t> binaryData{1, 2, 3, 4, 5, 6};

    testSocket.SendFrame(binaryData, true);

    auto response = testSocket.ReceiveFrame();
    EXPECT_EQ(WebSocketResultType::BinaryFrameReceived, response->ResultType);
    EXPECT_THROW(response->AsPeerCloseFrame(), std::logic_error);
    EXPECT_THROW(response->AsTextFrame(), std::logic_error);
    auto textResult = response->AsBinaryFrame();
    EXPECT_EQ(binaryData, textResult->Data);

    // Close the socket gracefully.
    testSocket.Close();
  }

  {
    WebSocket testSocket(Azure::Core::Url("http://localhost:8000/echotest?fragment=true"));

    testSocket.Open();

    std::vector<uint8_t> binaryData{1, 2, 3, 4, 5, 6};

    testSocket.SendFrame(binaryData, true);

    std::vector<uint8_t> responseData;
    std::shared_ptr<Azure::Core::Http::WebSockets::WebSocketResult> response;
    do
    {
      response = testSocket.ReceiveFrame();
      EXPECT_EQ(WebSocketResultType::BinaryFrameReceived, response->ResultType);
      auto binaryResult = response->AsBinaryFrame();
      responseData.insert(responseData.end(), binaryResult->Data.begin(), binaryResult->Data.end());
    } while (!response->IsFinalFrame);

    auto textResult = response->AsBinaryFrame();
    EXPECT_EQ(binaryData, responseData);

    // Close the socket gracefully.
    testSocket.Close();
  }
}

template <size_t N> void EchoRandomData(WebSocket& socket)
{
  std::vector<uint8_t> sendData = Azure::Core::Http::WebSockets::_detail::GenerateRandomBytes(N);

  socket.SendFrame(sendData, true);

  std::vector<uint8_t> receiveData;

  std::shared_ptr<WebSocketResult> response;
  do
  {
    response = socket.ReceiveFrame();
    EXPECT_EQ(WebSocketResultType::BinaryFrameReceived, response->ResultType);
    auto binaryResult = response->AsBinaryFrame();
    receiveData.insert(receiveData.end(), binaryResult->Data.begin(), binaryResult->Data.end());
  } while (!response->IsFinalFrame);

  // Make sure we get back the data we sent in the echo request.
  EXPECT_EQ(sendData.size(), receiveData.size());
  EXPECT_EQ(sendData, receiveData);
}

TEST_F(WebSocketTests, VariableSizeEcho)
{
  {
    WebSocket testSocket(Azure::Core::Url("http://localhost:8000/echotest"));

    testSocket.Open();
    {
      EchoRandomData<100>(testSocket);
      EchoRandomData<124>(testSocket);
      EchoRandomData<125>(testSocket);
      // The websocket protocol treats lengths of 125, 126 and > 127 specially.
      EchoRandomData<126>(testSocket);
      EchoRandomData<127>(testSocket);
      EchoRandomData<128>(testSocket);
      EchoRandomData<1020>(testSocket);
      EchoRandomData<1021>(testSocket);
      EchoRandomData<1022>(testSocket);
      EchoRandomData<1023>(testSocket);
      EchoRandomData<1024>(testSocket);
      EchoRandomData<2048>(testSocket);
      EchoRandomData<4096>(testSocket);
      EchoRandomData<8192>(testSocket);
      // The websocket protocol treats lengths of >65536 specially.
      EchoRandomData<65535>(testSocket);
      EchoRandomData<65536>(testSocket);
      EchoRandomData<131072>(testSocket);
    }
    // Close the socket gracefully.
    testSocket.Close();
  }
}

TEST_F(WebSocketTests, CloseDuringEcho)
{
  {
    WebSocket testSocket(Azure::Core::Url("ws://localhost:8000/closeduringecho"));

    testSocket.Open();

    testSocket.SendFrame("Test message", true);

    auto response = testSocket.ReceiveFrame();
    EXPECT_EQ(WebSocketResultType::PeerClosed, response->ResultType);
    auto peerClosed = response->AsPeerCloseFrame();
    EXPECT_EQ(1001, peerClosed->RemoteStatusCode);

    // Close the socket gracefully.
    testSocket.Close();
  }
}

TEST_F(WebSocketTests, ExpectThrow)
{
  {
    WebSocket testSocket(Azure::Core::Url("ws://localhost:8000/closeduringecho"));

    EXPECT_THROW(testSocket.SendFrame("Foo", true), std::runtime_error);
    std::vector<uint8_t> data{1, 2, 3, 4};
    EXPECT_THROW(testSocket.SendFrame(data, true), std::runtime_error);
    EXPECT_THROW(testSocket.ReceiveFrame(), std::runtime_error);
  }
}

std::string ToHexString(std::vector<uint8_t> const& data)
{
  std::stringstream ss;
  for (auto const& byte : data)
  {
    ss << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(byte);
  }
  return ss.str();
}

TEST_F(WebSocketTests, MultiThreadedTestOnSingleSocket)
{
  constexpr size_t threadCount = 50;
  constexpr size_t testDataLength = 150000;
  constexpr auto testDuration = 10s;

  WebSocket testSocket(Azure::Core::Url("http://localhost:8000/echotest"));

  testSocket.Open();

  // seed test data for the operations.
  std::vector<std::vector<uint8_t>> testData(testDataLength);
  std::vector<std::vector<uint8_t>> receivedData(testDataLength);
  std::atomic_size_t iterationCount(0);

  // Spin up threadCount threads and hammer the echo server for 10 seconds.
  std::vector<std::thread> threads;
  for (size_t i = 0; i < threadCount; i += 1)
  {
    threads.push_back(std::thread([&]() {
      std::chrono::time_point<std::chrono::steady_clock> startTime
          = std::chrono::steady_clock::now();
      try
      {
        do
        {
          size_t i = iterationCount++;
          std::vector<uint8_t> sendData
              = Azure::Core::Http::WebSockets::_detail::GenerateRandomBytes(100);
          {
            if (i < testData.size())
            {
              EXPECT_EQ(0, testData[i].size());
              testData[i] = sendData;
            }
          }

          testSocket.SendFrame(sendData, true);

          auto response = testSocket.ReceiveFrame();
          EXPECT_EQ(WebSocketResultType::BinaryFrameReceived, response->ResultType);
          auto binaryResult = response->AsBinaryFrame();

          // Make sure we get back the data we sent in the echo request.
          EXPECT_EQ(sendData.size(), binaryResult->Data.size());
          {
            // There is no ordering expectation on the results, so we just remember the data
            // as it comes in. We'll make sure we received everything later on.
            if (i < receivedData.size())
            {
              EXPECT_EQ(0, receivedData[i].size());
              receivedData[i] = binaryResult->Data;
            }
          }
        } while (std::chrono::steady_clock::now() - startTime < testDuration);
      }
      catch (std::exception const& ex)
      {
        GTEST_LOG_(ERROR) << "Exception: " << ex.what() << std::endl;
        EXPECT_TRUE(false);
      }
    }));
  }
  //  std::this_thread::sleep_for(10s);

  // Wait for all the threads to exit.
  for (auto& thread : threads)
  {
    thread.join();
  }

  // We no longer need to worry about synchronization since all the worker threads are done.
  GTEST_LOG_(INFO) << "Total server requests: " << iterationCount.load() << std::endl;
  GTEST_LOG_(INFO) << "Estimated " << std::dec << testData.size() << " iterations (0x" << std::hex
                   << testData.size() << ")" << std::endl;
  EXPECT_GE(testDataLength, iterationCount.load());
  // Close the socket gracefully.
  testSocket.Close();

  // Resize the test data to the number of actual iterations.
  testData.resize(iterationCount.load());
  receivedData.resize(iterationCount.load());

  // If we've processed every iteration, let's make sure that we received everything we sent.
  // If we dropped some results, then we can't check to ensure that we have received everything
  // because we can't account for everything sent.
  std::set<std::string> testDataStrings;
  std::set<std::string> receivedDataStrings;
  for (auto const& data : testData)
  {
    testDataStrings.emplace(ToHexString(data));
  }
  for (auto const& data : receivedData)
  {
    receivedDataStrings.emplace(ToHexString(data));
  }

  for (auto const& data : testDataStrings)
  {
    EXPECT_NE(receivedDataStrings.end(), receivedDataStrings.find(data));
  }
  for (auto const& data : receivedDataStrings)
  {
    EXPECT_NE(testDataStrings.end(), testDataStrings.find(data));
  }
}

// Does not work because curl rejects the wss: scheme.
class LibWebSocketIncrementProtocol {
  WebSocketOptions m_options{{"dumb-increment-protocol"}};
  WebSocket m_socket;

public:
  LibWebSocketIncrementProtocol() : m_socket{Azure::Core::Url("wss://libwebsockets.org"), m_options}
  {
  }

  void Open() { m_socket.Open(); }
  int GetNextNumber()
  {
    // Time out in 5 seconds if no activity.
    Azure::Core::Context contextWithTimeout
        = Azure::Core::Context().WithDeadline(std::chrono::system_clock::now() + 10s);
    auto work = m_socket.ReceiveFrame(contextWithTimeout);
    if (work->ResultType == WebSocketResultType::TextFrameReceived)
    {
      auto frame = work->AsTextFrame();
      return std::atoi(frame->Text.c_str());
    }
    if (work->ResultType == WebSocketResultType::BinaryFrameReceived)
    {
      auto frame = work->AsBinaryFrame();
      throw std::runtime_error("Not implemented");
    }
    else if (work->ResultType == WebSocketResultType::PeerClosed)
    {
      GTEST_LOG_(INFO) << "Remote server closed connection." << std::endl;
      throw std::runtime_error("Remote server closed connection.");
    }
    else
    {
      throw std::runtime_error("Unknown result type");
    }
  }

  void Reset() { m_socket.SendFrame("reset\n", true); }
  void RequestClose() { m_socket.SendFrame("closeme\n", true); }
  void Close() { m_socket.Close(); }
  void Close(uint16_t closeCode, std::string const& reasonText = {})
  {
    m_socket.Close(closeCode, reasonText);
  }
  void ConsumeUntilClosed()
  {
    while (m_socket.IsOpen())
    {
      auto work = m_socket.ReceiveFrame();
      if (work->ResultType == WebSocketResultType::PeerClosed)
      {
        auto peerClose = work->AsPeerCloseFrame();
        GTEST_LOG_(INFO) << "Peer closed. Remote Code: " << std::dec << peerClose->RemoteStatusCode
                         << " (0x" << std::hex << peerClose->RemoteStatusCode << ")" << std::endl;
        if (!peerClose->RemoteCloseReason.empty())
        {
          GTEST_LOG_(INFO) << " Peer Closed Data: " << peerClose->RemoteCloseReason;
        }
        GTEST_LOG_(INFO) << std::endl;
        return;
      }
      else if (work->ResultType == WebSocketResultType::TextFrameReceived)
      {
        auto frame = work->AsTextFrame();
        GTEST_LOG_(INFO) << "Ignoring " << frame->Text << std::endl;
      }
    }
  }
};

class LibWebSocketStatus {

public:
  std::string GetLWSStatus()
  {
    WebSocketOptions options;

    options.ServiceName = "websockettest";
    // Send 3 protocols to LWS.
    options.Protocols.push_back("brownCow");
    options.Protocols.push_back("lws-status");
    options.Protocols.push_back("flibbityflobbidy");
    WebSocket serverSocket(Azure::Core::Url("wss://libwebsockets.org"), options);
    serverSocket.Open();

    // The server should have chosen the lws-status protocol since it doesn't understand the other
    // protocols.
    EXPECT_EQ("lws-status", serverSocket.GetChosenProtocol());
    std::string returnValue;
    std::shared_ptr<WebSocketResult> lwsStatus;
    do
    {

      lwsStatus = serverSocket.ReceiveFrame();
      EXPECT_EQ(WebSocketResultType::TextFrameReceived, lwsStatus->ResultType);
      if (lwsStatus->ResultType == WebSocketResultType::TextFrameReceived)
      {
        auto textFrame = lwsStatus->AsTextFrame();
        returnValue.insert(returnValue.end(), textFrame->Text.begin(), textFrame->Text.end());
      }
    } while (!lwsStatus->IsFinalFrame);
    serverSocket.Close();
    return returnValue;
  }
};

TEST_F(WebSocketTests, LibWebSocketOrgLwsStatus)
{
  {
    LibWebSocketStatus lwsStatus;
    auto serverStatus = lwsStatus.GetLWSStatus();
    GTEST_LOG_(INFO) << "Server status: " << serverStatus << std::endl;

    Azure::Core::Json::_internal::json status;
    EXPECT_NO_THROW(status = Azure::Core::Json::_internal::json::parse(serverStatus));
    EXPECT_TRUE(status["conns"].is_array());
    auto& connections = status["conns"].get_ref<std::vector<Azure::Core::Json::_internal::json>&>();
    bool foundOurConnection = false;

    // Scan through the list of connections to find a connection from the websockettest.
    for (auto& connection : connections)
    {
      EXPECT_TRUE(connection["ua"].is_string());
      auto userAgent = connection["ua"].get<std::string>();
      if (userAgent.find("websockettest") != std::string::npos)
      {
        foundOurConnection = true;
        break;
      }
    }
    EXPECT_TRUE(foundOurConnection);
  }
}
TEST_F(WebSocketTests, LibWebSocketOrgIncrement)
{
  {
    LibWebSocketIncrementProtocol incrementProtocol;
    incrementProtocol.Open();

    // Note that we cannot practically validate the numbers received from the service because
    // they may be in flight at the time the "Reset" call is made.
    for (auto i = 0; i < 100; i += 1)
    {
      if (i % 5 == 0)
      {
        GTEST_LOG_(INFO) << "Reset" << std::endl;
        incrementProtocol.Reset();
      }
      int number = incrementProtocol.GetNextNumber();
      GTEST_LOG_(INFO) << "Got next number " << number << std::endl;
    }
    incrementProtocol.RequestClose();
    incrementProtocol.ConsumeUntilClosed();
  }
}
#if defined(BUILD_CURL_HTTP_TRANSPORT_ADAPTER)
TEST_F(WebSocketTests, CurlTransportCoverage)
{
  {

    Azure::Core::Http::CurlTransportOptions transportOptions;
    transportOptions.HttpKeepAlive = false;
    auto transport
        = std::make_shared<Azure::Core::Http::WebSockets::CurlWebSocketTransport>(transportOptions);

    EXPECT_THROW(transport->CloseSocket(1001, {}, {}), std::runtime_error);
    EXPECT_THROW(transport->GetCloseSocketInformation({}), std::runtime_error);
    EXPECT_THROW(
        transport->SendFrame(WebSocketTransport::WebSocketFrameType::FrameTypeBinary, {}, {}),
        std::runtime_error);
    WebSocketTransport::WebSocketFrameType ft;
    EXPECT_THROW(transport->ReceiveFrame(ft, {}), std::runtime_error);
  }
}

#endif