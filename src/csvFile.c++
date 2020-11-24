#include"../includes/csvFile.h"

csvFile :: csvFile(vector<vector<string>> Table)
{

	setMatrix(Table);

}

void csvFile :: setMatrix(vector<vector<string>> Table)
{
	int i = 0;
	int size = Table.size();
	
	while(i < size)
	{
        	Matrix.push_back(Table[i]);
		i = i + 1;
    	}

}

vector<vector<string>> csvFile :: getMatrix()
{

    return Matrix;

}

void csvFile :: setTransMatrix(vector<vector<string>> Table)
{

        int i = 0;
        int size = Table.size();

        while(i < size)
        {
                TransMatrix.push_back(Table[i]);
                i = i + 1;
        }

}


vector<vector<string>> csvFile :: getTransMatrix()
{

    	return TransMatrix;

}
