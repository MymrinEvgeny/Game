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
	
	src/Utils/Logger.hpp
	src/Utils/Logger.cpp
	
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





