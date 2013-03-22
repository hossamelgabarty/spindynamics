add_executable(powder main.cpp powder.cpp)
OptimizeForArchitecture(powder)
target_link_libraries(powder ${Boost_LIBRARIES} ${FFTW_LIBRARIES})
install(TARGETS powder  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})
