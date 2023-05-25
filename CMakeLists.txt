cmake_minimum_required(VERSION 3.16)

project (dogeater)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "usr/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(DIRECTORY "./src/")
#target_include_directories(dogeater PRIVATE ${DIRECTORY})
set(SOURCE 
   ${DIRECTORY}main.cc 
   ${DIRECTORY}game.cc 
   ${DIRECTORY}entity.cc 
   ${DIRECTORY}enemy.cc
   ${DIRECTORY}player.cc
   ${DIRECTORY}projectile.cc
)
if(UNIX)
    find_package(SFML REQUIRED COMPONENTS graphics window system)
    find_package(jsoncpp REQUIRED)

    add_executable(dogeater ${SOURCE})

    #target_link_directories(dogeater PUBLIC ./src/levels/ ./src/sprites/)
    target_link_libraries(dogeater PRIVATE sfml-graphics sfml-window sfml-system jsoncpp )
else() #Windows
    set(CMAKE_SYSTEM_NAME Windows)

    find_package(SFML REQUIRED COMPONENTS graphics window system PATHS "~/SFML-2.51")
    find_package(jsoncpp REQUIRED)

    add_executable(dogeater WIN32 ${SOURCE})
    target_link_libraries(dogeater PRIVATE sfml-graphics sfml-window sfml-system jsoncpp)
    target_link_options(dogeater PRIVATE -mwindows)
endif()

