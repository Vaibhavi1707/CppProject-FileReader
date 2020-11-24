//#include "ppm.h"
#include<string.h>
#include<fstream>
#include "../includes/brg.h"
ppm::ppm(std::string file_name)
{
    this->file_name=file_name;
}
ppm::ppm(const ppm &p)
{
    this->file_name=p.file_name;
}
void ppm:: setwidth(int w)
{
    width=w;
}
void ppm::setheight(int h)
{
    height=h;
}
int ppm::getheight()
{
    return height;
}
int ppm::getwidth()
{
    return width;
}
void ppm::setmaxcolor(int c)
{
    maxcolor=c;
}
void ppm::setversion(std::string s)
{
    version=s;
}
std::string ppm::getversion()
{
    return version;
}
void ppm:: setimage(RGB **im)
{
    image=im;
}
bool ppm:: read()
{
    ifstream input(this->file_name);
    int color,i,j,width,height,color1;
    char ver[3];
    string version;
    if (input.is_open())
    {
        input.read(ver,2);
        version=ver;
        setversion(version);
        input>>width;
        setwidth(width);
        input>>height;
        setheight(height);
        input>>color;
        setmaxcolor(color);
        input.read(ver,1);
        RGB ** image;
        image= (RGB **) malloc(height* sizeof(RGB *));
        for (int i=0;i<height;i++)
        {
           image[i]=(RGB *)malloc(width * sizeof(RGB));
        }
        if (version=="P3")
        {
            for (i=0;i<height;i++)
            {
                for(j=0;j<width;j++)
                {
                   input>>color1;
                   image[i][j].r=color1;
                    input>>color1;
                   image[i][j].g=color1;
                    input>>color1;
                   image[i][j].b=color1;
                }
            }
        }
        setimage(image);
        input.close();
        return true;
    }
   return false;  
}
bool ppm:: write()
{
   std::ofstream fout(this->file_name);
   if (!fout.fail())
   {
      fout<<"P3\n";
      fout<<width<<" "<<height<<"\n";
      fout<<maxcolor<<'\n';
      for (int i=0;i<height;i++)
      {
          for(int j=0;j<width;j++)
          {
              fout<<image[i][j].b<<" ";
              fout<<image[i][j].r<<" ";
              fout<<image[i][j].g<<" ";
              fout<<"  ";
          }
          fout<<'\n';
      }
    return true;
    }
    fout.close(); 
    // I added the cout line to check whether it's able to write or not.
    cout << "Hello World" << endl;
   return false;
    //   fout.close();  
}
