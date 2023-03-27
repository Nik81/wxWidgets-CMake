CMAKE_MINIMUM_REQUIRED(VERSION 3.8.2)
 MESSAGE("Configuring Libraries")

 SET(wxBUILD_SHARED FALSE)

 #SUBDIRS(wxWidgets)
 ADD_SUBDIRECTORY(wxWidgets)
 ADD_SUBDIRECTORY(${PROJECT_BINARY_DIR}/Libraries/wxWidgets/Sources build)

 ADD_LIBRARY(Libraries::wx::net ALIAS wxnet)
 ADD_LIBRARY(Libraries::wx::base ALIAS wxbase)
 ADD_LIBRARY(Libraries::wx::core ALIAS wxcore)