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
    string fileName;
    char output[100];
public:
    CSV_File(string file)
    {
      fileName = file;
      strcpy(output,"output.csv");
      row = getNoOfRows();
      col = getNoOfCols();
    }
    int countDelimeters(char c[], char input[]);
    int fill();
    int GetColumnNumber(char name[]);
    int getNoOfRows();
    int getNoOfCols();
    static bool isFloat(string myString);
    //int fillMetaData();
    bool read();
    virtual void modify() = 0;
    bool write();
    //virtual bool compareVector(vector <string> i1, vector <string> i2)=0;
}; 

