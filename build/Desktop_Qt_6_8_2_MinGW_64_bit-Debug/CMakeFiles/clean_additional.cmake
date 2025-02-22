# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LifeForm_Simulation_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LifeForm_Simulation_autogen.dir\\ParseCache.txt"
  "LifeForm_Simulation_autogen"
  )
endif()
