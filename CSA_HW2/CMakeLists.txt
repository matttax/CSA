# project name and language
project(CSA_HW2)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
# Headers
rand.h
container.h
shape.h
parallelepiped.h
regtet.h
sphere.h

# Sources
container.cpp
shape.cpp
parallelepiped.cpp
regtet.cpp
sphere.cpp
main.cpp
)

add_executable(task ${SOURCE_FILES})