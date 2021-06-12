#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "types.hpp"

void write_to_ply(std::vector<std::vector<Point>> &triangles, const char* path);
void write_triangles_to_file(std::vector<std::vector<Point>> triangles, const char* path);

#endif