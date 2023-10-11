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
FetchContent_Populate(sdl2)


# SDL1
include(FetchContent)
FetchContent_Declare(
        sdl1
        GIT_REPOSITORY https://github.com/libsdl-org/sdl12-compat
        GIT_TAG        release-1.2.68
)

# FetchContent_Declare(
#         sdl1
#         GIT_REPOSITORY https://github.com/kattkieru/sdl
#         GIT_TAG        master
# )

FetchContent_GetProperties(sdl1)
if(NOT sdl1_POPULATED)
    FetchContent_Populate(sdl1)
    if (MSVC)
        set(SHARED ON)
    else()
        set(SHARED OFF)
    endif()

    # set(CMAKE_SKIP_RPATH FALSE)
    set(SDL12TESTS OFF)
    set(SDL12DEVEL OFF)

    if(APPLE)
        set(STATICDEVEL OFF)
    else()
        set(STATICDEVEL ON)   
    endif(APPLE)
    
    set(SDL2_INCLUDE_DIR ${sdl2_SOURCE_DIR}/include)
add_subdirectory(${sdl1_SOURCE_DIR} ${sdl1_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# FetchContent_Declare(
#     sdl1_image
#         GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
#         GIT_TAG        SDL-1.2
# )
# FetchContent_GetProperties(sdl1_image)
# if(NOT sdl1_image_POPULATED)
#     FetchContent_Populate(sdl1_image)
#     if (MSVC)
#         set(BUILD_SHARED_LIBS ON)
#     else()
#         set(BUILD_SHARED_LIBS OFF)
#     endif()
#     set(SDLIMAGE_SAMPLES OFF)
#     set(SDLIMAGE_DEPS_SHARED OFF)
#     set(SDLIMAGE_TESTS OFF)
#     add_subdirectory(${sdl1_image_SOURCE_DIR} ${sdl1_image_BINARY_DIR} EXCLUDE_FROM_ALL)
# endif()

if(APPLE)
    set(CMAKE_CXX_FLAGS "-framework Cocoa")    
endif(APPLE)

# main code
add_executable(${PROJECT_NAME} main-win.cpp)

message("sdl1_SOURCE_DIR: ${sdl1_SOURCE_DIR}
sdl1_image_SOURCE_DIR: ${sdl1_image_SOURCE_DIR}
")

# include
target_include_directories(${PROJECT_NAME} PUBLIC 
${sdl1_SOURCE_DIR}/include/SDL ${sdl1_BINARY_DIR}
${sdl1_image_SOURCE_DIR}/include ${sdl1_image_BINARY_DIR}/include
)
# Link with dependencies

target_link_libraries(${PROJECT_NAME} PRIVATE SDL SDLmain)

