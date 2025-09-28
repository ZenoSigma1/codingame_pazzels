#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> temperatures;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        temperatures.push_back(t);
    }
    
    int closest = temperatures[0];
    for (int i = 1; i < n; i++) {
        int current = temperatures[i];
        if (abs(current) < abs(closest)) {
            closest = current;
        } else if (abs(current) == abs(closest)) {
            if (current > closest) {
                closest = current;
            }
        }
    }
    
    cout << closest << endl;
    return 0;
}
