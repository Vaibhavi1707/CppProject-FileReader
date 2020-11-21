#include "../includes/PPM_File.h"

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

vector <string> parse_content(ifstream& ppm_file) {
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

    ppm_file.close();

    return content;
}

bool PPM_File::extract_header(vector <string>& content) {
   this->_magic_no = content[0];

   if (this->_magic_no != "P3") {
       return false;
   }
   
   this->_width = stoi(content[1]);
   this->_height = stoi(content[2]);
   this->_max_color_val = stoi(content[3]);
   
   return true;
}

bool PPM_File::parse_rgb_values(vector <string> content) {

    for (int h = 0; h < 3 * this->_height * this->_width; h += 3 * this->_width) {
        for (int i = h; i < h + 3 * this->_width; i += 3) {

            int red = stoi(content[i]);
            int green = stoi(content[i + 1]);
            int blue = stoi(content[i + 2]);

            this->_rgb_pixels.push_back(make_tuple(red, green, blue));
        }
    }

    return true;
}

bool PPM_File::read() {
    ifstream ppm_file(this->_filename);
    if (!ppm_file.is_open()) {
        return false;
    }

    vector <string> content = parse_content(ppm_file);

    if (!this->extract_header(content)) {
        return false;
    }

    auto new_begin = content.erase(content.begin());
    auto new_begin1 = content.erase(new_begin);
    auto new_begin2 = content.erase(new_begin1);
    content.erase(new_begin2);

    this->parse_rgb_values(content);

    return true;
}

bool PPM_File::write() {
    ofstream grey_scale_file(this->_filename.substr(0, this->_filename.length() - 3) + ".pgm");

    int max_grey_val = *max_element(content.begin(), content.end());

    grey_scale_file << "P2" << endl << this->_width << "\t" << this->_height << "\t" << max_grey_val << endl;

    for (int i = 0; i < content.size(); i += this->_width) {
        for (int j = 0; j < this->_width; j ++) {
            grey_scale_file << content[i + j] << '\t';
        }
        grey_scale_file << endl;
    }

    grey_scale_file.close();

    return true;
}