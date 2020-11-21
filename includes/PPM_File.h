#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

#include "File.h"

class PPM_File : public File
{
private:
    std::string _filename;
    std::string _magic_no;
    int _width;
    int _height;
    int _max_color_val;

    bool extract_header(std::vector <std::string>& content);
    bool parse_rgb_values(std::vector <std::string> content);

protected:
    std::vector <int> content;
    std::vector <std::tuple<int, int, int>> _rgb_pixels;
    bool write();

public:
    PPM_File(std::string filename): _filename(filename) {};

    bool read();

    ~PPM_File() {};
};