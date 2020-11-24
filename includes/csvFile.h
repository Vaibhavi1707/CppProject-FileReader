#ifndef csvFile_H
#define csvFile_h

#include <iostream>
#include<vector>
#include<string>

using namespace std;

class csvFile{
    	public:
        	csvFile(){};

        	csvFile(vector<vector<string>> Table);
        	
		void setMatrix(vector<vector<string>> Table);

		vector<vector<string>> getMatrix();
        	
		void setTransMatrix(vector<vector<string>> Table);
        	
        	vector<vector<string>> getTransMatrix();
        	
	private:
		vector<vector<string>> Matrix;
	        vector<vector<string>> TransMatrix;
};
#endif
