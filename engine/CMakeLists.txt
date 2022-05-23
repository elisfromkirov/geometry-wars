add_library(engine)

file(GLOB_RECURSE ENGINE_INCLUDES *.hpp)
file(GLOB_RECURSE ENGINE_SOURCES *.cpp)

target_include_directories(engine
  PUBLIC
    .
  )

target_sources(engine
  PUBLIC
    ${ENGINE_INCLUDES}
  PRIVATE
    ${ENGINE_SOURCES}
  )

target_link_libraries(engine
  PRIVATE
    m
    X11
  )