#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

    map<int, int> quiz;
    int score[8];
    int index[5];
    int sum = 0;

    for (int i = 0; i < 8; i++) {
        cin >> score[i];
        quiz.insert(make_pair(score[i], i+1));
    }

    sort(score, score + 8);

    for (int i = 3; i < 8; i++) {
        sum += score[i];
        index[i - 3] = quiz[score[i]];
    }

    sort(index, index + 5);

    cout << sum << endl;
    
    for (int i = 0; i < 5; i++) {
        cout << index[i] << ' ';
    }
    cout << endl;
    return 0;
}