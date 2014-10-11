# The name of our project is "SPACECHESS". CMakeLists files in this project can
# refer to the root source directory of the project as ${SPACECHESS_SOURCE_DIR} and
# to the root binary directory of the project as ${SPACECHESS_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (spacechess)

# Enable C++11
set (CMAKE_CXX_FLAGS    "-Wall -std=c++11")

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../whole)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../whole)


# Recurse into subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
# Example:
# add_subdirectory (lib/glfw)
# add_subdirectory (lib/glm)

add_subdirectory(source)


