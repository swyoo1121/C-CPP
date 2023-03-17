#include <iostream>
#include <string>

using namespace std;

int main() {
    string diary;
    getline(cin, diary);

    int index = 0;

    while (index != diary.length()) {
        if (diary[index] == 'a' || diary[index] == 'e' || diary[index] == 'i' || diary[index] == 'o' || diary[index] == 'u') {
            cout << diary[index];
            index += 3;
        }
        else {
            cout << diary[index];
            index++;
        }
    }

    return 0;
}