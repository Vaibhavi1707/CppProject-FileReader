#include <stdio.h>
#include<string>
#include<algorithm>
#include"../includes/Task8.h"
#include<iostream>
#include<fstream>
using namespace std;

void Task8::fillMetaData()
{
	for (int i = 0; i < arr[1].size(); i++)
	{
		if (isFloat(arr[1][i]))
			Task8::mD[i] = 0;
		else
			Task8::mD[i] = 1;
	}
}

void Task8::bubble1()
{
	int n = arr.size();
	if (mD[c1] == 1)
	{
		for (int p = 1; p < n; p++)
			for (int j = 0; j < n - p; j++)
				if (arr[j][c1] > arr[j + 1][c1])
				{
					vector <string> temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
	}
	else
	{
		for (int p = 1; p < n; p++)
			for (int j = 0; j < n - p; j++)
				if (stof(arr[j][c1]) > stof(arr[j + 1][c1]))
				{
					vector <string> temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
	}
}

void Task8::bubble2()
{
	int n = arr.size();
	if (mD[c1] == 1 && mD[c2] == 1)
	{
		for (int p = 1; p < n; p++)
			for (int i = 0; i < n - p; i++)
				if ((arr[i][c1] == arr[i + 1][c1]) && (arr[i][c2] > arr[i + 1][c2]))
				{
					vector <string> temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
	}
	else if (mD[c1] == 1 && mD[c2] == 0)
	{
		for (int p = 1; p < n; p++)
			for (int i = 0; i < n - p; i++)
				if ((arr[i][c1] == arr[i + 1][c1]) && (stof(arr[i][c2]) > stof(arr[i + 1][c2])))
				{
					vector <string> temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
	}
	else if (mD[c1] == 0 && mD[c2] == 0)
	{
		for (int p = 1; p < n; p++)
			for (int i = 0; i < n - p; i++)
				if ((stof(arr[i][c1]) == stof(arr[i + 1][c1])) && (stof(arr[i][c2]) > stof(arr[i + 1][c2])))
				{
					vector <string> temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
	}
	else
	{
		for (int p = 1; p < n; p++)
			for (int i = 0; i < n - p; i++)
				if ((stof(arr[i][c1]) == stof(arr[i + 1][c1])) && ((arr[i][c2]) > (arr[i + 1][c2])))
				{
					vector <string> temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
	}
}

void Task8::modify()
{
	Task8::mD.resize(col);
	fillMetaData();
	bubble1();
	bubble2();
}
