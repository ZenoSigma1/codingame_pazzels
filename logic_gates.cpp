#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to apply logic gate operations
bool applyGate(const string& gate, bool a, bool b) {
    if (gate == "AND") return a && b;
    if (gate == "OR") return a || b;
    if (gate == "XOR") return a != b;
    if (gate == "NAND") return !(a && b);
    if (gate == "NOR") return !(a || b);
    if (gate == "NXOR") return !(a != b);
    return false; // Should not happen
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    
    // Store input signals
    unordered_map<string, string> signals;
    
    for (int i = 0; i < n; i++) {
        string name, signal;
        cin >> name >> signal;
        signals[name] = signal;
    }
    
    // Store output specifications
    vector<vector<string>> outputs;
    
    for (int i = 0; i < m; i++) {
        string output_name, gate, input1, input2;
        cin >> output_name >> gate >> input1 >> input2;
        outputs.push_back({output_name, gate, input1, input2});
    }
    
    // Process each output
    for (const auto& output : outputs) {
        string output_name = output[0];
        string gate = output[1];
        string input1 = output[2];
        string input2 = output[3];
        
        // Get the input signals
        string signal1 = signals[input1];
        string signal2 = signals[input2];
        
        // Result signal
        string result;
        
        // Process each character position
        for (size_t i = 0; i < signal1.length(); i++) {
            bool a = (signal1[i] == '-');
            bool b = (signal2[i] == '-');
            bool res = applyGate(gate, a, b);
            result += res ? '-' : '_';
        }
        
        cout << output_name << " " << result << endl;
    }
    
    return 0;
}
