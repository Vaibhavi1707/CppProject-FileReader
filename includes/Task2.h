#ifndef PPM_H
#define PPM_H
#include<string>
#include "../includes/File.h"
using namespace std;
struct RGB{
    int r;
    int g;
    int b;
};
class Task2:public File{

    private:
      int width;
      int height;

      std::string file_name;
      std::string version;
      std::string output_file;
      int maxcolor;
      RGB **image;

    public:
      Task2(std::string fname);
      Task2(const Task2 &p);

      void setwidth(int w);
      void setheight(int h);
      void setversion(std::string s);
      void setmaxcolor(int c);
      void setimage(RGB **im);
      friend void read(std::string file_name,Task2 &p);

      int getheight();
      int getwidth();

      std::string getversion();

      bool write();
      bool read();


};
#endif
