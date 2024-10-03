
#define _CRT_SECURE_NO_WARNINGS

#include "largebucket.h"
#include "simple_unique_ptr.h"

// 301
// Sieve of Erastothenes


#include <vector>
#include <deque>
#include <string>

#include <fstream>
#include <chrono>
#include <ctime>

class Image
{
public:

    std::string data{};
};

struct ImageMeta
{
    std::string path{};
};

struct sector
{
    int row;
    int col;
};

class ImageProcessor
{
public:
    ImageProcessor(int numRow, int numCol) :
        images(numRow, std::vector<ImageMeta>(numCol, ImageMeta{}))
    {
        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                accesed.push_back(images[i][j]);
            }
        }
    };

    void update(sector index, Image* img)
    {
        if (std::string& path = images[index.row][index.col].path; !path.empty())
        {
            eraceImage(path);
            path = std::string();
        }

        images[index.row][index.col].path = saveImage(img);
    }

    Image* fetch(sector index) const
    {
        Image* res{};
        if(const std::string& path = images[index.row][index.col].path; !path.empty())
        {
            res = loadImage(path);
        }

        return res;
    }



private:
    std::string saveImage(Image* img) const
    {
        auto now = std::chrono::system_clock::now();
        auto now_t = std::chrono::system_clock::to_time_t(now);
        std::string res = std::ctime(&now_t);

        std::ofstream fd;
        fd.open(res);
        if (!fd)
        {
            int x;
            x = 3;
        }
        
        fd << img->data;
        fd.close();

        return res;
    }

    void eraceImage(std::string path) const
    {}

    Image* loadImage(std::string path) const
    {
        return nullptr;
    }

    std::vector<std::vector<ImageMeta>> images;
    std::deque<ImageMeta> accesed;
};

int main(int argc, char** argv)
{
    ImageProcessor proce{ 10, 10 };
    
    Image img1{"someimage"};
    proce.update({2 , 1}, &img1);

    Image img2{ "someimage" };
    proce.update({ 3 , 2 }, &img2);
    
    return 0;
}