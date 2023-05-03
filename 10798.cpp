#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line[5];
    int length[5];
    
    for (int i = 0; i < 5; i++) {
        cin >> line[i];
        length[i] = line[i].length();
    }
    
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            if (length[j] <= i) continue;
            else cout << line[j][i];
        }
    }

    cout << endl;
    return 0;
}
