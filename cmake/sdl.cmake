if(NOT DEFINED EMSCRIPTEN)
SET(BUILD_SHARED_LIBS OFF CACHE BOOL "BUILD_SHARED_LIBS" FORCE)
SET(BUILD_STATIC_LIBS ON CACHE BOOL "BUILD_STATIC_LIBS" FORCE)
SET(POSITION_INDEPENDENT_CODE ON CACHE BOOL "POSITION_INDEPENDENT_CODE" FORCE)

string(TIMESTAMP BEFORE "%s")
CPMAddPackage(
        NAME SDL2
        GITHUB_REPOSITORY libsdl-org/SDL
        GIT_TAG release-2.26.2
        OPTIONS
        "SDL2_DISABLE_INSTALL ON"
        "SDL_SHARED OFF"
        "SDL_STATIC ON"
        "SDL_STATIC_PIC ON"
        "SDL_WERROR OFF"
)
find_package(SDL2 REQUIRED)

    file(GLOB SDL2_HEADERS "${SDL2_SOURCE_DIR}/include/*.h")

    add_custom_target(sdl_copy_headers_in_build_dir
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${SDL2_SOURCE_DIR}/include" "${CMAKE_BINARY_DIR}/SDLHeaders/SDL2"
            DEPENDS ${SDL2_HEADERS})

    add_dependencies(SDL2-static sdl_copy_headers_in_build_dir)

    target_include_directories(SDL2-static INTERFACE "${CMAKE_BINARY_DIR}/SDLHeaders")

    set (SDL2_INCLUDE_DIR ${SDL2_SOURCE_DIR}/include)

include_directories(${SDL2_INCLUDE_DIR})
string(TIMESTAMP AFTER "%s")
math(EXPR DELTASDL "${AFTER} - ${BEFORE}")
MESSAGE(STATUS "SDL2 TIME: ${DELTASDL}s")

string(TIMESTAMP BEFORE "%s")
CPMAddPackage(GITHUB_REPOSITORY libsdl-org/SDL_image
        GIT_TAG release-2.6.2
        OPTIONS
        "SDL2IMAGE_INSTALL OFF"
        "SDL2IMAGE_SAMPLES OFF"
        "SDL2IMAGE_VENDORED ON"
        "SDL2IMAGE_BUILD_SHARED_LIBS OFF"
        "GIT_SUBMODULES_RECURSE ON"
)
find_package(SDL_image REQUIRED)
include_directories(${SDL_image_SOURCE_DIR})
string(TIMESTAMP AFTER "%s")
math(EXPR DELTASDL_image "${AFTER} - ${BEFORE}")
MESSAGE(STATUS "SDL_image TIME: ${DELTASDL_image}s")

string(TIMESTAMP BEFORE "%s")
CPMAddPackage(GITHUB_REPOSITORY libsdl-org/SDL_mixer
        GIT_TAG release-2.8.0
)
find_package(SDL_mixer REQUIRED)
include_directories(${SDL_mixer_SOURCE_DIR})
string(TIMESTAMP AFTER "%s")
math(EXPR DELTASDL_mixer "${AFTER} - ${BEFORE}")
MESSAGE(STATUS "SDL_mixer TIME: ${DELTASDL_mixer}s")

string(TIMESTAMP BEFORE "%s")
CPMAddPackage(GITHUB_REPOSITORY libsdl-org/SDL_ttf
        GIT_TAG release-2.22.0
)
find_package(SDL_ttf REQUIRED)
include_directories(${SDL_ttf_SOURCE_DIR})
string(TIMESTAMP AFTER "%s")
math(EXPR DELTASDL_ttf "${AFTER} - ${BEFORE}")
MESSAGE(STATUS "SDL_ttf TIME: ${DELTASDL_ttf}s")

ENDIF()