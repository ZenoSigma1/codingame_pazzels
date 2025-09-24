#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int h;
    cin >> h;
    cin.ignore();
    
    vector<vector<int>> grid;
    int width = 0;
    
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> row;
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
        if (width == 0) {
            width = row.size();
        }
        grid.push_back(row);
    }
    
    vector<pair<int, int>> peaks;
    vector<pair<int, int>> valleys;
    
    // Directions for 8 neighbors: (dx, dy)
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < width; j++) {
            int current = grid[i][j];
            bool isPeak = true;
            bool isValley = true;
            
            for (const auto& dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                
                if (ni >= 0 && ni < h && nj >= 0 && nj < width) {
                    int neighbor = grid[ni][nj];
                    if (current <= neighbor) {
                        isPeak = false;
                    }
                    if (current >= neighbor) {
                        isValley = false;
                    }
                }
            }
            
            if (isPeak) {
                peaks.push_back({j, i}); // (x, y) = (column, row)
            }
            if (isValley) {
                valleys.push_back({j, i});
            }
        }
    }
    
    // Output peaks
    if (peaks.empty()) {
        cout << "NONE" << endl;
    } else {
        for (int i = 0; i < peaks.size(); i++) {
            cout << "(" << peaks[i].first << ", " << peaks[i].second << ")";
            if (i < peaks.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    
    // Output valleys
    if (valleys.empty()) {
        cout << "NONE" << endl;
    } else {
        for (int i = 0; i < valleys.size(); i++) {
            cout << "(" << valleys[i].first << ", " << valleys[i].second << ")";
            if (i < valleys.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
