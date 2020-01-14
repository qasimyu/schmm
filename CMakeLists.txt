cmake_minimum_required(VERSION 3.0)
project(SCHMM)

SET(CMAKE_BUILD_TYPE Release)

#add_definitions(-std=c++11)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib)

include_directories (
	${SCHMM_SOURCE_DIR}/lib/bamtools/src
	${SCHMM_SOURCE_DIR}/lib/cnacaller
	${SCHMM_SOURCE_DIR}/lib/config
	${SCHMM_SOURCE_DIR}/lib/fastahack
	${SCHMM_SOURCE_DIR}/lib/genomedata
	${SCHMM_SOURCE_DIR}/lib/hmm
	${SCHMM_SOURCE_DIR}/lib/inputparser
	${SCHMM_SOURCE_DIR}/lib/kent/inc
	${SCHMM_SOURCE_DIR}/lib/mathfunc
	${SCHMM_SOURCE_DIR}/lib/matrix
	${SCHMM_SOURCE_DIR}/lib/model
	${SCHMM_SOURCE_DIR}/lib/mydefine
	${SCHMM_SOURCE_DIR}/lib/split
	${SCHMM_SOURCE_DIR}/lib/threadpool
)

add_executable(schmm src/schmm.cpp)

target_link_libraries(schmm mydefine)

SET_TARGET_PROPERTIES(schmm PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SCHMM_BINARY_DIR}/bin)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
	set_property(TARGET schmm PROPERTY COMPILE_OPTIONS "-pthread")
	set_property(TARGET schmm PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
	target_link_libraries(schmm "${CMAKE_THREAD_LIBS_INIT}")
endif()

INSTALL(TARGETS schmm
	RUNTIME DESTINATION bin
)
