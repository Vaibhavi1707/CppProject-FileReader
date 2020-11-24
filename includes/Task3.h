#ifndef Task3_H
#define Task3_H

#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Task3{
    	public:
        	Task3(){};

        	Task3(vector<vector<string>> Table);

		void setMatrix(vector<vector<string>> Table);

		vector<vector<string>> getMatrix();

		void setTransMatrix(vector<vector<string>> Table);

        	vector<vector<string>> getTransMatrix();

	private:
		vector<vector<string>> Matrix;
	        vector<vector<string>> TransMatrix;
};
#endif
