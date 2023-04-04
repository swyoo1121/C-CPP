#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N, max = 0, start, end, s_pos = 0, e_pos;
    multimap<int, int>mm;

    cin >> N;

    for (int iter = 0; iter < N; iter++) {
        cin >> start >> end;
        mm.insert(make_pair(start, end));
    }

    for (auto it = mm.begin(); it != mm.end(); it++) {
        if (it != s_pos) {
            if (it->second - it->first < )
        }
        else {
            if ()
        }
    }


}

/*
int main() {
    int N, max = 0, start, end, start_pos = 0, end_pos = 0, start_limit, end_limit = 0;
    map<int, int>m;

    cin >> N;

    for (int iter = 0; iter< N;iter++) {
        cin >> start >> end;

        if (m.count(start) != 0) {
            if (m[start] < end;) continue;
            else {
                m[start] = end;
                if (end_limit < end) end_limit = end;
            }
        }
        else {
            m.insert(make_pair(start, end));
            if (end_limit < end) end_limit = end;            
        }
    }
    start_limit = m.begin;

    while(true) {

    }

    
       
}
*/