# @file:	CMakeLists.txt
# @author:	Jacob Xie
# @date:	2025/12/07 12:18:14 Sunday
# @brief:

cmake_minimum_required(VERSION 3.20)
project(fb-cpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###################################################################################################


# Find FlatBuffers package
find_package(flatbuffers REQUIRED PATHS /opt/flatbuffers)

# Add your main executable
add_executable(monster fb-cpp/monster.cpp)

# Link against FlatBuffers library
target_link_libraries(monster flatbuffers::flatbuffers)
