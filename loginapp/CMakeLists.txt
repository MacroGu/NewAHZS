cmake_minimum_required(VERSION 2.8.9)
project(loginapp)
 
include_directories(./ ../common ../include ../wepoll/include ../cellapp ../baseapp ../lua)
link_directories(../libs/mysql ../libs/linux)

FILE(GLOB CELLAPP_FILES 
	../cellapp/entity_cell.cpp
	../cellapp/entity_cell.h
	../cellapp/aoi.cpp
	../cellapp/aoi.h
	../cellapp/lua_cell.cpp
	../cellapp/lua_cell.h
	../cellapp/space.cpp
	../cellapp/space.h
	../cellapp/world_cell.cpp
	../cellapp/world_cell.h	
)
source_group(cellapp FILES ${CELLAPP_FILES} )

FILE(GLOB BASEAPP_FILES 
	../baseapp/entity_base.cpp
	../baseapp/entity_base.h
	../baseapp/lua_base.cpp
	../baseapp/lua_base.h
	../baseapp/world_base.cpp
	../baseapp/world_base.h	
)
source_group(baseapp FILES ${BASEAPP_FILES} )

source_group(loginapp FILES ${LOGINAPP_FILES} )

FILE(GLOB SOURCE_FILES "./*.cpp" "./*.h")
source_group(src FILES ${SOURCE_FILES} )

# Target
add_executable (loginapp
	${CELLAPP_FILES}
	${BASEAPP_FILES}
	${SOURCE_FILES}
)

if(MSVC)
	target_link_libraries(loginapp common tinyxml hiredis lua wepoll libmysql ws2_32)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS -D_WINSOCK_DEPRECATED_NO_WARNINGS)
else()
	target_link_libraries(loginapp common tinyxml hiredis lua mysqlclient uuid dl m libssl.a libcrypto.a)
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread")
	ADD_DEFINITIONS(-D__RELOGIN -D_CRT_SECURE_NO_WARNINGS)
endif()
