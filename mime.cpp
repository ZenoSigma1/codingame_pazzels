#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    int n; // Number of elements which make up the association table.
    cin >> n; cin.ignore();
    int q; // Number Q of file names to be analyzed.
    cin >> q; cin.ignore();
    
    unordered_map<string, string> mimeMap;
    
    for (int i = 0; i < n; i++) {
        string ext; // file extension
        string mt; // MIME type.
        cin >> ext >> mt; cin.ignore();
        mimeMap[toLower(ext)] = mt;
    }
    
    for (int i = 0; i < q; i++) {
        string fname;
        getline(cin, fname); // One file name per line.
        
        size_t lastDot = fname.find_last_of('.');
        if (lastDot == string::npos || lastDot == fname.length() - 1) {
            cout << "UNKNOWN" << endl;
            continue;
        }
        
        string ext = fname.substr(lastDot + 1);
        string lowerExt = toLower(ext);
        
        if (mimeMap.find(lowerExt) != mimeMap.end()) {
            cout << mimeMap[lowerExt] << endl;
        } else {
            cout << "UNKNOWN" << endl;
        }
    }
    
    return 0;
}
