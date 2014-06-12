#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sh_MT" for configuration "Debug"
set_property(TARGET sh_MT APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sh_MT PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/components/lib/sh_MT.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "RTC110d;coil110d;omniORB416_rtd;omniDynamic416_rtd;omnithread34_rtd;advapi32;ws2_32;mswsock;mclmcrrt.lib;shMT.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/components/bin/sh_MT.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS sh_MT )
list(APPEND _IMPORT_CHECK_FILES_FOR_sh_MT "${_IMPORT_PREFIX}/components/lib/sh_MT.lib" "${_IMPORT_PREFIX}/components/bin/sh_MT.dll" )

# Import target "sh_MTComp" for configuration "Debug"
set_property(TARGET sh_MTComp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sh_MTComp PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/components/bin/sh_MTComp.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS sh_MTComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_sh_MTComp "${_IMPORT_PREFIX}/components/bin/sh_MTComp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
