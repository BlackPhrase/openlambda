project(ogs-cl_dll)

#####################################################################

# Find the required packages

if(OGS_USE_SDL)
	find_package(SDL2 REQUIRED)
endif()

#####################################################################

add_library(${PROJECT_NAME} MODULE)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SOURCES)

target_sources(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "client"
)

target_link_libraries(${PROJECT_NAME} ogs-tier1 ogs-pm_shared ogs-mathlib ogs_game_shared-client ogs-game-client)

if(WIN32)
	target_link_libraries(${PROJECT_NAME} winmm) #joyGetPosEx
endif()