# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable called helloworld_SOURCES containing all .cpp files:
set(SOURCES render25d.cpp 
	    stylesheet.cpp texturemanager.cpp fontmanager.cpp
	    boardpainter.cpp rank.cpp field.cpp fieldcontent.cpp
	    panelpainter.cpp widget.cpp cursorinfo.cpp nextplayerinfo.cpp messagewidget.cpp)

set(TEST_SOURCES viewtests.cpp
    stylesheettest.cpp 
    boardpaintertest.cpp 
    fieldtest.cpp fieldcontenttest.cpp ranktest.cpp
    )

# For a large number of source files you can create it in a simpler way
# using file() function:
# file(GLOB hellworld_SOURCES *.cpp)

add_library(SpaceChessView2D ${SOURCES})

add_executable(ViewTests ${TEST_SOURCES})
add_test(View_tests ViewTests)
target_link_libraries(ViewTests SpaceChessModel SpaceChessView2D SpaceChessController )

# Make sure the compiler can find include files from our glfw library.
# Example:
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glfw/include)
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glm)

# Make sure the linker can find the Hello library once it is built.
#link_directories (${SPACECHESS_BINARY_DIR}/Hello)

# Link with the required SFML modules
target_link_libraries(SpaceChessView2D SpaceChessCore sfml-graphics sfml-window sfml-system)
