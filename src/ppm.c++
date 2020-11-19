#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector <string> split(string s, char delimiter) {
    vector <string> words;
    stringstream s_stream(s);

    for (string word; s_stream >> word;) { 
        words.push_back(word);
        if (s_stream.peek() == delimiter) 
            s_stream.ignore(); 
    }

    return words; 
}

vector <string> get_content(ifstream& ppm_file) {
    vector <string> content;
    
    while (ppm_file) {
        string line;
        getline(ppm_file, line);
        if (line[0] == '#') {
            continue;
        }
        replace(line.begin(), line.end(), '\t', ' ');
        for (string word: split(line, ' ')) {
            content.push_back(word);
        }
    }

    return content;
}

tuple <int, int, int, int> extract_header(vector <string>& content) {
   string magic_no = content[0];
   int good_header = magic_no == "P3" ? 1 : -1;
   std::cout << content[1] << endl;
   int width = stoi(content[1]);
   int height = stoi(content[2]);
   int max_color_val = stoi(content[3]);
   std::cout << "Header" << endl;
   std::cout << magic_no << endl << width << "\t" << height << endl << max_color_val << endl; 
   content.erase(content.begin());
   content.erase(content.begin() + 1);
   content.erase(content.begin() + 2);
   content.erase(content.begin() + 3);
   std::cout << "No of rows " << content.size() << endl;
   return make_tuple(good_header, width, height, max_color_val);
}

vector<tuple<int, int, int>> get_rgb_values(vector <string> content, int width, int height) {
    vector<tuple<int, int, int>> rgb; 
    
    for (int h = 0; h < height; h ++) {
        for (int i = 0; i < 3 * width; i += 3) {
            int red = stoi(content[i]);
            int green = stoi(content[i + 1]);
            int blue = stoi(content[i + 2]);
            rgb.push_back(make_tuple(red, green, blue));
        }
    }

    return rgb;
}

vector<tuple<int, int, int>> read(string filename) {
    ifstream ppm_file(filename + ".ppm");
    if (!ppm_file.is_open()) {
        vector<tuple<int, int, int>> null;
        return null;
    }

    vector <string> content = get_content(ppm_file);

    ppm_file.close();

    tuple <int, int, int, int> header = extract_header(content);
    if (get<0>(header) < 0) {
        vector<tuple<int, int, int>> null;
        return null;
    }

    int width = get<1>(header); 
    int height = get<2>(header);

    return get_rgb_values(content, width, height);
}

vector <int> modify(vector<tuple<int, int, int>> pixels) {
    vector <int> greyscale;
    
    for (tuple<int, int, int> pixel: pixels) {
        greyscale.push_back((0.3 * get<0>(pixel)) + 
        (0.59 * get<1>(pixel)) + (0.11 * get<2>(pixel)));
    }

    return greyscale;
}

bool write(string filename, vector <int> content) {
    ofstream grey_scale_file(filename + ".pgm");

    int max_color_val = *max_element(content.begin(), content.end());

    grey_scale_file << "P2" << endl << "4\t4\n" << max_color_val << endl;

    for (int grey_val: content) {
        grey_scale_file << grey_val << " ";
    }

    return true;
}

int main() {
    string filename;
    cin >> filename;

    if (!(filename.rfind(".ppm") || filename.rfind(".pnm"))) {
        std::cout << "ERROR: Bad extension. File read failed. Aborting.." << endl;
        return 1;
    }

    vector<tuple<int, int, int>> rgb_pixels = read(filename);

    if (rgb_pixels.empty()) {
        std::cout << "ERROR: Cannot read file. Bad format. Aborting.." << endl;
        return 1;
    }

    vector <int> greyscale = modify(rgb_pixels);

    for (int grey : greyscale) {
        cout << grey << endl;
    }

    if (!write(filename, greyscale)) {
        cout << "Write failed. Aborting.." << endl;
    }

    cout << "File written successfully" << endl;
    return 0;
}