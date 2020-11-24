#include <stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<sstream>
#include"../includes/CSV_File.h"
#include<fstream>

using namespace std;

bool CSV_File::isFloat(string myString) {
	istringstream iss(myString);
	float f;
	iss >> noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool CSV_File::read()
{
	ifstream input_from_file("1.csv");
	vector <vector<string>> arr;
	string line;
	while (getline(input_from_file, line))
	{
		line += ",";
		stringstream ss(line);
		string word;
		vector<string> words;
		while (getline(ss, word, ','))
		{
			words.push_back(word);
		}
		arr.push_back(words);
	}
	row = arr.size();
	col = arr[1].size();
	return true;
}

bool CSV_File::write()
{
	ofstream myfile;
	myfile.open(output);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j != col - 1)
				myfile << arr[i][j] << ",";
			else
				myfile << arr[i][j];
		}
		if (i != row - 1)
			myfile << "\n";
	}
	myfile.close();
	return true;
}
