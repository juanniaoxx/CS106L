#ifndef COUNT_H
#define COUNT_H

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

void OpenUserFile(ifstream& input);
string GetFileContents(ifstream& file);
set<string> LoadKeyWords();
void PreprocessString(string& text);
map<string , size_t> GeneratKeyWordReport(string& contents);


#endif 