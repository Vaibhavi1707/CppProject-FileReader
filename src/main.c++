#include <bits/stdc++.h>
#include "../includes/Task4.h"
#include "../includes/Task7.h"
#include "../includes/Task2.h"
#include"../includes/CSVSort.h"
#include "../includes/task3.h"

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

void csv_transpose(string filename) {
    csvFile file_csv;

    fstream *file_input = new fstream();

    string line;
        string word;

    int i = 0;

        vector<vector<string>> Matrix;
        vector<vector<string>> TranspMatrix;

        file_input->open(filename);

        if(file_input->is_open())
    {
                while ( !file_input->eof() )
        {
                        vector<string> rows;
                        Matrix.push_back(rows);

            vector<string> strng;
                        TranspMatrix.push_back(strng);

            getline(*file_input, line);
                        stringstream get(line);

            while (getline(get, word,','))
            {
                                Matrix[i].push_back(word);
                        }
                        i++;
                }
        }

        csvFile file(Matrix);

    file_csv = file;

    vector<vector<string>> TransposeTable;

        int maximum = file_csv.getMatrix()[0].size();

        int temp = 0;

        i = 0;

        while(i < file_csv.getMatrix().size())
        {

                temp = file_csv.getMatrix()[i].size();

                if(maximum < temp)
                {
                        maximum = temp;
                }
                i = i + 1;
        }

        int j = 0;

        while(j < maximum)
        {
                vector<string> str;
                TransposeTable.push_back(str);
                j = j + 1;
        }

        int k = 0;
        int l = 0;

        while(k < file_csv.getMatrix().size())
        {
                l = 0;

                while(l < file_csv.getMatrix()[k].size())
                {
                        TransposeTable[l].push_back(file_csv.getMatrix()[k][l]);
                        l = l + 1;
                }
                k = k + 1;
        }

        file_csv.setTransMatrix(TransposeTable);

    fstream file_output;

        file_output.open("transposeFile.csv",ios::app | ios::out);

        i = 0;
        j = 0;

        while(i < file_csv.getTransMatrix().size())
        {
                j = 0;
                while(j < file_csv.getTransMatrix()[i].size()){

                        if(j == file_csv.getTransMatrix()[i].size()-1)
                        {
                                file_output<<file_csv.getTransMatrix()[i][j];
                                j = j + 1;
                        }

                        else
                        {
                                file_output<<file_csv.getTransMatrix()[i][j]<<",";
                                j = j + 1;
                        }
                }

                if(i == file_csv.getTransMatrix().size()-1)
                {
                        i = i + 1;
                        continue;
                }

                else
                {
                        file_output << "\n";
                }

                i = i + 1;
        }
}

bool ppm_to_brg(string filename) {
    Task2 p(filename);
    if (p.read()) {
        p.write();
        return true;
    }
    return false;
}

bool ppm_to_pgm(string filename) {
    Task7 ppm_file(filename);

    if (! ppm_file.read()) {
        return false;
    }

    ppm_file.modify();
    return true;
}

void txt_reader(string filename) {
    string outputfile = "Documentstatic-"+filename;
    //making class object
    Task4 f(filename);
    //to process input file
    f.read();
    //to write in outputfile
    f.write();

    //printing on terminal
    cout << YELLOW;
    // cout<<"Lines"<<f.getNumLines()<<" "<<f.getNumWords()<<" "<<f.getNumCharSpace()<<" "<<f.getNumChar()<<" "<<f.getBytes()<<endl;
    cout << RESET;

    cout<<"Lines - "<<f.getNumLines()<<endl;
    cout<<"Words - "<<f.getNumWords()<<endl;
    cout<<"Characters (with spaces) - "<<f.getNumCharSpace()<<endl;
    cout<<"Characters (no spaces) - "<<f.getNumChar()<<endl;
    cout<<"Bytes - "<<f.getBytes()<<endl;

    cout << RESET;

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
            txt_reader(filename);
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
                cin >> c2;
            }

            else if (choice == 2) {
                csv_transpose(filename);
                cout << GREEN << "File written successfully" << RESET << endl;
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
                if (ppm_to_brg(filename)) {
                    cout << GREEN << "File written successfully" << RESET << endl;
                } else {
                    cout << RED << "ERROR: Bad file format. Aborting.." << RESET << endl;
                }
            }

            else if (choice == 2) {
                if (ppm_to_pgm(filename)) {
                    cout << GREEN << "File written successfully" << RESET << endl;
                } else {
                    cout << RED << "ERROR: Bad file format. Aborting.." << RESET << endl;
                }
            } else {
                cout << RED << "ERROR: Wrong choice. Aborting.." << RESET << endl;
            }
        } else {
            cout << RED << "ERROR: Bad extension. File read failed. Aborting.." << RESET << endl;
        }

        cout << YELLOW << "To continue enter yes" << RESET << endl;

        cout << MAGENTA;
        string to_continue;
        cin >> to_continue;
        cout << RESET;

        transform(to_continue.begin(), to_continue.end(), to_continue.begin(), ::tolower);
        over = to_continue != "yes";
    }

    cout << CYAN << "Thanks for the demo :)" << RESET << endl;

    return 0;
}
