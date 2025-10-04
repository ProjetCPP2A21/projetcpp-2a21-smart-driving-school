# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\apprenant_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\apprenant_autogen.dir\\ParseCache.txt"
  "apprenant_autogen"
  )
endif()
