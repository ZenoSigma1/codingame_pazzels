#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int h, w;
    cin >> h;
    cin >> w;
    vector<string> grid;
    cin.ignore(); // Ignore newline after reading w
    for (int i = 0; i < h; i++) {
        string s;
        getline(cin, s);
        grid.push_back(s);
    }

    int x = 0, y = -1;
    int dx = 0, dy = 1;
    int steps = 0;
    string result;

    while (true) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == '#') {
            x = nx;
            y = ny;
            steps++;
        } else {
            int left_dx = -dy;
            int left_dy = dx;
            int right_dx = dy;
            int right_dy = -dx;

            int left_x = x + left_dx;
            int left_y = y + left_dy;
            int right_x = x + right_dx;
            int right_y = y + right_dy;

            bool left_ok = (left_x >= 0 && left_x < h && left_y >= 0 && left_y < w && grid[left_x][left_y] == '#');
            bool right_ok = (right_x >= 0 && right_x < h && right_y >= 0 && right_y < w && grid[right_x][right_y] == '#');

            if (!left_ok && !right_ok) {
                if (steps > 0) {
                    result += to_string(steps);
                }
                break;
            } else if (left_ok && !right_ok) {
                result += to_string(steps) + "L";
                steps = 0;
                dx = left_dx;
                dy = left_dy;
            } else if (!left_ok && right_ok) {
                result += to_string(steps) + "R";
                steps = 0;
                dx = right_dx;
                dy = right_dy;
            } else {
                // Both available? Choose left arbitrarily
                result += to_string(steps) + "L";
                steps = 0;
                dx = left_dx;
                dy = left_dy;
            }
        }
    }

    cout << result << endl;
    return 0;
}
