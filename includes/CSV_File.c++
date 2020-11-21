// Feel free to change the name of this class according to your convinience. 
// This class contains the concrete implementation of the base class File and it's methods.
//  read() -- reads the csv file
//  write() -- writes the csv file

#include "File.h"

class CSV_File : public File
{
private:
    /* data */
public:
    CSV_File(/* args */);
    ~CSV_File() {};

    bool read();
    bool write(/* WHatever type you want to pass here and int size */);
    // bool write(type_want_to_pass var, int size)
};
