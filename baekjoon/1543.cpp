#include <iostream>
#include <string>

using namespace std;

int main() {
    int count = 0;
    string input, target;

    getline(cin, input);
    getline(cin, target);

    for (int iter = 0; iter < input.length();) {
        int index = input.find(target, iter);
        if (index >= 0) {
            iter = index + target.length();
            count++;
        }
        else iter++;
    }
    
    cout << count << endl;
}
