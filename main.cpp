#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    int n = str.size();
    int min;
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        min = (z[i - l] < r - i) ? z[i - l] : r - i;
        z[i] = (0 > min) ? 0 : min;
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    for (auto a : z) {
        cout << a << " ";
    }
    return 0;
}
