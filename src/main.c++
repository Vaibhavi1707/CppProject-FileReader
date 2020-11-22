// #include <bits/stdc++.h>
// #include <iostream>
// // #include "FileReader.h"
// #include "../includes/TXT_File.h"
//
// using namespace std;
//
// int main(){
//     //taking fileName from the user
//     string filename;
//     cin>>filename;
//
//     //assign output filename
//     string outputfile;
//     outputfile = "Documentstatic-"+filename;
//
//     vector<string> format;
//
//     stringstream s(filename);
//     string sub;
//
//     while(getline(s,sub,'.')){
//         format.push_back(sub);
//     }
//
//     int n=format.size();
//
//     if(format[n-1]=="txt"){
//         //making class object
//         FileReader f(filename);
//         //to process input file
//         f.read();
//         //to write in outputfile
//         f.write(outputfile);
//
//         //printing on terminal
//         cout<<f.getNumLines()<<" "<<f.getNumWords()<<" "<<f.getNumCharSpace()<<" "<<f.getNumChar()<<" "<<f.getBytes()<<endl;
//     }
//
//     else if(format[n-1] == "csv"){
//         //make obj and calls
//     }
//
//     else if(format[n-1] == "ppm"){
//         //make obj and calls
//     }
//
//     return 0;
// }
