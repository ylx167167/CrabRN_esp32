# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/bootloader/subproject"
  "F:/project/crab-robot/software/esp32/CrabRN/build/bootloader"
  "F:/project/crab-robot/software/esp32/CrabRN/build/bootloader-prefix"
  "F:/project/crab-robot/software/esp32/CrabRN/build/bootloader-prefix/tmp"
  "F:/project/crab-robot/software/esp32/CrabRN/build/bootloader-prefix/src/bootloader-stamp"
  "F:/project/crab-robot/software/esp32/CrabRN/build/bootloader-prefix/src"
  "F:/project/crab-robot/software/esp32/CrabRN/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "F:/project/crab-robot/software/esp32/CrabRN/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "F:/project/crab-robot/software/esp32/CrabRN/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
