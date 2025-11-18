cmake_minimum_required(VERSION 3.20)
project(KVParser)

add_library(KVParser SHARED)

target_compile_features(KVParser PRIVATE cxx_std_23)

target_sources(KVParser
  PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    src/interface/kv_lexer.cppm
    src/interface/kv_node.cppm
    src/interface/kv_parser.cppm
    src/interface/library.cppm
    src/interface/shared.cppm
    src/vkvparser.cppm
)

target_sources(KVParser
  PRIVATE
    src/implementation/library.cpp
    src/implementation/kv_node.cpp
    src/implementation/kv_lexer.cpp
    src/implementation/kv_parser.cpp
)

if(WIN32)
    target_compile_definitions(KVParser PRIVATE "LIBRARY_API=__declspec(dllexport)")
else()
    target_compile_definitions(KVParser PRIVATE "LIBRARY_API=")
endif()
