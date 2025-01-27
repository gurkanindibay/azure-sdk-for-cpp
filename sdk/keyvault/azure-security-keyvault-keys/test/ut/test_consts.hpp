// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

/**
 * @file
 * @brief Test constants
 *
 */

#include <azure/core/internal/environment.hpp>
#include <string>

// cspell:disable
namespace Azure { namespace Security { namespace KeyVault { namespace Keys { namespace Test {

  const std::string AttestationServiceUrl()
  {
    // default to wus
    std::string shortLocation
        = Azure::Core::_internal::Environment::GetVariable("LOCATION_SHORT_NAME");
    if (shortLocation.length() == 0)
    {
      shortLocation = "wus";
    }

    std::string const endpoint
        = "https://shared" + shortLocation + "." + shortLocation + ".attest.azure.net";

    return endpoint;
  }

  const std::string RawBackupKey(
      "JkF6dXJlS2V5VmF1bHRLZXlCYWNrdXBWMS5taWNyb3NvZnQuY29tZXlKcmFXUWlPaUkwTXpnMVlqQTNZaTFrTlRRM0xU"
      "UXlaVFV0WVdVNVpTMDJNVEJrWXpNNVpHWmhaamdpTENKaGJHY2lPaUpTVTBFdFQwRkZVQzB5TlRZaUxDSmxibU1pT2lK"
      "Qk1qVTJRMEpETFVoVE5URXlJbjAuYUFjZGVkTGVwWkQ0SGR0bTlvTTA2R0tGOENxbmNxYWVGZThRc09oRTFSNEh2aC1M"
      "ZFphUXhvZ2s1czU3aTk1XzBGbkVxZnFmdjA4N0VHNWVReGhfTjkxMjctODVIWURoc3RSY2ZUSDVwVUJaNTJfSjlLbjdm"
      "WEU2WUU3VHQ3bno4OElndVkzeTZsVE5pVG9YbHU2enhNZ0dVLTVMLW4tbGRHUHROb05idk40MHVWVG1hTzFVZFdEd3I5"
      "dnZRQzZQNmRBMzhPQnEwRjJHeEloRy1JN0NvZUhwU2hHM2QxVjlzOXJVSVljQ2lGMGhXdG1FUk5IOGx6aU9RaFdhQUo4"
      "Y3ZOY2dsVl9QdmY2dVBLaVJXNjhINTJFZnR1RHZvclJWekY2OTVoY2hkQi1jYU9ZQlEyazJpbHRaWTZYYVMwYS16Ml9r"
      "RS0wdFpVSVp3QllGTTROcFNRLkdXNUhHdTNaNU5uSGtvMUR4TFBRUkEuRTlCRklFenYyQ3pWNXFpdWtTNEhFTXpMN2NH"
      "NENkMURXa1BTTkt2QWpaOFh0MzRELUdham4zM2daZ2tKS0FsYnlQQWRlbXFKblBQNmdpSWNJUEZqVkIyZW9nX3ZGOUNy"
      "MUdMTEhMaUJCMGFQcVg4WWRuQlRTREc2TDRoUkc5LWFnY3FUaU9MNkVtSjYyN1hIRi1kZ3p4cXNsdVdBS2NIa19Yd2FV"
      "Q1pEcVAtVjJRV2ZBb2pmNkFsZmxmRkczRklldGVPd2hvZWNWSlJFQTlJcXk5TUdHU21LcVRFWlJRR3dUUDNkRnRtZEh5"
      "bzZYb2xvUG1sVUxYU0lieTB0R3laUHVZc0ZSWHhKZGxaR0IyUXJJMmZnUDlvNTNkMmkwV0tDYU01dkdLMlFJcERhWDdh"
      "Q0tlN1VBVTRxVERweDU5VnJOVmlna3pkRl9tX0tXTERiQ2otd2thVmlPdnNMZW9RTVVaZ1JaejRWdzR4M0ZVX1ozdnRx"
      "eTdWMXVMdTRKemZZNzZ2LWdqTnhEbGpBb3V4TkRscGt0WDB6Rks2NkU4VmZsSnNVZEhnd3pmUG5RRTVwUWg5VXAtd0pa"
      "NmRVRHV2cEhvZzMzeXVJbGk3cllNYWVTQW9GQ1lZbDdiaExPSTJVb1BHdmppS1M1NlNfWmVEMWd1UGhiWjJSWlpfY2lv"
      "c18tbkZvTFdfQTQ4RlU5U0FnWUg1LS1ZTVpnNlFKQkllLUFPOXdFMXd1REV5UHA3VWtjOUt2MWwwQ05PWHZwZnZuXy1Z"
      "Nkk0Nm9PcE82LUp5VkJIQVdQMWQzMGdaWnN3T0pSemRIY2d0TDZLNVZzWWVHd05EVklKMHdqMG5SMVlFOWQ4cHhZVzJS"
      "X1hBVkNkeTZlUXlMSHJiRTRITVM1eTFxeHRNNVhlVjNTOVphb0w2a2tIOWhjYTdONkl3Skpfa3NkaWc0X3Vic3Myckxj"
      "NnZMWGE5cGxGWDNOSk9vdjNGUUgwV1pjSlVyRWtkSVlqMlMyQlUtampMNUNyUnZPb3FrLVpzUEp3aHRDd1ZGN3FQRC1w"
      "MEx0ZHJnMWVBRXhsTFY3bGxzbUJFaFMwdWFpWHR3MVN3UGRicTlENk1VQ3VHNWZYc1NpWlU3S0sxUDhJbVFiVTlwVEFf"
      "c1FJVTVuVFdZNENTS0xxbkNPU21mcTFYOEhnMVNxTHBfWXQ0Zy1MSmc0bHRTS1VTbGd2YXU2M25YM3Q4a3BXc3FJbjBK"
      "eUVJYTdCRC1zUTU1Q0VCdmd4TnZLbTN1ZlNGdmtMWEttejRBbEpHVjlsOVBxa2drR0RIbkVLcFAydmhiRkRvMjN2WW1z"
      "X3ZwZlRGYlJvcmE2TFhZMm1nV1VsZEg1Q0FJejBJblk3X2pfdVlyZmlvZ3pmTTJhOEJfQVpMM3J3d1JudzdaZThlTDI5"
      "VHR1dURhOThaVENDb1p5RzBaVmhnS1hobUxtRlF3MjdrQVVjVG1mWUhKalN5NGZpLU54cXlVdmF6QnpXeWVERG12WFM2"
      "U2VEMHQ2djFWVUFYTkxHOV94VEVfcWZBdHAxb3lfUGNUbHlkei1UR3REc2ZUeDFHS3VNcWVQRjhCVnhZeFFDemRmZnNn"
      "V2MtQUgxRmZoTmJkUHlNcXQ3MlU4WVd0UE1yb2R1bTFWWWc2NGtjNnlQWURlTUFCV2I0b3hhcEVXM25oZmhDWXVad2Zu"
      "S2RWS2tJWmp4RWY2MXZXT2VzTlBJeTZkOERCLXE2YjNQRmNzRjFRTlJEaFJNbXoyTFBzQlgtbVBna3N3WUpYOU9OSGll"
      "dU5wLUdVR2VxNVBfUmtJcG56MFh0el8wZEctVkJjZEZQYjBpNFN2WWh2dEVmejM1dVRPNFVYcWlrbEJPeC1laFJ2M1E2"
      "UXZmRjJMNUQ5ci1nTlBUcWsycDNMcHg1WXpjYU5DcHdsOEdvc0ZSYzVaVlZPZGtXZzNhNWZDRUZ2TlRZQk5FRnZwR2dk"
      "eUlMelphOFY4UmoweUhCR2FLd25ham1PVXZpanpCcl82NjFmeTl4R2o2YmVMNURuNVJwT1FQb0xpWFNRMmxLSFBlU1It"
      "TlR3ZUFRWm9Qa183dFkyMllza0YwbXFXUmdtVGR5UmZQRHl5alAtQ3N6MDlxTlJHR3VDSV81QzBsZ0poY2JNQzh2MjJL"
      "QVV2OEhDTVlzYXRabmZKcE9haldKSXpqT01oclhnY1ZYVlFlZU5ndnFVaDhrU1dIZHMzRURiaUV2STVuMnZfd3RhNWFa"
      "cXoxSDc1WVZTLVdUazVpd3ZEbXhydmhGaHlQM1hxRlgwMzh5dXl4dUo3a3BfVTBGMy1BeDhvNnd1UHBqNXFodUx5UlRl"
      "dzdHYl83bWJ6ZmJQUG9ObHpLUUxwNEZYaE00dGdHVHlmMkZwVWQ1N2ZHTE40OWxiWngyS2ZzeVdzQ09DQTNlWUhfeDZU"
      "TFB2VmNXUUU5T2cwMFdNc0FLeXZLd2ZDa1JjNFU2ZzV0N1luTDVrRDJ6VkhMLUxXZHNsaGMxTEZiZFJxckJybHJKd19L"
      "b0VGQmxPMHY4ZW4xTkdpSzVDWXRnRjJScXdlcWZRMGdmdnNqQkZfX1IxdGJadV8zUllYLWx2Vmk3SGVKeVIwMU1zbV9u"
      "SE13T2tNRzkwU3pPbm9YODBWamNyZlZyc1BWMFVQSTliR3RrZEdyWDB2WFJQZ1oyeE5IMnZQeVZ4YVhnQ1IzUEp5cVRr"
      "QUtBa19VS1E4ZzJ3VDNtdHNPdVc0VTNPYndNQlpHTXpnbnEyY28zRTlUQ0FVTnRwakhfS2stUE54UFdLcDQ2bC05Ylp6"
      "MmtZYjZGVTMyd1p3QWM0d1Zyc193T2FaSlJnSUVxYWZRVXYzWTdWczg4YmNyS3Z6VmJCVWNQbENlZ0Y3OGdNX3JiTGRT"
      "dWp3cy05WHlQdzNjX2tvWHh2LXFxZVF0Ri1yMzdhOV9laGhBT2dya3Z0MmN4VExuUm9MMHpoNjFIREU1QUZyUGdFUnRV"
      "LU5xOTdVZm1HcjNwNEJ2Y29pYmFweEVIVjlTLUkxMUZhaDdabHczaVA4dGs2WmtiRUZ0cnh2T0NiRUZUVnM3ZW56NWs4"
      "NTRWMDVJV290dTdWeHRxWkJMeVl0U1RZekpWNDJEOUFvZkhxOXVsUk5ZbEplRThtNFJRMmV2SGRkTW81SWE4c3BINW5l"
      "ODQwYXFXeGtlU2FKLUFkSHR6ZHZ0WnFVeFNfNWE1Z2VXd05fZDBXZ3dxRGw1MmRUbUI3cXN5Z21McjRPdklRdk1nRGZS"
      "Qi1wdFA2b0NmUXRFelVJdEJ3R1pkYjhJbjZQYnVPTDM5OXAyb2lFU0FDQXd6TU1FRXd5VnFXb3J1SG5zc2VfbXlsdEhu"
      "NjZ0VlFCVGpiUUVHWmZ0Z2NLOE1tNmpHLUlFdlFZV2g4OEpYV0xUbzZOSVpvY2g3ZDZLUU9qUkFUbkZENm5oUXlQak1S"
      "cFBKSVhQUmY4N2J6Tmw3RXNJQ0ttenVYLUw3MXl3UGNpVWFLR2tXNnNSVV82VnpqYjd0QUxHVmoyZ05YWm1RalFqV080"
      "ZWRnSEFjS0NYOW1oYzZabkxpR0IwVlgtYlc1UEdRM01Id2VXeFZzTVo3QXRzSUd1dFV1cjE4ZjJ5b3lPQzNFSWF4dUdJ"
      "NGltMjlORFREbTRPZXA3X3dhZGFqakFTX2J3UUtQQ3FmWUF5cUN4bDdNQmNUdDNzLWMyRXloZTVBa05ES3BRRVNUMkF4"
      "WWEwMG9UWDU3bVRzSjB4cWNOVGpUSjZvSV92Q3V1OEkwTFFWTXVWWkpfd1BhaGtoSW1jSG5uODRVMDF3SGR3bzZuU0hC"
      "cEgwdUFNWmxJUUZ3UF9VOVBUNEN5RXVJdHNCRGhncmxkdmR3NG5ST2ZsU3RQeElBdlFZTVd3VHFIbHdxalZQYXdDSnYw"
      "SUZGSzcyb0ptRTNfaHJYNGl4elo3cjg2aHZnR3RTRlRYVFd0aFpLX3JDQjRra1ZxN3ZlM2tyVW02YzFsNzk4aXNZZUpZ"
      "X0dpRGw0RWJXVTVhMllQWjNPaG5WUjdCRnVBY3pkYkoxUDJ5Qmdjek5mbHEtTDhfcWE3Y0FHWmVuN2VEWmpTUENETkRk"
      "c1BIeFNBMjN5aHlrOWJ6bVllUTZhNkRNRHl0dno5T2d4QjBpYjhpQ1ZtTGg5b1NpVHFpODJEeEpDQTZKVWhmZ0VSSXJM"
      "MTlsdlRQX1BJZDRDRlFNSkl5Y042VUs3ZlhfaTBKbWFzdWNaT1pnSDViNnpKTG43YVVoS0ZfeUZ0Z0Q1ZEJBVUdnZm1r"
      "SzAxMXNnLXZDOTl6NjJNZ2ZmRGNjcEVteU9PX1VmanFMcnNlRm1PRFJyNVNvZC1iRk03M3ZJeXpfN1FjbG04SW9fWlJP"
      "eGlPZDQ0ZDROeGN5ZThWR3hyV3BXeU1EQ01uSnk1SmN6Uk5PV3FhVUwxRk55TmFQRHVic0plajM3aEJ5YmtJdzRuV3dT"
      "cDRjdWV3NTRUb01zMkZFZUdLYUxpS1dEdklJUnpFbG5iYjVfNEd6OE5IVGxaUUY4djZWMHpxd3duQnB4VE5IeExsX01r"
      "NVNYY1k5aFNMOWhQWHlONVBja0F3NXBNb21ydDlLRlJNLXJXa0JuTGtxR1B5Q3hZaGhQZFkzd0NwZVQ3dDVZa251UFJw"
      "WTA1RWhfQkVDV05rVGFKSnhLbi1NalFLLTViS2dCcURhRkkwX00zOUNOcVBCeHhDcVoxdVFCQnVwRG92ZW51ZXdKU0Fv"
      "NFFIbzl2cVY0OUQwODIwN2lsUThUSkNwTzQ0UmRfNWlPa29kUnJKNkpLU2pQMml0YjM3NzZWUDI3RVZYbEllWWZYbURh"
      "a2taSEJyZjBGY1Y2ZGk3d29CUWVacWdJVE9hWmNSbVpGSUNHdGpqdVJPWjFjb1Y2M1hvYUF4cjdaSV9QclpaOTk3MDFY"
      "V3hFQkJjWFpJbWotcDM4VU13aGFwME1tMFZmaUpHdlF6enZxTW1pT3FBMF9fZjIwRkEzQmQ2a0xiZHc5MmltbV9wVGln"
      "eFY0Vm1WTFd5Vzl2akN3bVZNeWdQOG54ejNXdS02akM4ZUZfbmJ2WTBZMExCa3BzV0FmMWExSmRfNGc5eDJBSUtMNGt2"
      "dmlOSzczR2xJMVkyaUdNTmdYVlFBQXlhZ3RRRFktYjU3U1Bjbzl5NVNWMVgycnRPcGNlcHloa1FOUUtob1YyR0RNRGZM"
      "NU1WbGRtN2tObk9jVjU1YnJ3MkMxTk5IT1IxM0JFcWVuRkNybFF2N3pSajdVcEhZTlFGZDh4ZGRqc29vYjRzRmFpM2w0"
      "NlNmSUpDMzhDMDNRSncweDBDckttX1Q4Q0h5aWx1TV9jUzd1UGhFUEtjNk56Z1hoVzBTSGpzLTZpRHQ2UEh0X3JqdDVs"
      "YkZxWUd2aU5fUVZ6Yy1RYzRHWkhWOWtCdVNHekotS0hRNHNVV3pFX0dDWXpKUy1uYjlrRE1FY0tDUkQ3NFFuamhiZzN1"
      "OEs4dUJEUUJwMnlGQ1lacmtzcXY3RUVGNnRJS1FHdGhfbmhBRVpqaE4tNGFhb0tUTG50U1NoN3UyWVRPUU93bE9FSGdn"
      "aDFoLTctVGdRa0FGVS1jNURuOHpSdFhVOU90OFc4cDdXbG5xSG5VZjU0R0J3aHJPM1VPT2ZmNnlsWnhFQWQ0MFM0YUE2"
      "U1BkRFlDQzRFa3FLdHktNFRWM3lQNS03VGZrM25KRXYyRGp6UEVKeU00azZ1NE5kYW55UnhlRzFBd2YzVTdfanZTaEE2"
      "ZEhURGJfeDduYWlPVEJmd3F6VWJVLXY0cUtWV0dzbEZQNEFWeHFsakhRYmJUNTBCLUw1SVJuTmJIRlhOc3JKVG1RTFBm"
      "N01Jd3ZoNlVUQ3p6TVBxdklrY2E4N0FqNGlNbVp2cXlQTU9SOTNObVRmbjVYamdGZk83b0tXWDdoc0xqd2M0dGlqc1Q2"
      "WHhoNTVVQkFNekJ1aXVrVnc5aUE1YXFBa1pSbGVsWC1EMUdkU2c5OXNoYmZqZ0MzQm44ejZRRkI3Mjk5eFl1UmJ5OTBH"
      "dDhlTGxvOWFKRGtDS09QUjVaeEl6N296TW5ZVjdaT2ZWUmxleUpaVzF4ck82dTA1NkFnRnY0VFI4VHFCTnI5cE40OW5D"
      "THNMV0xDT0hfbWVQNmszYU9UWmd5MkowM1BHMXBYRUtZSUVBLTNCQUZGOFctRGYyTnVWVHFQeGVZejdIWFhrbk5KRWhl"
      "WFI1R2hMUmFDMzN5ZGVvbHExOE9mM09Xd2xFSG01aEhzQkhuMXIzUWQ5WkIwLXp5b1ZRMWNCNjBFSFQ3eXMzS1BsOUo1"
      "cE9Vby16SEN4YkFmWElnRTRsNGJreWtoTDhOdkpaZGhyeWpYMWYzUEdINkgyR0dUbmM0am1zY3pERDNISnBuRzJBaTFf"
      "UVdGY1BwR2I1Y21sb3BDazN3bFJObC0zT1ZXWVljZTZnbXM2c0d1dGxoN2NzcVNIdXVRTkVKbUV2aFg4VmllQnpqYzY3"
      "YXcwQThZVUFPU2RiMFZVV2s4RjNiZHFBenMxYW1uaGNEQ3h1M3pQSFJzYW5yblJjM1BrQjdMd2hiZzdsVGllQ1plbEJO"
      "MGhCYTIyNmJvdGRJRmUyeDdJdWJjdVpUUERBYmc2M1YwOUR3VUYwU0hLQks0Sm9JaGpUTno5TzRzTE1ocjdCUnBLYzhT"
      "VlNVQjF4OHMwbEFxWXA3eXByOTJ1TThnNGxRaWFLMkZMbUEtX1Q4SE9aSHVLQmI0V2plWFZoN0lqZUJldWh6Q2NJdkZ0"
      "c2pQNWVMZFp4WHZVcGkyMFpaS0NfMWtxeXRGbUQ0ZmZJNW9pM25pMDVNZGZPczRXa0FVdDctdjNlbWQ2VGNLVnI0Rk1t"
      "Z19fMW5WdDJIRXg2bUplbmJkaTQ5ajROdUZ1MXFCMjRRUUxaX1FtZ2tCM25OQ0VNRkptLTAzNEY5MzFiR2R1cTBTeGJ2"
      "dXZFT1hUek1hY3pqMm9DTUNjUjlGTEVNTW0yNHhwcXp3Tm9SRktBaHNvVXF5VlRoX0JfVnZlQno0U1hDU1pwVHZsdWxY"
      "TExoTmxWLXI2LUlfc2RGQ203VzJJdG9tS2FZT1JkVkFMOV9YcDB5b0ZVdmZEQUdwOG5hOExRZzFVZl9tc3RvdFBWTHBB"
      "X2pCNjV6V3ZfN3BRcnJ0Qm1VSUl2cFVFX0JpX1RBejl4Rlp2U0ktMktsWWxhcm1NQzdpR1VFNDFLRUdkc05IMzlYTFhi"
      "NFliTHNBTnRkMVc2MmtDRVdQYmhvMWRMV2JBcWxQbmVFSGJKNkNyYUFObDRyazJKTERpZDVJZ2U2QnhCbVY2NEVKeURw"
      "UVdnVS0wcEhYWGZUMUhXWWpmLWg3a2FadmhPUDRtMXpsYVg2TnJaaGN5a0JMX28wSV84S1hOdEZUS2tNdXI4TUh5TmdD"
      "dDNoSkhjR3E1d3dUNE8zbTF1RGo4VkxDdWd0MmF1aklPTkJjR0FaalB1Ty0zNmlqcFBHT1p0QlBsRHlCeVpsRTc0ZW53"
      "VmxMY29LNDV0ZFAxUFFPRHdmcDdackFkRHFiSTBhb2JobGpqVVo5WWhYb0pGUHV3cWVfa0UzMTRQWFZpMWJtUGpRQjRK"
      "YzFraVlFRlpBNEliM1diSVM3djZCcnR5WXZGTlpzemhGbmZfdWhyS3YwTHUtVnYtN0g0SWw5UHBMN0VOQXk4bEg3cWFl"
      "ODZFdHBteGJzTkFMVzZkemNHdFJkdUFYd3RYd201YjdOTkVyRU5YaFhSWWZ4WWlrSi1GRGZOUW53aE1nTHRHMGMtcUJ4"
      "akpyVVVXVGhjSE5BM09nUFBQWUpQQy1KSnFsenFONDQ5UU5BSWZIQnU3UkpfLTRMY3ZTLUVocVMyNzBvVXF2R0pEZzdv"
      "bTJ5UVdBd2p0WFM4YkZhU3o4aGNFdzNQeF91Q3htclRpRzdfdDIwblM1QnJMc2xkT0xjRWNGRUpzb1J4MzZLQloybXRF"
      "Tk9Md0EwTU16QkdqejNTM0FvQnhfeVVjR283eTlUbUw3RzVwTlJsMjdBREpTeExONjRRa19aeTlkS3h5S1JGdUZmNWl4"
      "aUFWdzBtc2FoX2xELUZ4OXQtLXRXSzlDTGxpRHVDOXI1QTdrZ0EtMWp0UEQzcFB1Um90TXUtcVJ4U0g1elAweTNjQm9f"
      "d20xalJfNFRRV3F1MEZzTW9hSXh3R2xaVWp0bW5yM1ZyV1FSSm1qclhOaGlycW9ERWVFOUFVYnFFcWNlMFNUdjhibG92"
      "T2pHQ1BHRlJoLVdmMHgzQTJhRDVraHdkTE9EaTN5QU5GMldKd04wMU50a2trY1cyei1OdmZSLVV6ZzU5WU1zbS1TeU5w"
      "S3Rod2Z3ck15U2QzNEV4a2tQZUJWRHRBTHp2T3hodTdZMDFPX2ZDcUg0QVQwWmw2bnVnZTBoT0k3cldPVHhDVElqZFdK"
      "bWxDdVZXclJBOWJzTFB1WVBxdzBxWnN1RFVqTmFrSHQ4T2pQZmVQMXdudFNnLXdsSENPemZpNDBFVlY4dm1MVkNWUWpC"
      "SDA2LVExV3o5SVRjRDNKU1VrWGx5ZEhTdHFyT2hoR3NBaENyQnlNNXE5VExwMnM0cVZsUkk1ZjhNS3B6dzNXMDh1bVhE"
      "M05sMDJHTkxYbWhYdER3dUdkNi1CR3VhNjMxNEFNQ3U1ZjBXNUxFNXhSVG9uZzd1SnJVdDJPeUUwbjFTWkY5S19XdGpv"
      "b1dCUGk3X2ZCZnZINWRaam9wczE5M2poTkItVVlHN0lsZXlBY0NkRFhFU2FraG9sYTJ1WlNBMVB2YjhnZVpwWHhFZEVn"
      "cXhoZG9Ddmw5X0ZqNTFKel93SWU0WFkwWXlGQ2dvanBLdlQyMVUtSEhZYXdGVi00VXJFZElBcTZleklzYUJENHJTMk5u"
      "SzVJNEdqS29fenNBbEtDbmhvVkdKMHhSdXB3NXVNVDNHckVPYk1PbW10OXdXcHNtbHhwTktqMUU5RW1iQ0tTOWl6NGUw"
      "X3p3ODA3SWRpRjVLX2ZCNDZ5R0wxcnlMS3dWY21MRTBoV0tjMFBCODVieWtqUHVNR3RwYkVJc0RWRlE1RjFibklDb0Rk"
      "bnJGaTluM1RfcEZRVG1Td1JxUXg1eG5lQlhlSWF0TGtMVUpxZTdnM0ViRWJoWXlmZ1VsWTNLNmR0S2JNWmVlTFR1a0JL"
      "dkVFMWpWRkI2Mm9nNk9oTGxVVHRMN2FkdDNOaFNFdjd2YXZVMHhVYmhMUHJNTEItZXhwN2E3Vk9naXJMcW5KT0U0UHNV"
      "b2stSFJDOGRqYXBfRExLQnR0YmpQRW5nZ2lxRFpxV00tbkZ2OVVKcTN6YmUxY2FzUGw0R2FsZFZ5WllRcTh3Ym1zZWVv"
      "T0UyeHFLOThmYWJJaTg1VHh5V1lPdnB3eV9OZFRFVE5nMDBmRXhMeHVfU1pwUXViX211d2dfc3BqbnZyNzAyaFAteVFf"
      "M0MtNURLMVdjOV84SmYxbXhKVy1xTFU4V0tUQ1N5aUpyTEY3YnQyNUZDdTRZYzh1aDh5NlhEUktzX2FoT2FEakVnalA2"
      "NkZYZnFwZW9Hd0dmWEstSXlpRzJnM0s4TWhZcU0wMGVaTUhIZnVJdVNueUZBNTdOMFVvczItSm9iV3E5UVJRRURWVDg3"
      "aG80bXFvcHowVTBnTF81MU1RUFhnWm5EWmNUUGhyMEg2SVlRRURBdU1GZzl0Wk5XMElid1R2SWZ3ME9SVmxfc3lkVjdX"
      "QWtNaG5NSHJXVkJRdTNKZlU3RUIzdFEwME5hSWVoM0c0c2JGdVA5MHRnUkF5WXlFM3J4UC02NGwyU1ZyYVA3bF9lbTNB"
      "UEhDb0prSWRxc1ZXdlNzb08tMHlPcXdRN0k0QTl3T0h3bFdmaFVVSXR1Z29jakxCLVZZRjFYbmZWdkdmaUt6S3NsbDJ2"
      "QlFvZmNSTTd6R1FCUDVsaG9uN3VuekFkNU9aZWhPekxYVFY0LWItNzdocDZsWEhtaHhTUTdZXzByWHRlaTRLQzZKYk9u"
      "LXZpRXY4UDlobUZVZlNkSDJzZUhBa0dQUHhqQ3M4QlF4Zmkzc0NqX01lUjNHSHh4cGtIOUY5QndFSXQ5R0dQWndkY3pX"
      "SkFudG5pSDFPTWE4c3hicWttWEdBeFBSVjdwbGhaS2JxZmZMUVQyY0FuQncwM1ZXdVhJbV9wNVpYOXFxQmRLS0hPNXl5"
      "Nmtzb3g2QkZuanV4QnZUUkRibzNIVEstb3BUREkyTHgwcnFaVWpNTFJsVk4xRlExSGFvVlN4WU9nQktNUVBVRWxTUlln"
      "MEpUeXAzSkdqUUduSTlXRGVmRXBWS0Y3Nll1eGo4cWJwUTJQSmVvNGsxaXp4XzJOZG5zbWRTWWx2Z2lkaWVPS1FsR3BQ"
      "bG1MNy1wV1pVbllCUDVQUXNWcVdha2tTZzJxRDQyYmo5YjZlN29rTkVfemRFeEp5R0t5cmxYdHBkZ0NYMXliaXN5TVN0"
      "NHU4cVlEX1JENTlWQXIxZlhiNEpWd0RFZkxaNENQbzVodzZ1YThVdWxocGFISEEyTUZhZDVmTkJ3Wk9HLWxMMDYxaEE2"
      "OE1Uc3VQS2xTZGtwSkxMZlY4eWl5eW4zNE1HRGpwRUl5cUNsckFsYVRyWW1la01vZHd1a1JxaGNYNC10YW5hWHl1MWJp"
      "b2RHbnpGeTBHNkh3al80SFNfdFJxWkpzQkhCbkE0RWxJc1lMenltcF82QjZBVEZnVmpHWWlsckRuOEhrVFQxbGxKYTRz"
      "MExaUHZwZDZyLXE1SFkzS2FneVB2ZzFhbDFuXzE4OGc4a0h4eENKN21FNDhjVXB4aUNYWlZkRmxZSENvQ080VFZwV3A2"
      "S1drVE83NGtlOEo4MmhsTHpjUjhNWmN6d2hiRGw4UHdXQXBDNHFXV2hoX0REN09GMkY3bERWMGRld2R1TjZRcm8tbVNy"
      "MjJhdWFmVlpVNl85OENySWFmTzdzdFVLXzhweXVPenFGQjU5MHI0ZFd5Mi1wYVBuT3dweGttRjE1STFCV0NiOEFCdE5J"
      "SWpxaGhheThzcjRObFJnUWk0S2JVT2l2QnhzdDJpeXktVFl6Y1dGVUg5U3hEaDN4dFRQTElfOV9aWXRDaDAycWpXbzY1"
      "MGdqQW5rOFZVbXhQb1NBX19zREJ1TGliLTdfRlh4N0xNSWZHTG1MNnFVVDhYNnFBeHNzMnVSLXBXWVNnR3FsMkxhYUMy"
      "eFNCdUM4aDZ6Nld1VktyRW8zQUxqVlU0SkJCUk03WlZoSGYtaGtPU1FQOVI1cXliZDEtOGFQemY1NW1iSmNQd2RuY2Ru"
      "WExmM2RHUHkyWGwyUkJJMTN4VzBMQlFscmV0bTFzQzhyU3VjdmhVU0szWGRBbFJqZHNfdXFmSHRCeTE5YlhrOWRHYWNZ"
      "N2VXZ0NMRHdpV1dFcW5jWVViTHdwR1pMVXhTS1kySGJzYzg5bDVPNGhsQUhXQk9XUnBWckoyTm9pRlZ3eEJoRlQyOE9N"
      "WV9wREpkR2c3SUFlMmwwR1JfY0huaHk0eTVzRVNERTUwZEN1blh1TXJONzNIZDM1MXM3am1MMlFWOGhSbG9oNldmbktl"
      "a1pPRnlTLWNCYk1OUkI2dFVGQ1lRZnhKdXpVMDdMNVdTb0MwT09FZUtfMkw3SjJ6T0dVZW81UkZybmFSMk5tZTU0a3FQ"
      "SmhGUmJGRHZPLXZhLVVPZUxoN2xBa3FNMHljZU8tUkkxcGtSdGRlX1UtTlFXVkVnTnhyVFBJLXlPeVBqZ2VBalgxMHRn"
      "LlV6aC1EYjJUV1VRVGpwVmlYWUQtV3ZfYVVRc0NnVm5ndS1jNEpybFg1MWs");

