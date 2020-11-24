#include "../includes/TXT_File.h"

//defining constructor
TXT_File::TXT_File (string fname){

    filename = "../Test_files/Text_files/"+fname;
    outputfile = "../Output_files/Text_files/new-"+fname;

    numChar=0;
    numWords=0;
    numSpace=0;
    numLines=0;
    numchar_nounicode=0;
    bytes=0;
}

//to count subwords in words with non alpha-numeric char
int TXT_File::countSubWords(string word){

    word = word+'.';
    int flag,count=0;

    //assigning flag acc to first char of words
    if(isdigit(word[0]) || isalpha(word[0]))
        flag=1;
    else
        flag=0;

    //counting increase whenever flag changes from 0 to 1
    //because when we get alpha-numeric char after an special char
    //we know we got a new word i.e (word1)(word2)  {after 8th index second sub word starts
    //as we got alpha-numeric char after special char
    for(int i=0; i<word.size(); i++){
        if(flag){
            if(isalpha(word[i])||isdigit(word[i]))
                flag=1;

            else{
                flag=0;
                count++;
            }
        }
        else{
            if(isalpha(word[i])||isdigit(word[i]))
                flag=1;
        }
    }
    // return sub-word count
    return count;
}

//to count no of words {between two spaces} (ligature and diacritic not included)
int TXT_File::countWords(string line){
    int flag=0;
    //using stringstream to take input form string
    stringstream s(line);
    string word ;

    //looping in string to check if we have any special char i.e non alpha-numberic chars
    //if we have then we have to count subwords inside that word
    while (s >> word){
        flag=0;
        //if we have non alpha-numberic char find subwords
        for(int i=0; i<word.length(); i++){
            if(!(isalpha(word[i]) || isdigit(word[i])))
                flag=1;
        }

        if(flag)
            numWords+=countSubWords(word);
        else
            numWords++;
    }
}

//count no of chars(without space) and spaces in line
int TXT_File::countChars(string line){
    char ch;
    int flag=0;

    for(int i=0; i<line.length(); i++){
        ch=line[i];
        numchar_nounicode++;
        if(flag==0){
            // to check if any char unicode char is present (char uses replacement-char in txt file)
            if((ch & 0xC0) != 0x80)
                numChar++;
            if(isspace(ch)){
                numChar--;
                numSpace++;
                numchar_nounicode--;
            }
        }

    }
}

//driver function
bool TXT_File::read(){
    string line;
    fin.open(filename);
    //reading whole file
    while(getline(fin,line)){
        numLines++;
        countChars(line);
        countWords(line);
    }
    fin.close();
}

// void TXT_File::write(string content_to_write, int size){
//     int x;
// }

//writing in outputfile
bool TXT_File::write(){
    string line;

    fout.open(outputfile,ios::out);
    if(fout){
        //writing Document static in outputfile as header
        fout<<endl<<endl;
        fout<<"Lines - "<<numLines<<endl;
        fout<<"Words - "<<numWords<<endl;
        fout<<"Characters (with spaces) - "<<numSpace+numChar+numLines-1<<endl;
        fout<<"Characters (no spaces) - "<<numChar<<endl;
        fout<<"Bytes - "<<numSpace+numChar+numLines-1<<endl;
        fout<<endl<<endl;

        //writing text input file as body of outputfile
        fin.open(filename);
        while (getline(fin,line)){
            fout<<line;
            fout<<endl;
        }
        fin.close();

    }
    fout.close();
}

int TXT_File::getNumWords(){ return numWords; }
int TXT_File::getNumLines(){ return numLines; }
int TXT_File::getNumCharSpace(){ return numSpace+numChar+numLines-1; }
int TXT_File::getNumChar(){ return numChar; }
int TXT_File::getBytes(){ return numSpace+numchar_nounicode+numLines-1; }
