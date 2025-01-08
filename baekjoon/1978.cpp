#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int result = 0;
    int input;

    for (int i = 0; i < N; i++)
    {
        cin >> input;

        int prime = 1;
        for (int j = 2; j < input; j++)
        {
            if (input % j == 0)
            {
                prime = 0;
                break;
            }
            else if (j * j >= input)
                break;
        }
        if (input == 1)
            prime = 0;
        if (prime == 1)
            result++;
    }

    cout << result << endl;
    return 0;
}
