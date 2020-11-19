#include "../includes/GreyScale.h"

using namespace std;

bool GreyScale::modify() {
    for (std::tuple<int, int, int> pixel: this->_rgb_pixels) {
        // cout << get<0>(pixel) << " " << get<1>(pixel) << " " << get<2>(pixel) << endl;
        // cout << 0.3 * get<0>(pixel) << " " <<  0.59 * get<1>(pixel) << " " << 0.11 * get<2>(pixel) << endl;
        cout << (0.3 * get<0>(pixel)) + 
        (0.59 * get<1>(pixel)) + (0.11 * get<2>(pixel)) << endl;
        this->greyscale.push_back((0.3 * get<0>(pixel)) + 
        (0.59 * get<1>(pixel)) + (0.11 * get<2>(pixel)));
    }

    write(this->greyscale);
    return true;
}