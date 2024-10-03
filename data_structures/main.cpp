
#include <vector>

#include "array_list.h"
#include "list.h"

using namespace std;

struct Point
{
    int x;
    int y;
};

int main(int argc, char** argv)
{
    //std::byte data[2 * sizeof(Point)];
    //new(&data[0 * sizeof(Point)]) Point{1 ,2 };
    //new(&data[1 * sizeof(Point)]) Point{3 , 4};
    //Point* p3 = reinterpret_cast<Point*>(data);

    Array<Point> arr;
    
    Point a{ 1, 2 };
    Point b{ 3, 4 };

    arr.push_back(a);
    arr.push_back(b);

    for (auto p : arr)
    {
        int x;
        x = 3;
    }

    return 0;
}