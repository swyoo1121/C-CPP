#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int N, result = 0;
string input;
set<string> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    while (N--) {
        cin >> input;
        
        if (input == "ENTER") {
            result += s.size();
            s.clear();
        }
        else {
            s.insert(input);
        }
    }
    result += s.size();

    cout << result << '\n';
    return 0;    
}