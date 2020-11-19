#include "../includes/GreyScale.h"

using namespace std;

int main() {
    string filename;
    cin >> filename;

    if (!(filename.rfind(".ppm") || filename.rfind(".pnm"))) {
        std::cout << "ERROR: Bad extension. File read failed. Aborting.." << endl;
        return 1;
    }

    cout << "Hello" << endl;

    GreyScale ppm_file(filename);

    cout << "Hello" << endl;
    
    ppm_file.read();

    cout << "Hello" << endl;

    ppm_file.modify();

    cout << "Hello" << endl;

    cout << "File written successfully" << endl;
    return 0;
}