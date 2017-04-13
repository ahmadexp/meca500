cmake_minimum_required(VERSION 3.6.2 FATAL_ERROR)

project("Meca500")

add_executable(meca500 main.cpp
			GetSocket.cpp
#			DestroySocket.cpp
#			ActivateRobot.cpp
#			DeactivateRobot.cpp
#			ReadFromSocket.cpp
#			HomeRobot.cpp
#			SetJoints.cpp
)
target_link_libraries(meca500 socket++)
target_compile_options(meca500 PRIVATE
			-std=c++11
)
