# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "app\\CMakeFiles\\app_autogen.dir\\AutogenUsed.txt"
  "app\\CMakeFiles\\app_autogen.dir\\ParseCache.txt"
  "app\\app_autogen"
  "lib\\CMakeFiles\\lib_autogen.dir\\AutogenUsed.txt"
  "lib\\CMakeFiles\\lib_autogen.dir\\ParseCache.txt"
  "lib\\lib_autogen"
  )
endif()
