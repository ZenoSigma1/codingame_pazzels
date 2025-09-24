#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int l, w, d, n;
    cin >> l >> w >> d >> n;
    cin.ignore();
    
    vector<string> input_lines;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        input_lines.push_back(line);
    }
    
    // Precompute rounded square root table for optimization
    int max_squared = (l-1)*(l-1) + (w-1)*(w-1) + (d-1)*(d-1);
    vector<int> rounded_sqrt(max_squared + 1);
    for (int i = 0; i <= max_squared; i++) {
        double sqrt_val = sqrt(i);
        rounded_sqrt[i] = static_cast<int>(sqrt_val + 0.5);
    }
    
    // Parse the 3D grid from input lines
    vector<vector<vector<char>>> grid(l, vector<vector<char>>(w, vector<char>(d, '.')));
    int line_index = 0;
    
    for (int z = 0; z < d; z++) {
        for (int y = 0; y < w; y++) {
            while (line_index < n && input_lines[line_index].size() != l) {
                line_index++;
            }
            if (line_index < n) {
                string line = input_lines[line_index];
                for (int x = 0; x < l; x++) {
                    grid[x][y][z] = line[x];
                }
                line_index++;
            }
        }
    }
    
    // Collect all light sources
    vector<tuple<int, int, int, int>> lights;
    for (int x = 0; x < l; x++) {
        for (int y = 0; y < w; y++) {
            for (int z = 0; z < d; z++) {
                char c = grid[x][y][z];
                if (c != '.') {
                    int radius;
                    if (c >= '1' && c <= '9') {
                        radius = c - '0';
                    } else if (c >= 'A' && c <= 'Z') {
                        radius = 10 + (c - 'A');
                    } else {
                        continue;
                    }
                    lights.push_back(make_tuple(x, y, z, radius));
                }
            }
        }
    }
    
    // Calculate brightness for each cell
    vector<vector<vector<int>>> brightness(l, vector<vector<int>>(w, vector<int>(d, 0)));
    
    for (int x = 0; x < l; x++) {
        for (int y = 0; y < w; y++) {
            for (int z = 0; z < d; z++) {
                int total_brightness = 0;
                
                for (const auto& light : lights) {
                    int x0 = get<0>(light);
                    int y0 = get<1>(light);
                    int z0 = get<2>(light);
                    int radius = get<3>(light);
                    
                    int dx = x - x0;
                    int dy = y - y0;
                    int dz = z - z0;
                    int squared_dist = dx*dx + dy*dy + dz*dz;
                    
                    int distance;
                    if (squared_dist <= max_squared) {
                        distance = rounded_sqrt[squared_dist];
                    } else {
                        distance = static_cast<int>(sqrt(squared_dist) + 0.5);
                    }
                    
                    int contribution = radius - distance;
                    if (contribution > 0) {
                        total_brightness += contribution;
                    }
                }
                
                if (total_brightness > 35) {
                    total_brightness = 35;
                }
                brightness[x][y][z] = total_brightness;
            }
        }
    }
    
    // Output the result in the required format
    for (int z = 0; z < d; z++) {
        for (int y = 0; y < w; y++) {
            for (int x = 0; x < l; x++) {
                int b = brightness[x][y][z];
                if (b < 10) {
                    cout << char('0' + b);
                } else {
                    cout << char('A' + (b - 10));
                }
            }
            cout << endl;
        }
        if (z != d - 1) {
            cout << endl;
        }
    }
    
    return 0;
}
