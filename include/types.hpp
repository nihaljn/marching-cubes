#ifndef TYPES_H
#define TYPES_H

#include <map>
#include <vector>

struct Point
{
    float x;
    float y;
    float z;

    bool operator<(const Point& rhs) const
    {
        if (x != rhs.x)
            return x < rhs.x;
        if (y != rhs.y)
            return y < rhs.y;
        return z < rhs.z;
    }
};

struct GridCell
{
    Point vertex[8];
    float value[8];
};

struct VertexContainer
{
    std::map<Point, int> vertexMap;
    std::vector<std::vector<int>> triangles;
};

#endif