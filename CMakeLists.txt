cmake_minimum_required(VERSION 3.0)

project(game)

add_executable(game)

add_subdirectory(engine)
add_subdirectory(geometry_wars)

target_link_libraries(game
  PRIVATE
    engine
  )

# set(CMAKE_CXX_FLAGS "-std=c++17 -O2")