cmake_minimum_required(VERSION 3.6.2 FATAL_ERROR)

set(name "meca500_test")
set(MECA500_DIR "../")
set(GTEST_PATH "googletest")
project(${name})

add_subdirectory(${GTEST_PATH})
include_directories(${GTEST_PATH}/include)
include_directories(${MECA500_DIR})

file(GLOB TEST_SRC
	"*.cpp"
)

set(MECA_SRC "${MECA500_DIR}/MessageAssembler.cpp")
add_executable(${name}
		${TEST_SRC}
		${MECA500_DIR}/MessageAssembler.cpp
		${MECA500_DIR}/Sending.cpp
		${MECA500_DIR}/Exception.h
)
target_link_libraries(${name} 
			socket++
			gtest
)
target_compile_options(${name} PRIVATE
			-std=c++11
)
