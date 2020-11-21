#include "../includes/GreyScale.h"

using namespace std;

bool GreyScale::modify() {
    for (std::tuple<int, int, int> pixel: this->_rgb_pixels) {
        this->greyscale.push_back((.299 * get<0>(pixel)) + 
        (.587 * get<1>(pixel)) + (.114 * get<2>(pixel)));
    }

    this->content = this->greyscale;
    write();
    return true;
}