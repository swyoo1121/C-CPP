#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];
vector<int> X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int iter = 0; iter < N; iter++) {
        cin >> arr[iter];
        X.push_back(arr[iter]);
    }

    sort(X.begin(), X.end());

    X.erase(unique(X.begin(), X.end()), X.end());
    
    for(int i = 0; i < N; i++){
		int idx = lower_bound(X.begin(), X.end(), arr[i]) - X.begin();
		cout << idx << " "; 
	}
    cout << endl;
    return 0;
}