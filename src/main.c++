// #include "../includes/GreyScale.h"

// using namespace std;

// int main() {
//     string filename;
//     cin >> filename;

//     if (!(filename.rfind(".ppm") || filename.rfind(".pnm"))) {
//         std::cout << "ERROR: Bad extension. File read failed. Aborting.." << endl;
//         return 1;
//     }

//     GreyScale ppm_file(filename);
    
//     if (! ppm_file.read()) {
//         cout << "ERROR: Wrong File path. Aborting.." << endl;
//         return 1;
//     }

//     ppm_file.modify();

//     cout << "File written successfully" << endl;
//     return 0;
// }