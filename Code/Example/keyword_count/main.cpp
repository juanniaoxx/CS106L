#include "count.h"

int main()
{
    ifstream input;
    OpenUserFile(input);
    string txt;
    txt = GetFileContents(input);
    map<string, size_t> report = GeneratKeyWordReport(txt);

    for (map<string, size_t>::iterator iter = report.begin(); iter != report.end(); iter++) {
        cout << "keyword " << iter->first << " occurred " << iter->second << " times "  << endl;
    }
    return 0;
}