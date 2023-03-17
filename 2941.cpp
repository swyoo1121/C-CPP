#include <iostream>
#include <string>

using namespace std;

int checker(string word, int index)
{
    if (word[index] == 'c' && word[index + 1] == '=')
        return 1;
    else if (word[index] == 'c' && word[index + 1] == '-')
        return 1;
    else if (word[index] == 'd' && word[index + 1] == 'z' && word[index + 2] == '=')
        return 2;
    else if (word[index] == 'd' && word[index + 1] == '-')
        return 1;
    else if (word[index] == 'l' && word[index + 1] == 'j')
        return 1;
    else if (word[index] == 'n' && word[index + 1] == 'j')
        return 1;
    else if (word[index] == 's' && word[index + 1] == '=')
        return 1;
    else if (word[index] == 'z' && word[index + 1] == '=')
        return 1;
    else
        return 0;
}

int main()
{
    string word;
    int result = 0;

    cin >> word;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (checker(word, i) == 1)
        {
            result++;
            i++;
        }
        else if (checker(word, i) == 2)
        {
            result++;
            i += 2;
        }
        else
        {
            result++;
        }
    }

    cout << result << endl;
    return 0;
}
