cmake_minimum_required(VERSION 3.7)
project(main)

# SDL2
include(FetchContent)
FetchContent_Declare(
        sdl2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL
        GIT_TAG        release-2.28.4
)
FetchContent_GetProperties(sdl2)
if(NOT sdl2_POPULATED)
    FetchContent_Populate(sdl2)
    if (MSVC)
        set(BUILD_SHARED_LIBS ON)
    else()
        set(BUILD_SHARED_LIBS OFF)
    endif()
    set(SDL_X11_SHARED OFF)
    add_subdirectory(${sdl2_SOURCE_DIR} ${sdl2_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

include(FetchContent)
FetchContent_Declare(
    sdl2_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
        GIT_TAG        SDL2
)
FetchContent_GetProperties(sdl2_image)
if(NOT sdl2_image_POPULATED)
    FetchContent_Populate(sdl2_image)
    if (MSVC)
        set(BUILD_SHARED_LIBS ON)
    else()
        set(BUILD_SHARED_LIBS OFF)
    endif()
    set(SDL2IMAGE_SAMPLES OFF)
    set(SDL2IMAGE_DEPS_SHARED OFF)
    set(SDL2IMAGE_TESTS OFF)
    add_subdirectory(${sdl2_image_SOURCE_DIR} ${sdl2_image_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


# main code
add_executable(${PROJECT_NAME} main-win.cpp)

message("sdl2_SOURCE_DIR: ${sdl2_SOURCE_DIR}
sdl2_image_SOURCE_DIR: ${sdl2_image_SOURCE_DIR}
")

# include
target_include_directories(${PROJECT_NAME} PUBLIC 
${sdl2_SOURCE_DIR}/include ${sdl2_BINARY_DIR}/include
${sdl2_image_SOURCE_DIR}/include ${sdl2_image_BINARY_DIR}/include
)
# Link with dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2-static SDL2_image)
