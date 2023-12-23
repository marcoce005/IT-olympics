#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <list>

using namespace std;

list<int> aperti;

void inizia() {
    return;
}

void apri(long long p) {
    aperti.push_back(p);
}


void chiudi(long long p) {
    aperti.remove(p);
}

long long chiedi(long long p) {
    if (aperti.empty())
        return -1;
    aperti.sort();
    for (long long x : aperti) {
        if (x >= p) {
            return x;
        }
    }
    return -1;
}


int main() {
    freopen("autogrill.input0.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int Q;
    cin >> Q;

    inizia();

    for (int i = 0; i < Q; i++){
        long long p;
        char t;
        cin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else cout << chiedi(p) << endl;
    }

    return 0;
}