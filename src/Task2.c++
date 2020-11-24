#include<string.h>
#include<fstream>
#include "../includes/Task2.h"

Task2::Task2(std::string fname)
{
    file_name = "../Test_files/Task2_files/"+fname;
    output_file = "../Output_files/Task2_files/new-"+fname;

    this->file_name=file_name;
}
Task2::Task2(const Task2 &p)
{
    this->file_name=p.file_name;
}
void Task2:: setwidth(int w)
{
    width=w;
}
void Task2::setheight(int h)
{
    height=h;
}
int Task2::getheight()
{
    return height;
}
int Task2::getwidth()
{
    return width;
}
void Task2::setmaxcolor(int c)
{
    maxcolor=c;
}
void Task2::setversion(std::string s)
{
    version=s;
}
std::string Task2::getversion()
{
    return version;
}
void Task2:: setimage(RGB **im)
{
    image=im;
}
bool Task2:: read()
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
        cout << width;
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
bool Task2:: write()
{
   std::ofstream fout(this->output_file);
   cout << width << " " << height << " " << maxcolor << endl;
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
    // cout << "Hello World" << endl;
   return false;
    //   fout.close();
}
