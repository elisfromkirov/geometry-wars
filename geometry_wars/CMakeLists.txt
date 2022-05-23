file(GLOB_RECURSE GAME_INCLUDES *.hpp)
file(GLOB_RECURSE GAME_SOURCES *.cpp)

target_include_directories(game
  PUBLIC
    .
  )

target_sources(game
  PUBLIC
    ${GAME_INCLUDES}
  PRIVATE
    ${GAME_SOURCES}
  )