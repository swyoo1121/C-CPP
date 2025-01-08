#include <iostream>
#include <string>

using namespace std;

string name, team, chosen;
int L = 0, O = 0, V = 0, E = 0, N, result = -1;
int saveL, saveO, saveV, saveE;

int main() {
    cin >> name;

    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'L') L++;
        else if (name[i] == 'O') O++;
        else if (name[i] == 'V') V++;
        else if (name[i] == 'E') E++;
    }

    saveL = L;
    saveO = O;
    saveV = V;
    saveE = E;

    cin >> N;

    while (N--) {
        cin >> team;
    
        for (int i = 0; i < team.length(); i++) {
            if (team[i] == 'L') L++;
            else if (team[i] == 'O') O++;
            else if (team[i] == 'V') V++;
            else if (team[i] == 'E') E++;
        }

        int temp = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

        if (temp > result) {
            result = temp;
            chosen = team;
        }
        else if (temp == result) {
            if (team < chosen) chosen = team;
        }

        L = saveL;
        O = saveO;
        V = saveV;
        E = saveE;
    }

    cout << chosen << endl;
    return 0;
}