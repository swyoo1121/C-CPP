#include <iostream>
#include <string>

using namespace std;

int main()
{
    string course, grade;
    double score, result = 0, count = 0;

    for (int iter = 0; iter < 20; iter++)
    {
        cin >> course >> score >> grade;

        if (grade == "A+")
        {
            result += score * 4.5;
            count += score;
        }
        else if (grade == "A0")
        {
            result += score * 4.0;
            count += score;
        }
        else if (grade == "B+")
        {
            result += score * 3.5;
            count += score;
        }
        else if (grade == "B0")
        {
            result += score * 3.0;
            count += score;
        }
        else if (grade == "C+")
        {
            result += score * 2.5;
            count += score;
        }
        else if (grade == "C0")
        {
            result += score * 2.0;
            count += score;
        }
        else if (grade == "D+")
        {
            result += score * 1.5;
            count += score;
        }
        else if (grade == "D0")
        {
            result += score * 1.0;
            count += score;
        }
        else if (grade == "F")
        {
            count += score;
        }
    }

    cout << result / count << endl;
    return 0;
}