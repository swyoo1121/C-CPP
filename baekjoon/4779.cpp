    #include <iostream>

    using namespace std;

    int recur(int in)
    {
        int out = 1;
        while (in > 0)
        {
            in--;
            out *= 3;
        }
        return out;
    }

    void cantor(int N, int flag)
    {
        if (N == 1 && flag == 0)
            cout << '-';
        else if (N == 1 && flag == 1)
            cout << ' ';
        else if (flag == 1)
        {
            cantor(N / 3, 1);
            cantor(N / 3, 1);
            cantor(N / 3, 1);
        }
        else
        {
            cantor(N / 3, 0);
            cantor(N / 3, 1);
            cantor(N / 3, 0);
        }
    }

    int main()
    {
        int N, round;

        while (!(cin >> N).eof())
        {
            round = recur(N);
            cantor(round, 0);
            cout << '\n';
        }
        return 0;
    }