#include <stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<sstream>
#include"../includes/CSV_File.h"
#include<fstream>
using namespace std;
int CSV_File::countDelimeters(string c, string input)
{
	int count = 0, constant = c.length();
	char* p = strstr(input, c); // What do you want to do in this function?
	string k = input;
	while (p != NULL)
	{
		k = p + constant + 1;
		count++;
		if (k.length() == 0)
			break;
		p = strstr(k, c);
	}
	return count;
}

int CSV_File::fill()
{
	char c[] = ",";
	ifstream in(fileName);
	// FILE* F = fopen(fileName, "r");
	string line;
	if (!in.is_open())
	{
		printf("FILE CANNOT BE OPENED!!\n");
		return -1;
	}
	else
	{
		do
		{
			getline(in, line);
			char x[100];
			string line1 = line;
			vector < string > segment;
			for (int i = 0; i < col; i++)
			{
				// What do you want to do in this block?
				if (i != col - 1)
					sscanf(line1, "%[^,],", x);
				else
					sscanf(line1, "%[^\n]", x);
				string data(x);
				line1 = strstr(line1, ",") + 1;
				segment.push_back(x);
			}
			arr.push_back(segment);
		} while (in);
	}
	in.close();
	return 1;
}

int CSV_File::GetColumnNumber(string name)
{
	int number = 0;
	int pow = 1, l = name.length();

	for (int i = l - 1; i >= 0; i--)
	{
		number += (name[i] - 'A' + 1) * pow;
		pow *= 26;
	}
	return number;
}

int CSV_File::getNoOfRows()
{
	// FILE* F = fopen(fileName, "r");
	ifstream F(fileName);
	string line;
	int nl = 1;
	if (!F.is_open())
	{
		printf("FILE CANNOT BE OPENED!!\n");
		return -1;
	}
	else
	{
		getline(F, line);
		while (F)
		{
			nl++;
			getline(F, line);
		}
	}
	F.close();
	return nl;
}

int CSV_File::getNoOfCols()
{
	char c[] = ",";
	// FILE* F = fopen(fileName, "r");
	ifstream F(fileName);
	string line;
	int nl = 1;
	if (!F.is_open())
	{
		printf("FILE CANNOT BE OPENED!!\n");
		return -1;
	}
	else
	{
		getline(F, line);
		nl += countDelimeters(c, line);
	}
	F.close();
	return nl;
}

bool CSV_File::isFloat(string myString) {
	istringstream iss(myString);
	float f;
	iss >> noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool CSV_File::read()
{
	char comma[] = ",";
	row = getNoOfRows();
	col = getNoOfCols();
	fill();
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
