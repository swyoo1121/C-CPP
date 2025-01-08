#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N, result = 0;
    string title;
    map<string, int> book;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> title;
        book[title]++;
    }

    for (auto i = book.begin(); i != book.end(); i++) {
        result = max(result, i->second);
    }

    for (auto j = book.begin(); j != book.end(); j++) {
        if (result == j->second) {
            cout << j->first;
            return 0;
        }
    }
    
    return 0;
}