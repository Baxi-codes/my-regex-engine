cmake_minimum_required(VERSION 3.5)
project(myregex)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/includes)

# Add source files
set(SOURCES
    lib/dfa/dfa.cpp
    lib/regex/Lexer.cpp
    lib/regex/AST.cpp
    lib/regex/Parser.cpp
    # tests/dfa_test.cpp
    # tests/regex_lexer_test.cpp
    # tests/regex_ast_test.cpp
    tests/regex_parser_test.cpp
)

# Add executable
add_executable(myregex ${SOURCES})