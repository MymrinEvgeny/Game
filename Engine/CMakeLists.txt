# ----- src -----
# Engine
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

# ----- deps -----
# glfw
set(GLFW_BUILD_DOCS 	OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS 	OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} glfw)

# glm
add_subdirectory(deps/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} glm)

# glad
############
add_library(glad STATIC 
	deps/glad/include/glad/glad.h 
	deps/glad/src/glad.c
)
target_include_directories(glad PUBLIC deps/glad/include)
############
target_link_libraries(${ENGINE_PROJECT_NAME} glad)





