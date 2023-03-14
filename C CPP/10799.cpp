#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string input;
	
	stack <char> st;

	int cnt = 0;

	cin >> input;

	st.push(input[0]);

	for (int i = 1; i < input.length(); i++)
	{
		if (input[i] == '(')
			st.push(input[i]);
	

		else if (input[i] == ')')
		{
			if (input[i - 1] == '(')
			{
				st.pop();
				cnt += st.size();
			}

			else if (input[i - 1] == ')')
			{
				st.pop();
				cnt++;
			}
		}
	}
	
	cout << cnt;
	return 0;
}