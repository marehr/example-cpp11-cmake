add_library(complex complex.cpp)

add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)
add_test(NAME src/complex_test COMMAND complex_test)

add_executable(complex2_test complex2_test.cpp)
target_link_libraries(complex2_test complex)
add_test(NAME src/complex2_test COMMAND complex2_test)
