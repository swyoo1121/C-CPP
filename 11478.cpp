#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string S;
    set<string> group;
    cin >> S;
    
    for (int i = 1; i <= S.length(); i++) {
        for (int j = 0; j <= S.length() - i; j++) {
            string target = S.substr(j, i);
            group.insert(target);
        }
    }

    cout << group.size() << endl;
    return 0;

}