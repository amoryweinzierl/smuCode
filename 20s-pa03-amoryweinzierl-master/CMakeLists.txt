cmake_minimum_required(VERSION 3.12)
project(p03)
set (EXE_NAME project3)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g")

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "graph_1.txt")
set (input02 "graph_2.txt")
set (input03 "graph_3.txt")
set (input04 "graph_4.txt")
set (input05 "graph_5.txt")
set (input06 "graph_6.txt")
set (input07 "graph_7.txt")
set (input08 "graph_8.txt")
set (input09 "graph_9.txt")
set (input10 "graph_10.txt")

set (output01 "output_1.txt")
set (output02 "output_2.txt")
set (output03 "output_3.txt")
set (output04 "output_4.txt")
set (output05 "output_5.txt")
set (output06 "output_6.txt")
set (output07 "output_7.txt")
set (output08 "output_8.txt")
set (output09 "output_9.txt")
set (output10 "output_10.txt")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04 input05 input06 input07 input08 input09 input10 input11 output01 output02 output03 output04 output05 output06 output07 output08 output09 output10)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp DS.h LLO.h kruskal.h edge.h graph_1.txt graph_2.txt graph_3.txt graph_4.txt graph_5.txt graph_6.txt graph_7.txt graph_8.txt graph_9.txt graph_10.txt output_1.txt output_2.txt output_3.txt output_4.txt output_5.txt output_6.txt output_7.txt output_8.txt output_9.txt output_10.txt)