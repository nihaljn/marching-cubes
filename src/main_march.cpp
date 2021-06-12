#include <iostream>
#include <string>

#include "generator.hpp"
#include "marching_cubes.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[])
{
    std::string file_in = argv[1];
    std::string file_out = argv[2];
    float isovalue = std::stof(argv[3]);

    MarchingCubes handle = MarchingCubes();
    int max = 400;
    Generator g = Generator(max);
    // auto field = g.generate_sphere(32, 32, 32, 30);
    std::cout << "Getting scalar field... "; fflush(stdout);
    // file must have each line as i, j, k, functional_value
    auto field = g.read_grid_from_file(file_in.c_str());
    std::cout << "Done.\n"; fflush(stdout);

    std::cout << "Triangulating using marching cubes... "; fflush(stdout);
    auto triangles = handle.triangulate_field(field, isovalue);
    std::cout << "Done.\n"; fflush(stdout);

    std::string filename = "output_healthy_brain" + std::to_string(isovalue) + ".ply";
    std::cout << "Number of triangles: " << triangles.size() << "\n";
    write_to_ply(triangles, file_out.c_str());
}