  const std::string Base64UrlEncodedGeneratedQuote(
      "AQAAAAIAAAD4EQAAAAAAAAMAAgAAAAAABwAMAJOacjP3nEyplAoNs5V_BgeXn7xW1Ia-pyWHTxihICruAAAAABERAwX_"
      "gAYAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAcAAAAAAAAABwAAAAAAAADs5WaWmpFHEvFe"
      "c2zr_"
      "jqgbOwooadc9HAc8icNoqk1EgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYbjwXvtOOyWfOxu6a4mhoWeEv"
      "Us7Fy0AuiKjbHEx0tUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
      "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
      "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAdFmbTnUQ-"
      "DRiboBGNhiOjTu99HJv4ZfzCppBPlaaigAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEQQAAA2OZ5rbQ-"
      "rIV6LtkxBysw8RnstOE_XhdU_"
      "L0TT77GJXOkXENj5XZPpa6rACwvNGqCDagWcCXddRfjb6z4a77333CtQDi3aSvfQ0KfwpsMh5Naon9_"
      "U8x3aWBLL2iLmDTHhl9Vpp7F-sWUNxrM_7tjw4_WC7Go63i31a0PatYmdnRERAwX_"
      "gAYAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABUAAAAAAAAABwAAAAAAAACuEjy_"
      "qWwmhWDf1d_-SFTORD3k4PpR0oEYTJQo16NA-"
      "wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAjE9XddeWUD6WE393xoqCmgBWrI3tcBQLCBsJRJDFe_"
      "8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
      "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAcAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
      "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAABcLBx313qfyVbSqE2AJFfegbbW0fcu3PQ_"
      "zNlq31p7oAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAODczXIYBOIupR5tEvWZEL1TwGVDK_"
      "eqqYVgcCFU2VWu5P83Hyc_nbrZ9yZkiMJ_"
      "Lek8IbVhFYxGMqIWG9rbMzwgAAABAgMEBQYHCAkKCwwNDg8QERITFBUWFxgZGhscHR4fBQDcDQAALS0tLS1CRUdJTiBD"
      "RVJUSUZJQ0FURS0tLS0tCk1JSUVqakNDQkRTZ0F3SUJBZ0lWQUxrL0sxRXhhc2w5bEpPUVNzeWVYS0dETERFUE1Bb0dD"
      "Q3FHU000OUJBTUMKTUhFeEl6QWhCZ05WQkFNTUdrbHVkR1ZzSUZOSFdDQlFRMHNnVUhKdlkyVnpjMjl5SUVOQk1Sb3dH"
      "QVlEVlFRSwpEQkZKYm5SbGJDQkRiM0p3YjNKaGRHbHZiakVVTUJJR0ExVUVCd3dMVTJGdWRHRWdRMnhoY21FeEN6QUpC"
      "Z05WCkJBZ01Ba05CTVFzd0NRWURWUVFHRXdKVlV6QWVGdzB5TVRFeE1Ea3lNREEzTkRsYUZ3MHlPREV4TURreU1EQTMK"
      "TkRsYU1IQXhJakFnQmdOVkJBTU1HVWx1ZEdWc0lGTkhXQ0JRUTBzZ1EyVnlkR2xtYVdOaGRHVXhHakFZQmdOVgpCQW9N"
      "RVVsdWRHVnNJRU52Y25CdmNtRjBhVzl1TVJRd0VnWURWUVFIREF0VFlXNTBZU0JEYkdGeVlURUxNQWtHCkExVUVDQXdD"
      "UTBFeEN6QUpCZ05WQkFZVEFsVlRNRmt3RXdZSEtvWkl6ajBDQVFZSUtvWkl6ajBEQVFjRFFnQUUKd2k2M1Nkc1hrTzhB"
      "RlBLM011ZEJrVkU3TVBtOUF6MHBvRkFuZE8vRGxqL1pLSWplVHVnMXRvSTFtbEExd2JBLwoySnJ5b3doOEhiMU9vclhQ"
      "UVlEK0lxT0NBcWd3Z2dLa01COEdBMVVkSXdRWU1CYUFGTkRvcXRwMTEva3VTUmVZClBIc1VaZERWOGxsTk1Hd0dBMVVk"
      "SHdSbE1HTXdZYUJmb0YyR1cyaDBkSEJ6T2k4dllYQnBMblJ5ZFhOMFpXUnoKWlhKMmFXTmxjeTVwYm5SbGJDNWpiMjB2"
      "YzJkNEwyTmxjblJwWm1sallYUnBiMjR2ZGpNdmNHTnJZM0pzUDJOaApQWEJ5YjJObGMzTnZjaVpsYm1OdlpHbHVaejFr"
      "WlhJd0hRWURWUjBPQkJZRUZDdDk0Y1oxZEJYY3V1UHBVNjZyCjAwMklEUFhDTUE0R0ExVWREd0VCL3dRRUF3SUd3REFN"
      "QmdOVkhSTUJBZjhFQWpBQU1JSUIxQVlKS29aSWh2aE4KQVEwQkJJSUJ4VENDQWNFd0hnWUtLb1pJaHZoTkFRMEJBUVFR"
      "WWNVbDROVjZyZUR0TzB4KzgvN1B6ekNDQVdRRwpDaXFHU0liNFRRRU5BUUl3Z2dGVU1CQUdDeXFHU0liNFRRRU5BUUlC"
      "QWdFUk1CQUdDeXFHU0liNFRRRU5BUUlDCkFnRVJNQkFHQ3lxR1NJYjRUUUVOQVFJREFnRUNNQkFHQ3lxR1NJYjRUUUVO"
      "QVFJRUFnRUVNQkFHQ3lxR1NJYjQKVFFFTkFRSUZBZ0VCTUJFR0N5cUdTSWI0VFFFTkFRSUdBZ0lBZ0RBUUJnc3Foa2lH"
      "K0UwQkRRRUNCd0lCQmpBUQpCZ3NxaGtpRytFMEJEUUVDQ0FJQkFEQVFCZ3NxaGtpRytFMEJEUUVDQ1FJQkFEQVFCZ3Nx"
      "aGtpRytFMEJEUUVDCkNnSUJBREFRQmdzcWhraUcrRTBCRFFFQ0N3SUJBREFRQmdzcWhraUcrRTBCRFFFQ0RBSUJBREFR"
      "QmdzcWhraUcKK0UwQkRRRUNEUUlCQURBUUJnc3Foa2lHK0UwQkRRRUNEZ0lCQURBUUJnc3Foa2lHK0UwQkRRRUNEd0lC"
      "QURBUQpCZ3NxaGtpRytFMEJEUUVDRUFJQkFEQVFCZ3NxaGtpRytFMEJEUUVDRVFJQkN6QWZCZ3NxaGtpRytFMEJEUUVD"
      "CkVnUVFFUkVDQkFHQUJnQUFBQUFBQUFBQUFEQVFCZ29xaGtpRytFMEJEUUVEQkFJQUFEQVVCZ29xaGtpRytFMEIKRFFF"
      "RUJBWUFrRzdWQUFBd0R3WUtLb1pJaHZoTkFRMEJCUW9CQURBS0JnZ3Foa2pPUFFRREFnTklBREJGQWlFQQorc1AvOFJ4"
      "bW1qejd1aHdPbTFzU1ladjBseitFSlVmelNYSnlTODRPQlNrQ0lGdFI3ZGlvTUJwWjZPaDU1UkJyCmpHWm5IMVRCTTV2"
      "aTBNc24wWHVXSmNRWAotLS0tLUVORCBDRVJUSUZJQ0FURS0tLS0tCi0tLS0tQkVHSU4gQ0VSVElGSUNBVEUtLS0tLQpN"
      "SUlDbURDQ0FqNmdBd0lCQWdJVkFORG9xdHAxMS9rdVNSZVlQSHNVWmREVjhsbE5NQW9HQ0NxR1NNNDlCQU1DCk1HZ3hH"
      "akFZQmdOVkJBTU1FVWx1ZEdWc0lGTkhXQ0JTYjI5MElFTkJNUm93R0FZRFZRUUtEQkZKYm5SbGJDQkQKYjNKd2IzSmhk"
      "R2x2YmpFVU1CSUdBMVVFQnd3TFUyRnVkR0VnUTJ4aGNtRXhDekFKQmdOVkJBZ01Ba05CTVFzdwpDUVlEVlFRR0V3SlZV"
      "ekFlRncweE9EQTFNakV4TURVd01UQmFGdzB6TXpBMU1qRXhNRFV3TVRCYU1IRXhJekFoCkJnTlZCQU1NR2tsdWRHVnNJ"
      "Rk5IV0NCUVEwc2dVSEp2WTJWemMyOXlJRU5CTVJvd0dBWURWUVFLREJGSmJuUmwKYkNCRGIzSndiM0poZEdsdmJqRVVN"
      "QklHQTFVRUJ3d0xVMkZ1ZEdFZ1EyeGhjbUV4Q3pBSkJnTlZCQWdNQWtOQgpNUXN3Q1FZRFZRUUdFd0pWVXpCWk1CTUdC"
      "eXFHU000OUFnRUdDQ3FHU000OUF3RUhBMElBQkw5cStOTXAySU9nCnRkbDFiay91V1o1K1RHUW04YUNpOHo3OGZzK2ZL"
      "Q1EzZCt1RHpYblZUQVQyWmhEQ2lmeUl1Snd2TjN3TkJwOWkKSEJTU01KTUpyQk9qZ2Jzd2diZ3dId1lEVlIwakJCZ3dG"
      "b0FVSW1VTTFscWROSW56ZzdTVlVyOVFHemtuQnF3dwpVZ1lEVlIwZkJFc3dTVEJIb0VXZ1E0WkJhSFIwY0hNNkx5OWpa"
      "WEowYVdacFkyRjBaWE11ZEhKMWMzUmxaSE5sCmNuWnBZMlZ6TG1sdWRHVnNMbU52YlM5SmJuUmxiRk5IV0ZKdmIzUkRR"
      "UzVrWlhJd0hRWURWUjBPQkJZRUZORG8KcXRwMTEva3VTUmVZUEhzVVpkRFY4bGxOTUE0R0ExVWREd0VCL3dRRUF3SUJC"
      "akFTQmdOVkhSTUJBZjhFQ0RBRwpBUUgvQWdFQU1Bb0dDQ3FHU000OUJBTUNBMGdBTUVVQ0lRQ0pnVGJ0VnFPeVoxbTNq"
      "cWlBWE02UVlhNnI1c1dTCjR5L0c3eTh1SUpHeGR3SWdScVB2QlNLenpRYWdCTFFxNXM1QTcwcGRvaWFSSjh6LzB1RHo0"
      "TmdWOTFrPQotLS0tLUVORCBDRVJUSUZJQ0FURS0tLS0tCi0tLS0tQkVHSU4gQ0VSVElGSUNBVEUtLS0tLQpNSUlDanpD"
      "Q0FqU2dBd0lCQWdJVUltVU0xbHFkTkluemc3U1ZVcjlRR3prbkJxd3dDZ1lJS29aSXpqMEVBd0l3CmFERWFNQmdHQTFV"
      "RUF3d1JTVzUwWld3Z1UwZFlJRkp2YjNRZ1EwRXhHakFZQmdOVkJBb01FVWx1ZEdWc0lFTnYKY25CdmNtRjBhVzl1TVJR"
      "d0VnWURWUVFIREF0VFlXNTBZU0JEYkdGeVlURUxNQWtHQTFVRUNBd0NRMEV4Q3pBSgpCZ05WQkFZVEFsVlRNQjRYRFRF"
      "NE1EVXlNVEV3TkRVeE1Gb1hEVFE1TVRJek1USXpOVGsxT1Zvd2FERWFNQmdHCkExVUVBd3dSU1c1MFpXd2dVMGRZSUZK"
      "dmIzUWdRMEV4R2pBWUJnTlZCQW9NRVVsdWRHVnNJRU52Y25CdmNtRjAKYVc5dU1SUXdFZ1lEVlFRSERBdFRZVzUwWVNC"
      "RGJHRnlZVEVMTUFrR0ExVUVDQXdDUTBFeEN6QUpCZ05WQkFZVApBbFZUTUZrd0V3WUhLb1pJemowQ0FRWUlLb1pJemow"
      "REFRY0RRZ0FFQzZuRXdNRElZWk9qL2lQV3NDemFFS2k3CjFPaU9TTFJGaFdHamJuQlZKZlZua1k0dTNJamtEWVlMME14"
      "TzRtcXN5WWpsQmFsVFZZeEZQMnNKQks1emxLT0IKdXpDQnVEQWZCZ05WSFNNRUdEQVdnQlFpWlF6V1dwMDBpZk9EdEpW"
      "U3YxQWJPU2NHckRCU0JnTlZIUjhFU3pCSgpNRWVnUmFCRGhrRm9kSFJ3Y3pvdkwyTmxjblJwWm1sallYUmxjeTUwY25W"
      "emRHVmtjMlZ5ZG1salpYTXVhVzUwClpXd3VZMjl0TDBsdWRHVnNVMGRZVW05dmRFTkJMbVJsY2pBZEJnTlZIUTRFRmdR"
      "VUltVU0xbHFkTkluemc3U1YKVXI5UUd6a25CcXd3RGdZRFZSMFBBUUgvQkFRREFnRUdNQklHQTFVZEV3RUIvd1FJTUFZ"
      "QkFmOENBUUV3Q2dZSQpLb1pJemowRUF3SURTUUF3UmdJaEFPVy81UWtSK1M5Q2lTRGNOb293THVQUkxzV0dmL1lpN0dT"
      "WDk0Qmd3VHdnCkFpRUE0SjBsckhvTXMrWG81by9zWDZPOVFXeEhSQXZaVUdPZFJRN2N2cVJYYXFJPQotLS0tLUVORCBD"
      "RVJUSUZJQ0FURS0tLS0tCgA");
}}}}} // namespace Azure::Security::KeyVault::Keys::Test
// cspell:enable
