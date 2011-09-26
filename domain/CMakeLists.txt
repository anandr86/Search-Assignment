
add_executable(dfs quiz1q1abcd.cpp)
add_executable(best_first quiz1q2.cpp)

include_directories(${SearchAssignment_SOURCE_DIR}/core ${SearchAssignment_SOURCE_DIR}/search .)
target_link_libraries(dfs core search)
target_link_libraries(best_first core search)