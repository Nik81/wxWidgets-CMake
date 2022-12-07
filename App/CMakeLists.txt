cmake_minimum_required(VERSION 3.8.2)
project(App)

file(GLOB SRC_FILES "*.cpp")

if(WIN32)
	add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
else()
	add_executable(${PROJECT_NAME} ${SRC_FILES})
endif()

target_link_libraries(${PROJECT_NAME} Libraries::wx::net Libraries::wx::core Libraries::wx::base)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

