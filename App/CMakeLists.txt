CMAKE_MINIMUM_REQUIRED(VERSION 3.8.2)
 PROJECT(App)

 #FILE(GLOB SRC_FILES "*.cpp")
 
 #SET(PROJECT_SRCS
 FILE(GLOB SRC_FILES
  MyApp.h          MyApp.cpp
  MyDialog.h       MyDialog.cpp
  MyFrame.h        MyFrame.cpp
  #MyFrameManager.h MyFrameManager.cpp
  MyInnerFrame.h   MyInnerFrame.cpp
  MyLogPanel.h     MyLogPanel.cpp
  MyNotebook.h     MyNotebook.cpp
  MyTimebar.h      MyTimebar.cpp
  MyWindow.h       MyWindow.cpp
 )
 
 #ADD_LIBRARY(${PROJECT_NAME} ${PROJECT_SRCS})
 
 if(WIN32)
	ADD_EXECUTABLE(${PROJECT_NAME} WIN32 ${SRC_FILES})
 else()
	ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_FILES})
 endif()

 TARGET_LINK_LIBRARIES(${PROJECT_NAME} Libraries::wx::net Libraries::wx::core Libraries::wx::base)

 SET(CMAKE_CXX_STANDARD 14)
 SET(CMAKE_CXX_STANDARD_REQUIRED ON)
 SET(CMAKE_CXX_EXTENSIONS OFF)
