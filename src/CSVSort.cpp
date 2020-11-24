#include <stdio.h>
#include<string>
#include<algorithm>
#include"../includes/CSVSort.h"
#include<iostream>
using namespace std;

int CSVSort::fillMetaData()
{
	for (int i = 0; i < arr[1].size(); i++)
	{
		if (isFloat(arr[1][i]))
			CSVSort::mD[i] = 0;
		else
			CSVSort::mD[i] = 1;
	}
}

/*bool CSVSort::compareVector(vector <string> i1, vector <string> i2)
{
	/*if (CSVSort::mD[CSVSort::c1] == 1 && CSVSort::mD[CSVSort::c2] == 1)
	//String ii1 = i1[col]
		return (i1[CSVSort::c1] < i2[CSVSort::c1]) ||
		((i1[CSVSort::c1] == i2[CSVSort::c1]) && (i1[CSVSort::c2] < i2[CSVSort::c2]));
	else if (CSVSort::mD[CSVSort::c1] == 1 && CSVSort::mD[CSVSort::c2] == 0)
	{
		return (i1[CSVSort::c1] < i2[CSVSort::c1]) ||
			((i1[CSVSort::c1] == i2[CSVSort::c1]) && (stof(i1[CSVSort::c2]) < stof(i2[CSVSort::c2])));
	}
	else if (CSVSort::mD[CSVSort::c1] == 0 && CSVSort::mD[CSVSort::c2] == 1)
	{
		return stof(i1[CSVSort::c1]) < stof(i2[CSVSort::c1]) ||
			((stof(i1[CSVSort::c1]) == stof(i2[CSVSort::c1])) && ((i1[CSVSort::c2]) < (i2[CSVSort::c2])));
	}
	else
		return stof(i1[CSVSort::c1]) < stof(i2[CSVSort::c1]) ||
		((stof(i1[CSVSort::c1]) == stof(i2[CSVSort::c1])) && (stof(i1[CSVSort::c2]) < stof(i2[CSVSort::c2])));
}*/

void CSVSort::bubble1()
{
int n = arr.size();
	if(mD[c1] == 1)
	{for(int p=1;p<n;p++)
		for(int j=0;j<n-p;j++)
			if(arr[j][c1] > arr[j+1][c1])
			{
				vector <string> temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
	}
	else
	{for(int p=1;p<n;p++)
		for(int j=0;j<n-p;j++)
			if(stof(arr[j][c1]) > stof(arr[j+1][c1]))
			{
				vector <string> temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
	}
}

void CSVSort::bubble2()
{
int n = arr.size();
	if(mD[c1] == 1 && mD[c2] == 1)
	{
		//cout<<""
		for(int p=1;p<n;p++)
		for(int i=0;i<n-p;i++)
			if((arr[i][c1] == arr[i+1][c1]) && (arr[i][c2] > arr[i+1][c2]))
			{
				vector <string> temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
	}
	else if(mD[c1] == 1 && mD[c2] == 0)
	{for(int p=1;p<n;p++)
		for(int i=0;i<n-p;i++)
			if((arr[i][c1] == arr[i+1][c1]) && (stof(arr[i][c2]) > stof(arr[i+1][c2])))
			{
				vector <string> temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
	}
	else if(mD[c1] == 0 && mD[c2] == 0)
	{
		//cout<<"Both number";
		for(int p=1;p<n;p++)
		for(int i=0;i<n-p;i++)
			if((stof(arr[i][c1]) == stof(arr[i+1][c1])) && (stof(arr[i][c2]) > stof(arr[i+1][c2])))
			{
				vector <string> temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
	}
	else
	{for(int p=1;p<n;p++)
		for(int i=0;i<n-p;i++)
			if((stof(arr[i][c1]) == stof(arr[i+1][c1])) && ((arr[i][c2]) > (arr[i+1][c2])))
			{
				vector <string> temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
	}
}

void CSVSort::modify()
{
	CSVSort::mD.resize(col);
	fillMetaData();
	bubble1();
	bubble2();
	//sort(arr.begin(), arr.end(), compareVector);
}
