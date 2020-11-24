#include"CSV_File.h"

class Task8 : public CSV_File
{
public:
    void modify();
    int c1, c2;
    vector<bool> mD;
    void fillMetaData();
    void bubble2();
    void bubble1();
    Task8(string file, int c1, int c2) : CSV_File(file)
    {
        Task8::c1 = c1;
        Task8::c2 = c2;
    }
};
