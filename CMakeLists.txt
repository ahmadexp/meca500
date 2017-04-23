cmake_minimum_required(VERSION 3.6.2 FATAL_ERROR)

project("Meca500")

set(PROJECT_NAME Meca500)

set(SRC src)
file(GLOB SRC_FILES ${SRC}/[^.]*.cpp)
add_subdirectory(test)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
  socket++
  pthread
)
target_compile_options(${PROJECT_NAME} PRIVATE
			-std=c++14
)
