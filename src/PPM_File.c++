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
   
   content.erase(content.begin());
   content.erase(content.begin() + 1);
   content.erase(content.begin() + 2);
   content.erase(content.begin() + 3);
   
   return true;
}

bool PPM_File::parse_rgb_values(vector <string> content) { 
    for (int h = 0; h < this->_height; h ++) {
        for (int i = 0; i < 3 * this->_width; i += 3) {

            int red = stoi(content[i]);
            int green = stoi(content[i + 1]);
            int blue = stoi(content[i + 2]);
            this->_rgb_pixels.push_back(make_tuple(red, green, blue));
        }
    }

    return true;
}

bool PPM_File::read() {
    ifstream ppm_file(this->_filename + ".ppm");
    if (!ppm_file.is_open()) {
        return false;
    }

    vector <string> content = parse_content(ppm_file);

    if (!this->extract_header(content)) {
        return false;
    }

    this->parse_rgb_values(content);

    return true;
}

bool PPM_File::write(vector <int> content) {
    ofstream grey_scale_file(this->_filename + ".pgm");

    int max_grey_val = *max_element(content.begin(), content.end());

    grey_scale_file << "P2" << endl << this->_width << "\t" << this->_height << "\t" << max_grey_val << endl;

    for (int word: content) {
        grey_scale_file << word << " ";
    }

    return true;
}