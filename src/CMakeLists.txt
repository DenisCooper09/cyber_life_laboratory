#
#   ╔═╗╦ ╦╔╗ ╔═╗╦═╗  ╦  ╦╔═╗╔═╗  ╦  ╔═╗╔╗ ╔═╗╦═╗╔═╗╔╦╗╔═╗╦═╗╦ ╦
#   ║  ╚╦╝╠╩╗║╣ ╠╦╝  ║  ║╠╣ ║╣   ║  ╠═╣╠╩╗║ ║╠╦╝╠═╣ ║ ║ ║╠╦╝╚╦╝
#   ╚═╝ ╩ ╚═╝╚═╝╩╚═  ╩═╝╩╚  ╚═╝  ╩═╝╩ ╩╚═╝╚═╝╩╚═╩ ╩ ╩ ╚═╝╩╚═ ╩
#
#   src/CMakeLists.txt
#   CMake subdirectory that adds project sources to the executable.
#

set(SOURCES
        main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
