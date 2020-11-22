#include <bits/stdc++.h>
#include <iostream>
#include "../includes/TXT_File.h"
#include "../includes/GreyScale.h"
using namespace std;

int main(){
    //taking fileName from the user
    string fileName,filename_Withpath,outputfile;
    cin>>fileName;
    //assign output fileName

    vector<string> format;

    stringstream s(fileName);
    string sub;

    while(getline(s,sub,'.')){
        format.push_back(sub);
    }

    int n=format.size();

    if(format[n-1]=="txt"){
        filename_Withpath = "../Test_files/Text_files/"+fileName;
        outputfile = "../Output_files/Text_files/new-"+fileName;

        //making class object
        TXT_File f(filename_Withpath, outputfile);
        //to process input file
        f.read();
        //to write in outputfile
        f.write();

        //printing on terminal
        cout<<f.getNumLines()<<" "<<f.getNumWords()<<" "<<f.getNumCharSpace()<<" "<<f.getNumChar()<<" "<<f.getBytes()<<endl;
        return 0;
    }

    // else if(format[n-1] == "csv"){
    //     //make obj and calls
    // }
    //
    // else if(format[n-1] == "ppm"){
    //     GreyScale ppm_file(filename_Withpath);
    //
    //     if (! ppm_file.read()) {
    //         cout << "ERROR: Wrong File path. Aborting.." << endl;
    //         return 1;
    //     }
    //
    //     ppm_file.modify();
    //
    //     cout << "File written successfully" << endl;
    //
    //     return 0;
    // }
    //
    // else {
    //     std::cout << "ERROR: Bad extension. File read failed. Aborting.." << endl;
    //     return 1;
    // }

    return 0;
}
