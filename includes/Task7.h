#include "PPM_File.h"

class Task7 : public PPM_File
{
private:
    std::vector <int> greyscale;

public:
    Task7(std::string filename) : PPM_File(filename) {};
    ~Task7() {};

    bool modify();
};
