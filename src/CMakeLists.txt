# We want shared libraries (and modules) without any prefix in name
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")

#####################################################################

# Add include directories
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/common
	${OGS_SDK_PATH}
	${OGS_SDK_PATH}/common
	${OGS_SDK_PATH}/engine
	${OGS_SDK_PATH}/pm_shared
	${OGS_SDK_PATH}/public
	${OGS_SDK_PATH}/next
)

#####################################################################

# Add subdirectories

add_subdirectory(pm_shared)

add_subdirectory(game)

if(${OPENLAMBDA_TARGET_ENGINE} STREQUAL "Legacy")
	add_subdirectory(dlls)
endif()

add_subdirectory(dedicated)

# If not building as dedicated server then build these modules too
if(NOT OGS_DEDICATED)
	if(${OPENLAMBDA_TARGET_ENGINE} STREQUAL "Legacy")
		add_subdirectory(cl_dll)
	elseif(${OPENLAMBDA_TARGET_ENGINE} STREQUAL "Next")
		add_subdirectory(gameui)
	endif()

	add_subdirectory(launcher)
endif()