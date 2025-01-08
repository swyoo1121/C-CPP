#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;

int N, M;
vector<string> listen;
vector<string> see;
vector<string> answer;
 
bool find(string key) {
 
    int start = 0, end = listen.size();
 
    while (start <= end) {
        
        int middle = (start + end) / 2;
 
        if (key < listen[middle]) {
            end = middle - 1;
        }
        else if (key > listen[middle]) {
            start = middle + 1;
        }
        else {
            return true;
        }
    }
 
    return false;
}
 
int main() {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        listen.push_back(tmp);
    }
    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        see.push_back(tmp);
    }

    sort(listen.begin(), listen.end());
 
    for (int i = 0; i < M; i++) {
        bool isIn = find(see[i]);

        if (isIn) {
            answer.push_back(see[i]);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
