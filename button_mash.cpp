#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int max_size = 2 * n + 10;
    vector<int> dist(max_size, -1);
    queue<int> q;
    
    dist[0] = 0;
    q.push(0);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == n) {
            cout << dist[current] << endl;
            return 0;
        }
        
        // Operation +1
        int next = current + 1;
        if (next < max_size && dist[next] == -1) {
            dist[next] = dist[current] + 1;
            q.push(next);
        }
        
        // Operation -1 (only if current > 0)
        if (current > 0) {
            next = current - 1;
            if (next < max_size && dist[next] == -1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
        
        // Operation ×2
        next = current * 2;
        if (next < max_size && dist[next] == -1) {
            dist[next] = dist[current] + 1;
            q.push(next);
        }
    }
    
    return 0;
}
