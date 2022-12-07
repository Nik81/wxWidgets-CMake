cmake_minimum_required(VERSION 3.8.2)

set(wxBUILD_SHARED FALSE)

add_subdirectory(wxWidgets)

add_library(Libraries::wx::net ALIAS wxnet)
add_library(Libraries::wx::base ALIAS wxbase)
add_library(Libraries::wx::core ALIAS wxcore)
