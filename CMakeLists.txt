cmake_minimum_required( VERSION 3.13 )

project( CommandLineParser )

add_executable( clptest src/Main.cc )
target_include_directories( clptest PUBLIC include )
