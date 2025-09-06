# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-src"
  "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-build"
  "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix"
  "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/tmp"
  "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp"
  "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src"
  "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspaces/DataStructures/Lab1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
