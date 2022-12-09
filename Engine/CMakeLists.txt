cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

set(ENGINE_PROJECT_NAME Engine)
project(${ENGINE_PROJECT_NAME})

add_library(${ENGINE_PROJECT_NAME} STATIC
	src/Engine.hpp
	
	src/Core/EntryPoint.cpp
	src/Core/Window.hpp
	src/Core/Window.cpp
	src/Core/Application.hpp
	src/Core/Application.cpp
	src/Core/ResourceLoader.hpp
	src/Core/ResourceLoader.cpp
	
	src/Graphics/Renderer.hpp
	src/Graphics/Renderer.cpp
	src/Graphics/ShaderProgram.hpp
	src/Graphics/ShaderProgram.cpp
	src/Graphics/VertexArray.hpp
	src/Graphics/VertexArray.cpp
	src/Graphics/ArrayBuffer.hpp
	src/Graphics/ArrayBuffer.cpp
	src/Graphics/Vertex.hpp
	src/Graphics/Vertex.cpp
	src/Graphics/ElementArrayBuffer.hpp
	src/Graphics/ElementArrayBuffer.cpp
	
	src/Utils/Logger.hpp
	src/Utils/Logger.cpp
	src/Utils/FileSystem.hpp
	src/Utils/FileSystem.cpp
)
target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC src)


# glfw
set(GLFW_BUILD_DOCS 	OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS 	OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glfw)

# glm
add_subdirectory(deps/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glm)

# glad
# --------------------
add_library(glad STATIC
	deps/glad/include/glad/glad.h 
	deps/glad/src/glad.c
)
target_include_directories(glad PUBLIC deps/glad/include)
# --------------------
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glad)

# DevIL
cmake_path(SET IL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/deps/DevIL/include")
cmake_path(SET IL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/deps/DevIL/lib/x64/Release/DevIL.lib")
cmake_path(SET ILU_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/deps/DevIL/lib/x64/Release/ILU.lib")
cmake_path(SET ILUT_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/deps/DevIL/lib/x64/Release/ILUT.lib")
find_package(DevIL)
message("-- DevIL_FOUND: ${DevIL_FOUND}")
message("-- DevIL_ILUT_FOUND: ${DevIL_ILUT_FOUND}")
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC DevIL::IL DevIL::ILU DevIL::ILUT)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/deps/DevIL/lib/x64/Release/DevIL.dll
	${CMAKE_CURRENT_SOURCE_DIR}/deps/DevIL/lib/x64/Release/ILU.dll
	${CMAKE_CURRENT_SOURCE_DIR}/deps/DevIL/lib/x64/Release/ILUT.dll
	DESTINATION ${CMAKE_BINARY_DIR}/Debug)

