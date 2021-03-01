message(STATUS "examples ... ")

ADD_EXECUTABLE(dump         babyMindDataDump.cpp)
TARGET_LINK_LIBRARIES(dump  BabyMINDUnpack)

if    (ROOT_FOUND)
  ADD_EXECUTABLE(unpack                         babyMindUnpack.cpp)
  TARGET_LINK_LIBRARIES(unpack                  BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(ufe-monitor                    ufe_monitor.cpp)
  TARGET_LINK_LIBRARIES(ufe-monitor             BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(TDMunpack                      babyMINDTDMUnpack.cpp)
  TARGET_LINK_LIBRARIES(TDMunpack               BabyMINDUnpack ${ROOT_LIBRARIES})
  
  ADD_EXECUTABLE(Calibration                    babyMindCalibration.cpp)
  TARGET_LINK_LIBRARIES(Calibration             BabyMINDUnpack "${ROOT_LIBRARIES} -lSpectrum")

  ADD_EXECUTABLE(GTrigTagSearch                 GTrigTagSearch.cpp)
  TARGET_LINK_LIBRARIES(GTrigTagSearch          BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(SpillTagSearch                 GSpillSearch.cpp)
  TARGET_LINK_LIBRARIES(SpillTagSearch          BabyMINDUnpack ${ROOT_LIBRARIES})
  
  ADD_EXECUTABLE(HG_vs_LG_calib                 HG_LG_calib.cpp)
  TARGET_LINK_LIBRARIES(HG_vs_LG_calib          BabyMINDUnpack ${ROOT_LIBRARIES})
  
  ADD_EXECUTABLE(LG_vs_ToT_calib                LG_vs_ToT_calib.cpp)
  TARGET_LINK_LIBRARIES(LG_vs_ToT_calib         BabyMINDUnpack ${ROOT_LIBRARIES})
  
  ADD_EXECUTABLE(HG_vs_ToT_calib                HG_vs_ToT_calib.cpp)
  TARGET_LINK_LIBRARIES(HG_vs_ToT_calib         BabyMINDUnpack ${ROOT_LIBRARIES})
  
  ADD_EXECUTABLE(HG_reconstructed               HG_reconstructed.cpp)
  TARGET_LINK_LIBRARIES(HG_reconstructed        BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(DataQualityCheck               babyMindDataQualityCheck.cpp)
  TARGET_LINK_LIBRARIES(DataQualityCheck        BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(Amplitude_matching             BabyMIND_ToT_Amplitude_matching.cpp)
  TARGET_LINK_LIBRARIES(Amplitude_matching      BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(gainStudy                      babyMindGainStudy.cpp)
  TARGET_LINK_LIBRARIES(gainStudy               BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(PedSearch                      babyMindPedSearch.cpp)
  TARGET_LINK_LIBRARIES(PedSearch               BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(ButterflyPlots                 ButterflyPlots.cpp)
  TARGET_LINK_LIBRARIES(ButterflyPlots          BabyMINDUnpack ${ROOT_LIBRARIES})

  ADD_EXECUTABLE(ListButterflyPlots             ListButterflyPlots.cpp)
  TARGET_LINK_LIBRARIES(ListButterflyPlots          BabyMINDUnpack ${ROOT_LIBRARIES})

endif (ROOT_FOUND)
