cmake_minimum_required(VERSION 3.13)
project(clogg)

enable_testing()
add_library(
    clogg
    "src/writer.cpp"
    "src/logger.cpp" 
)

add_executable(clogg_test test/main.cpp)
target_include_directories(clogg_test PUBLIC include)
target_link_directories(clogg_test PUBLIC build)
target_link_libraries(clogg_test clogg)

set_target_properties(
    clogg PROPERTIES
    CXX_STANDARD 17
    CXX_REQUIRED YES
)

target_include_directories(clogg PUBLIC include)
target_link_libraries(clogg clstl)