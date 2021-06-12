#include "generator.hpp"
#include "types.hpp"
#include <fstream>
#include <iostream>
#include <vector>

float Generator::get_random_number()
{
	float randomNumber = (float)rand() / RAND_MAX;
	randomNumber -= 0.5;
	randomNumber *= 2.0;

	return randomNumber;
}

Generator::Generator(int max)
{
    GRID_MAX = max;
}

std::vector<std::vector<std::vector<float>>> Generator::generate_random_grid()
{
	std::vector<std::vector<std::vector<float>>> scalarFunction(GRID_MAX, std::vector<std::vector<float>>(GRID_MAX, std::vector<float>(GRID_MAX)));

	for (int i = 0; i < GRID_MAX; i++)
		for (int j = 0; j < GRID_MAX; j++)
			for (int k = 0; k < GRID_MAX; k++)
				scalarFunction[i][j][k] = get_random_number();

	return scalarFunction;
}


std::vector<std::vector<std::vector<float>>> Generator::generate_sphere(
    float centerX, float centerY, float centerZ, float radius)
{
	std::vector<std::vector<std::vector<float>>> scalarFunction(GRID_MAX, std::vector<std::vector<float>>(GRID_MAX, std::vector<float>(GRID_MAX)));

	for (int k = 0; k < GRID_MAX; k++)
		for (int j = 0; j < GRID_MAX; j++)
			for (int i = 0; i < GRID_MAX; i++)
            {
				int val = (centerX-i)*(centerX-i) + (centerY-j)*(centerY-j) + (centerZ-k)*(centerZ-k);

				if (val <= radius*radius)
					scalarFunction[i][j][k] = -1;
				else
					scalarFunction[i][j][k] = 1;
            }

	return scalarFunction;
}

std::vector<std::vector<std::vector<float>>> Generator::generate_nested_spheres()
{
	std::vector<std::vector<std::vector<float>>> scalarFunction(GRID_MAX, std::vector<std::vector<float>>(GRID_MAX, std::vector<float>(GRID_MAX)));

	int r1 = 50, cx1 = 64, cy1 = 64, cz1 = 64;
	int r2 = 5, cx2 = 64, cy2 = 64, cz2 = 64;

	for (int i = 0; i < GRID_MAX; i++)
	{
		for (int j = 0; j < GRID_MAX; j++)
		{
			for (int k = 0; k < GRID_MAX; k++)
			{
				int val1 = (cx1-i)*(cx1-i) + (cy1-j)*(cy1-j) + (cz1-k)*(cz1-k);
				int val2 = (cx2-i)*(cx2-i) + (cy2-j)*(cy2-j) + (cz2-k)*(cz2-k);
				if (val1 <= r1*r1 && val2 > r2*r2)
				{
					scalarFunction[i][j][k] = -1;
				}
				else
					scalarFunction[i][j][k] = 1;
			}
		}
	}
	return scalarFunction;
}

std::vector<std::vector<std::vector<float>>> Generator::read_grid_from_file(const char* path)
{
	std::vector<std::vector<std::vector<float>>> scalarFunction(GRID_MAX, std::vector<std::vector<float>>(GRID_MAX, std::vector<float>(GRID_MAX)));
	
	int i, j, k;
	float value;
	FILE* inputFile = fopen(path, "r");
	while (fscanf(inputFile, "%d %d %d %f", &i, &j, &k, &value) != EOF)
		scalarFunction[i][j][k] = value;
	
	return scalarFunction;
}