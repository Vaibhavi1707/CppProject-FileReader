#include "PPM_File.h"

class GreyScale : public PPM_File
{
private:
    std::vector <int> greyscale;

public:
    GreyScale(std::string filename) : PPM_File(filename) {};
    ~GreyScale() {};

    bool modify();
};
