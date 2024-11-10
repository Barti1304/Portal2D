cmake_minimum_required(VERSION 3.25)

project(Portal2D)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCE "src/**.cpp")

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)
find_package(box2d REQUIRED)

add_executable(Portal2D ${SOURCE})
set_target_properties(Portal2D PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}
)

target_link_libraries(Portal2D
	glfw
	glad::glad
	glm::glm
	box2d::box2d
)
