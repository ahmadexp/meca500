cmake_minimum_required(VERSION 3.6.2 FATAL_ERROR)

set(name "meca500_test")
set(MECA500_SRC_DIR "../src")
set(GTEST_PATH "googletest")
project(${name})

add_subdirectory(${GTEST_PATH})
include_directories(${GTEST_PATH}/include)
include_directories(${MECA500_SRC_DIR})
include_directories(fakes)
file(GLOB TEST_SRC
	"[^.]*.cpp"
)
file(GLOB TEST_FAKES
	"fakes/*.cpp"
)

add_executable(${name}
  main_test.cpp
  Sending_tests.cpp
  Receiving_tests.cpp
		${TEST_FAKES}
		${MECA500_SRC_DIR}/MessageAssembler.cpp
		${MECA500_SRC_DIR}/Sending.cpp
		${MECA500_SRC_DIR}/Receiving.cpp
		${MECA500_SRC_DIR}/Exception.h
)
target_link_libraries(${name} 
			socket++
			gtest
)
target_compile_options(${name} PRIVATE
			-std=c++11
)
