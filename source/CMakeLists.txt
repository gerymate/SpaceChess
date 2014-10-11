# Include the directory itself as a path to include directories
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES main.cpp)

include_directories(Model)

# Create an executable file called helloworld from sources:
add_executable(SpaceChess ${SOURCES})

# Example:
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glfw/include)
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glm)

# Make sure the linker can find the Hello library once it is built.
#link_directories (${SPACECHESS_BINARY_DIR}/Hello)

target_link_libraries(SpaceChess SpaceChessModel)

add_subdirectory(Model)
