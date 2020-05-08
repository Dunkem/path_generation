cmake_minimum_required(VERSION 3.4)
project(path_generation_test)

include_directories(
  path_generation.h
  newton_insert.h
)
add_executable(${PROJECT_NAME}
  path_generation.cpp
  test.cpp
  )

add_executable(newton_test
  newton_insert.cpp
  newton_test.cpp
  )
