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
class ppm:public File{

    private:
      int width;
      int height;
    public:
      ppm(std::string file_name);
      std::string file_name;
      std::string version;
      int maxcolor; 
      void setwidth(int w);
      int getheight();
      void setheight(int h);
      int getwidth();
      void setversion(std::string s);
      std::string getversion();
      void setmaxcolor(int c);
      friend void read(std::string file_name,ppm &p);
      RGB **image;
      bool write();
      bool read();
      void setimage(RGB **im);
      
      ppm(const ppm &p);

};
#endif
