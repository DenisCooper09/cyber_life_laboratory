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

# ---------------- LIBRARIES ----------------
set(LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/../libs)

# GLEW
set(GLEW_INCLUDE_DIR ${LIBRARIES_DIR}/GLEW/include)
set(GLEW_LIB_DIR ${LIBRARIES_DIR}/GLEW)

target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLEW_LIB_DIR}/libglew.a)

# GLFW
set(GLFW_INCLUDE_DIR ${LIBRARIES_DIR}/GLFW/include)
set(GLFW_LIB_DIR ${LIBRARIES_DIR}/GLFW)

target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_LIB_DIR}/libglfw3.a gdi32 opengl32)

# Dear ImGui
set(IMGUI_INCLUDE_DIR ${LIBRARIES_DIR}/ImGui/include)
set(IMGUI_LIB_DIR ${LIBRARIES_DIR}/ImGui)

target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${IMGUI_LIB_DIR}/libimgui.a)
