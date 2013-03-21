add_executable(smoothing main.cpp powder.cpp)
OptimizeForArchitecture(smoothing)
target_link_libraries(smoothing ${Boost_LIBRARIES} ${FFTW_LIBRARIES})
