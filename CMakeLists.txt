cmake_minimum_required(VERSION 3.16)
project(SnowBros)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ─────────────────────────────────────────
# Platform-specific SFML path
# ─────────────────────────────────────────
if(WIN32)
    set(SFML_DIR "C:/SFML/lib/cmake/SFML")
elseif(APPLE)
    set(SFML_DIR "/usr/local/opt/sfml@2/lib/cmake/SFML")
    include_directories(BEFORE /usr/local/Cellar/sfml@2/2.6.2_1/include)
endif()

# ─────────────────────────────────────────
# Find SFML
# ─────────────────────────────────────────
find_package(SFML 2.5 COMPONENTS
    graphics
    window
    system
    audio
REQUIRED)

# ─────────────────────────────────────────
# Collect all source files recursively
# ─────────────────────────────────────────
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
)

# ─────────────────────────────────────────
# Only build if there are source files
# ─────────────────────────────────────────
if(NOT SOURCES)
    message(WARNING "No source files found in src/ — adding dummy main.cpp")
    file(WRITE ${CMAKE_BINARY_DIR}/dummy_main.cpp "int main(){return 0;}")
    list(APPEND SOURCES ${CMAKE_BINARY_DIR}/dummy_main.cpp)
endif()

# ─────────────────────────────────────────
# Create executable
# ─────────────────────────────────────────
add_executable(SnowBros ${SOURCES})

# ─────────────────────────────────────────
# Include directories
# ─────────────────────────────────────────
set(INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/main
    ${CMAKE_SOURCE_DIR}/include/characters
    ${CMAKE_SOURCE_DIR}/include/characters/player
    ${CMAKE_SOURCE_DIR}/include/characters/enemies
    ${CMAKE_SOURCE_DIR}/include/characters/projectiles
    ${CMAKE_SOURCE_DIR}/include/characters/powerups
    ${CMAKE_SOURCE_DIR}/include/levels
    ${CMAKE_SOURCE_DIR}/include/systems
    ${CMAKE_SOURCE_DIR}/include/factory
    ${CMAKE_SOURCE_DIR}/include/auth
    ${CMAKE_SOURCE_DIR}/include/DB
    ${CMAKE_SOURCE_DIR}/include/UI
)

set(VALID_INCLUDE_DIRS "")
foreach(DIR ${INCLUDE_DIRS})
    if(EXISTS ${DIR})
        list(APPEND VALID_INCLUDE_DIRS ${DIR})
    endif()
endforeach()

target_include_directories(SnowBros PRIVATE ${VALID_INCLUDE_DIRS})

# ─────────────────────────────────────────
# Link SFML
# ─────────────────────────────────────────
target_link_libraries(SnowBros
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

# ─────────────────────────────────────────
# Copy assets/config/data if they exist
# ─────────────────────────────────────────
if(EXISTS ${CMAKE_SOURCE_DIR}/assets)
    add_custom_command(TARGET SnowBros POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:SnowBros>/assets
        COMMENT "Copying assets to build directory"
    )
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/config)
    add_custom_command(TARGET SnowBros POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/config
        $<TARGET_FILE_DIR:SnowBros>/config
        COMMENT "Copying config to build directory"
    )
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/data)
    add_custom_command(TARGET SnowBros POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/data
        $<TARGET_FILE_DIR:SnowBros>/data
        COMMENT "Copying data to build directory"
    )
endif()