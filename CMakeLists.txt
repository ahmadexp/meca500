cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project("Meca500")

add_executable(meca500 main.c
			GetSocket.c
			DestroySocket.c
			ActivateRobot.c
			DeactivateRobot.c
			ReadFromSocket.c
			HomeRobot.c
			SetJoints.c)
target_link_libraries(meca500 socket)

