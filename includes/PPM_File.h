#include <string>

#include "File.h"

class PPM_File : public File
{
private:
    std::string filename;
public:
    PPM_File(std::string filename): filename(filename) {};

    bool read();
    bool modify();
    bool write();

    ~PPM_File() {};
};