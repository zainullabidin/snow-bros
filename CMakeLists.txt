cmake_minimum_required(VERSION 3.16)
project(SnowBros)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ─────────────────────────────────────────
# Platform-specific SFML path
# ─────────────────────────────────────────
if(WIN32)
    # Windows — update this path to wherever YOU installed SFML
    set(SFML_DIR "C:/SFML/lib/cmake/SFML")
elseif(APPLE)
    # Mac — Homebrew default
    set(SFML_DIR "/opt/homebrew/lib/cmake/SFML")
endif()
# Linux (GitHub Actions) — no path needed, apt installs it globally

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
# Collect all source files
# ─────────────────────────────────────────
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
)

# ─────────────────────────────────────────
# Create executable
# ─────────────────────────────────────────
add_executable(SnowBros ${SOURCES})

# ─────────────────────────────────────────
# Include directories
# ─────────────────────────────────────────
target_include_directories(SnowBros PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/core
    ${CMAKE_SOURCE_DIR}/include/entities
    ${CMAKE_SOURCE_DIR}/include/entities/player
    ${CMAKE_SOURCE_DIR}/include/entities/enemies
    ${CMAKE_SOURCE_DIR}/include/entities/projectiles
    ${CMAKE_SOURCE_DIR}/include/entities/powerups
    ${CMAKE_SOURCE_DIR}/include/levels
    ${CMAKE_SOURCE_DIR}/include/systems
    ${CMAKE_SOURCE_DIR}/include/factories
    ${CMAKE_SOURCE_DIR}/include/auth
    ${CMAKE_SOURCE_DIR}/include/database
    ${CMAKE_SOURCE_DIR}/include/ui
)

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
# Copy assets to build directory
# ─────────────────────────────────────────
add_custom_command(TARGET SnowBros POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:SnowBros>/assets
)

# ─────────────────────────────────────────
# Copy config to build directory
# ─────────────────────────────────────────
add_custom_command(TARGET SnowBros POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/config
    $<TARGET_FILE_DIR:SnowBros>/config
)

# ─────────────────────────────────────────
# Copy data to build directory
# ─────────────────────────────────────────
add_custom_command(TARGET SnowBros POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data
    $<TARGET_FILE_DIR:SnowBros>/data
)
