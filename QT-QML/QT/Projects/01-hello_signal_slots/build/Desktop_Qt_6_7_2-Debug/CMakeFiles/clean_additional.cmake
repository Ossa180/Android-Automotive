# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/signalANDslot_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/signalANDslot_autogen.dir/ParseCache.txt"
  "signalANDslot_autogen"
  )
endif()
