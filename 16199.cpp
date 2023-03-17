#include <iostream>

using namespace std;

int main() {
    int year, month, date, now_year, now_month, now_date;
    int age1 = 0, age2 = 0;

    cin >> year >> month >> date;
    cin >> now_year >> now_month >> now_date;

    age1 = now_year - year;
    age2 = age1;

    if (month > now_month || (month == now_month) && date > now_date) age2--;

    cout << age2 << endl;
    cout << age1 + 1 << endl;
    cout << age1 << endl;
    return 0;

}