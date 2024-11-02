cmake_minimum_required(VERSION 3.22)

project(CrazyMaze VERSION 0.1.0)
add_executable(CrazyMaze)

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
        classes/Bullet.cpp
        classes/CatchableObject.cpp
        classes/Enemy.cpp
        classes/Level.cpp
        classes/Maze.cpp
        classes/Player.cpp
        classes/Renderer.cpp
        classes/Timer.cpp
        classes/UI.cpp
        classes/Wall.cpp
        classes/Window.cpp
        functions/KeysManager.cpp
        functions/LevelElementsManager.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        classes
        enums
        functions
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        SDL2-static
        ${OPENGL_gl_LIBRARY}
        ${CMAKE_DL_LIBS}
        SDL2_image
        SDL2_ttf
        IMGUI
        glew
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "crazy_maze")

if(MSVC)
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        _SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING
)
endif()