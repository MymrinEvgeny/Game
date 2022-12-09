cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

set(GAME_PROJECT_NAME Game)
project(${GAME_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	PROPERTY VS_STARTUP_PROJECT ${GAME_PROJECT_NAME} 
)

add_executable(${GAME_PROJECT_NAME}

	src/Game.hpp
	src/Game.cpp

)

add_subdirectory(Engine)
target_link_libraries(${GAME_PROJECT_NAME} Engine)

add_custom_command(TARGET ${GAME_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/assets
                $<TARGET_FILE_DIR:${GAME_PROJECT_NAME}>/assets)

