#include"CSV_File.h"

class CSVSort : public CSV_File
{
public:
    void modify();
    int c1,c2;
    vector<bool> mD;
    int fillMetaData();
    void bubble2();
    void bubble1(); 
    CSVSort(string file,int c1,int c2) : CSV_File(file)
    {
	 CSVSort::c1 = c1;
	 CSVSort::c2 = c2; 
    }
    //bool compareVector(vector <string> i1, vector <string> i2);
};
