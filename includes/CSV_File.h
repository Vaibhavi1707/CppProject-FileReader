#ifndef CSV_FILE_H_
#define CSV_FILE_H_

#include"File.h"
#include<vector>
#include <string>
#include<string.h>

using namespace std;


class CSV_File : public File
{
protected:
    int row, col;
    vector < vector <string> >  arr;
    string fileName, output;
public:
    CSV_File(string file)
    {
        fileName = file;
        output = "output.csv";
    }
    static bool isFloat(string myString);
    bool read();
    bool write();
};

#endif