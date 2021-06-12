#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "types.hpp"
#include <vector>

class Generator
{
    public:
        int GRID_MAX;

        Generator(int max);

        /**
         * @brief returns a random number between -1.0 and 1.0
         * @return float 
         */
        float get_random_number();
        std::vector<std::vector<std::vector<float>>> generate_random_grid();
        std::vector<std::vector<std::vector<float>>> generate_sphere(float centerX, float centerY, float centerZ, float radius);
        std::vector<std::vector<std::vector<float>>> generate_nested_spheres();
        std::vector<std::vector<std::vector<float>>> read_grid_from_file(const char* path);
};

#endif