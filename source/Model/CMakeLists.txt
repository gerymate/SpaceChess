# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable called helloworld_SOURCES containing all .cpp files:
set(SOURCES position.cpp board.cpp history.cpp
	    coord.cpp field.cpp fullboard.cpp gamestate.cpp game.cpp
    )
	    
# For a large number of source files you can create it in a simpler way
# using file() function:
# file(GLOB hellworld_SOURCES *.cpp)

# Example:
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glfw/include)

# Make sure the linker can find the Hello library once it is built.
#link_directories (${SPACECHESS_BINARY_DIR}/Hello)

# Example:
# Link the executable to the glfw library.
# target_link_libraries(095_GLMandel glfw ${GLFW_LIBRARIES})

add_library(SpaceChessModel ${SOURCES})
target_link_libraries(SpaceChessModel SpaceChessPieces SpaceChessGameEvents)

add_subdirectory(Pieces)
add_subdirectory(GameEvents)

