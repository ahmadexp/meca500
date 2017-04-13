cmake_minimum_required(VERSION 3.6.2 FATAL_ERROR)



set(name "meca500_test")
set(MECA500_DIR "../")
set(GTEST_PATH "googletest")
project(${name})

add_subdirectory(${GTEST_PATH})
include_directories(${GTEST_PATH}/include)
include_directories(${MECA500_DIR})
add_executable(${name}
		main.cpp
		Meca500_test.cpp
		${MECA500_DIR}/Messaging.cpp
		${MECA500_DIR}/Meca500.cpp
)
target_link_libraries(${name} 
			socket++
			gtest
)
target_compile_options(${name} PRIVATE
			-std=c++11
)
