#include"../includes/Task3.h"

Task3 :: Task3(vector<vector<string>> Table)
{

	setMatrix(Table);

}

void Task3 :: setMatrix(vector<vector<string>> Table)
{
	int i = 0;
	int size = Table.size();

	while(i < size)
	{
        	Matrix.push_back(Table[i]);
		i = i + 1;
    	}

}

vector<vector<string>> Task3 :: getMatrix()
{

    return Matrix;

}

void Task3 :: setTransMatrix(vector<vector<string>> Table)
{

        int i = 0;
        int size = Table.size();

        while(i < size)
        {
                TransMatrix.push_back(Table[i]);
                i = i + 1;
        }

}


vector<vector<string>> Task3 :: getTransMatrix()
{

    	return TransMatrix;

}
