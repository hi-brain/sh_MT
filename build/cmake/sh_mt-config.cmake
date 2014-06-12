# sh_MT CMake config file
#
# This file sets the following variables:
# sh_MT_FOUND - Always TRUE.
# sh_MT_INCLUDE_DIRS - Directories containing the sh_MT include files.
# sh_MT_IDL_DIRS - Directories containing the sh_MT IDL files.
# sh_MT_LIBRARIES - Libraries needed to use sh_MT.
# sh_MT_DEFINITIONS - Compiler flags for sh_MT.
# sh_MT_VERSION - The version of sh_MT found.
# sh_MT_VERSION_MAJOR - The major version of sh_MT found.
# sh_MT_VERSION_MINOR - The minor version of sh_MT found.
# sh_MT_VERSION_REVISION - The revision version of sh_MT found.
# sh_MT_VERSION_CANDIDATE - The candidate version of sh_MT found.

message(STATUS "Found sh_MT-1.0.0")
set(sh_MT_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(sh_MT_INCLUDE_DIRS
#    "C:/Program Files/sh_MT/include/sh_mt-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(sh_MT_IDL_DIRS
#    "C:/Program Files/sh_MT/include/sh_mt-1/idl")
set(sh_MT_INCLUDE_DIRS
    "C:/Program Files/sh_MT/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(sh_MT_IDL_DIRS
    "C:/Program Files/sh_MT/include//idl")


if(WIN32)
    set(sh_MT_LIBRARIES
        "C:/Program Files/sh_MT/components/lib/sh_mt.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(sh_MT_LIBRARIES
        "C:/Program Files/sh_MT/components/lib/sh_mt.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(sh_MT_DEFINITIONS ${<dependency>_DEFINITIONS})

set(sh_MT_VERSION 1.0.0)
set(sh_MT_VERSION_MAJOR 1)
set(sh_MT_VERSION_MINOR 0)
set(sh_MT_VERSION_REVISION 0)
set(sh_MT_VERSION_CANDIDATE )

