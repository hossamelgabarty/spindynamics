add_executable(powder main.cpp powder.cpp)
OptimizeForArchitecture(powder)
target_link_libraries(powder ${Boost_LIBRARIES} ${FFTW_LIBRARIES})
