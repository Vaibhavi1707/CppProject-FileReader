#include <bits/stdc++.h>
#include "../includes/TXT_File.h"
#include "../includes/GreyScale.h"
#include "../includes/brg.h"
#include"../includes/CSVSort.h"

using namespace std;

#define RESET "\033[0m\n"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define MAGENTA "\033[1;35m"

string get_extension(string filename) {
    vector<string> format;

    stringstream s(filename);
    string sub;

    while(getline(s,sub,'.')){
        format.push_back(sub);
    }

    return format[format.size() - 1];
}

int main(){
    bool over = false;

    while (! over) {
        //taking fileName from the user
        cout << CYAN << "Enter the filename to be operated on" << RESET << endl;
        cout << MAGENTA;
        string filename;
        cin>>filename;
        cout << RESET;

        //assign output filename
        string extension = get_extension(filename);

        if(extension == "txt") {
            string outputfile = "Documentstatic-"+filename;

            //making class object
            TXT_File f(filename);
            //to process input file
            f.read();
            //to write in outputfile
            f.write();

            //printing on terminal
            cout<<f.getNumLines()<<" "<<f.getNumWords()<<" "<<f.getNumCharSpace()<<" "<<f.getNumChar()<<" "<<f.getBytes()<<endl;
            return 0;
        }

        else if(extension == "csv"){
            cout << YELLOW << "You've entered a csv file" << endl;
            cout << "Please enter 1 for sorting columns in a csv file" << endl;
            cout << "Please enter 2 for converting ppm file to a pgm file" << RESET << endl;
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << YELLOW << "Enter the columns" << endl;
                cout << YELLOW << "Coloumn 1: " << RESET << endl;
                string c1, c2;
                cin >> c1;
                cout << YELLOW << "Coloumn 2: " << RESET << endl;
                CSVSort c(filename,c.GetColumnNumber(c1) - 1,c.GetColumnNumber(c2) - 1);
                c.read();
                c.modify();
                c.write();
            }

            else if (choice == 2) {

            }

            else {
                cout << RED << "ERROR: Wrong choice. Aborting.." << RESET << endl;
            }
        }

        else if(extension == "ppm"){
            cout << YELLOW << "You've entered a ppm file" << endl;
            cout << "Please enter 1 for converting rgb ppm file to brg ppm file" << endl;
            cout << "Please enter 2 for converting ppm file to a pgm file" << RESET << endl;

            int choice;
            cin >> choice;

            if (choice == 1) {
                ppm p(filename);
                if (p.read()) {
                    p.write();
                    cout << GREEN << "File written successfully" << RESET << endl;
                } else {
                    cout << RED << "ERROR: Bad file format. Aborting.." << RESET << endl;
                }
            }

            else if (choice == 2) {
                GreyScale ppm_file(filename);

                if (! ppm_file.read()) {
                    cout << RED << "ERROR: Bad file format. Aborting.." << RESET << endl; // red
                }

                ppm_file.modify();

                cout << GREEN << "File written successfully" << RESET << endl;
            }

            else {
                cout << RED << "ERROR: Wrong choice. Aborting.." << RESET << endl;
            }
        }

        else {
            cout << RED << "ERROR: Bad extension. File read failed. Aborting.." << RESET << endl;
        }

        cout << "To continue enter yes" << endl;

        string to_continue;
        cin >> to_continue;

        transform(to_continue.begin(), to_continue.end(), to_continue.begin(), ::tolower);
        over = to_continue != "yes";
    }

    cout << CYAN << "Thanks for the demo :)" << RESET << endl;

    return 0;
}
