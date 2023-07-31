#
#   ╔═╗╦ ╦╔╗ ╔═╗╦═╗  ╦  ╦╔═╗╔═╗  ╦  ╔═╗╔╗ ╔═╗╦═╗╔═╗╔╦╗╔═╗╦═╗╦ ╦
#   ║  ╚╦╝╠╩╗║╣ ╠╦╝  ║  ║╠╣ ║╣   ║  ╠═╣╠╩╗║ ║╠╦╝╠═╣ ║ ║ ║╠╦╝╚╦╝
#   ╚═╝ ╩ ╚═╝╚═╝╩╚═  ╩═╝╩╚  ╚═╝  ╩═╝╩ ╩╚═╝╚═╝╩╚═╩ ╩ ╩ ╚═╝╩╚═ ╩
#
#   cmake/CMakeLists.txt
#   Main CMake for the project; builds project sources, links and includes required libraries.
#

cmake_minimum_required(VERSION 3.26)
project(cyber_life_laboratory VERSION 0.1 LANGUAGES CXX)

# ---------------- SOURCES ----------------
set(SOURCES_DIR ../src)
set(SOURCES_BINARY_DIR ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(${SOURCES_DIR} ${SOURCES_BINARY_DIR})
