#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> codeMap;
    for (int i = 0; i < n; i++) {
        string b;
        int c;
        cin >> b >> c;
        codeMap[b] = c;
    }
    string s;
    cin >> s;
    
    string result = "";
    int i = 0;
    while (i < s.size()) {
        bool found = false;
        for (auto& pair : codeMap) {
            string code = pair.first;
            if (s.size() - i < code.size()) {
                continue;
            }
            if (s.substr(i, code.size()) == code) {
                result += (char)pair.second;
                i += code.size();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "DECODE FAIL AT INDEX " << i << endl;
            return 0;
        }
    }
    cout << result << endl;
    return 0;
}
