#include "count.h"
/*
    Given a C++ source file,how many times does each reserved word come up?
*/

/*
    Funciton:OpenUserFile(ifstream& fileStream)
    Prompts the user for a filename until a valid filename is entered,
    then sets fileStream to read from that file.
*/
void OpenUserFile(ifstream& input){
    while(true){
        cout << "Enter filename: ";
        string filename;
        getline(cin,filename);
        
        input.open(filename.c_str());
        if(input.is_open()) return;

        cout << "Sorry, I can't find the file" << filename << endl;
        input.clear();

    }
}
/*
    Function:GetFileCOntents(ifstream& filename)
    returns a string containing the contents of the file passed in as a parameter.
*/
string GetFileContents(ifstream& input){
    string result;
    
    string line;
    while(getline(input,line)){
        result += line + "\n";
    }

    return result;
}
/*
    Function:set<string> LoadKeyWords();
    load the keyword list to set<string> , becasue of set is effective to quary one element.
*/
set<string> LoadKeyWords(){
    ifstream input("keyword.txt");

    set<string> result;

    string keyword;
    while (input >> keyword ) 
        result.insert(keyword);//set.insert(element) return a pair of <iterator, bool>;
    return result;   
}
/*
    Function:PreprocessString(string& stringname)
    accept a string by reference,then replace all punctuation charcters in that string with the 
    space  character

    ispunct(char) accept a char  return 1 if it is punctuation ,0 othewisw.
*/
void PreprocessString(string& text){
    for(size_t k = 0 ;  k < text.size(); k ++){
        if(ispunct(text[k]) && text[k] != '_') 
            text[k] = ' ';
    }
}
/*

    Function:map<string, size_t>GeneratKeyWordReport(string& textname)
*/
map<string , size_t> GeneratKeyWordReport(string& contents){
    set<string> keyword = LoadKeyWords();

    PreprocessString(contents);
    stringstream tokenizer;
    tokenizer << contents;

    map<string, size_t> result;

    string word;
    while (tokenizer >> word){
        if (keyword.count(word))
            ++ result[word];
    }
    return result;
}