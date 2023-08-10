# CMakeLists.txt

set(PACKAGE_VERSION "0.00")

cmake_policy (SET CMP0115 NEW)

include(cmake/config.cmake)

set(gha_sandbox_SRCS
  gha_sb.c
  config.h
  )

add_executable(gha_sb ${gha_sandbox_SRCS})
target_compile_definitions(gha_sb PRIVATE -DHAVE_CONFIG_H -DWITH_SYSTEM_ICU)
#target_link_libraries(gha_sb icu)
target_include_directories(gha_sb
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )
