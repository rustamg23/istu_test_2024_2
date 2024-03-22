# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-src"
  "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-build"
  "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/rustam/Documents/GitHub/istu_test_2024_2/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
