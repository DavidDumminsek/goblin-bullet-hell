cmake_minimum_required(VERSION 3.16)

project (dogeater)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "usr/include")
find_package(SFML REQUIRED COMPONENTS graphics window system)
find_package(jsoncpp REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(SOURCE 
  ../src/main.cc 
  ../src/game.cc 
  ../src/entity.cc 
  ../src/enemy.cc
)

add_executable(dogeater ${SOURCE})
target_link_libraries(dogeater PRIVATE sfml-graphics sfml-window sfml-window jsoncpp )

