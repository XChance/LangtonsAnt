cmake_minimum_required(VERSION 3.12)
project(Langtons_Ant)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Sources/main.cpp Sources/Application.cpp Sources/Random.cpp Sources/Automaton.cpp Sources/Ant.cpp Headers/Ant.h)
add_executable(Langtons_Ant ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Langtons_Ant ${SFML_LIBRARIES})
endif()

install(TARGETS Langtons_Ant DESTINATION ${CMAKE_BINARY_DIR}/bin/)