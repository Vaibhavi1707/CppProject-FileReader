#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class File
{
public:
    virtual void read() = 0;
    virtual void write(string content_to_write, int size) = 0;
    virtual void write(string outputfile) = 0;
};
