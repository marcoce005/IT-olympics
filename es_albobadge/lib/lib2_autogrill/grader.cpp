#include <iostream>
#include <bits/stdc++.h>

using namespace std;

set<long long> aperti;
long long k;
auto iter = aperti.begin();
auto pre = iter;

void inizia() {
    return;
}

void apri(long long p) {
    aperti.insert(p);
}


void chiudi(long long p) {
    aperti.erase(p);
}

long long chiedi(long long p) {
    if (aperti.empty())
        return -1;
    //aperti.sort();
    /* for (iter = aperti.begin(); iter != aperti.end(); ++iter) {
        if (*iter > p) {
            pre = prev(iter);
            if (*pre > 10000)
                return *iter;
            if (abs(p - *pre) > abs(p - *iter))
                return *pre;
            else if (abs(p - *pre) <= abs(p - *iter))
                return *iter;
            else
                return *iter;
        } else if (*iter == p)
            return *iter;
        cont++;
    } */
    iter = aperti.lower_bound(p);
    if (*iter == *aperti.begin())
        return *iter;
    pre = iter;
    pre--;
    
    try {
        if(abs(p-*iter)<=abs(p-*pre))
            return *iter;
        else
            return *pre;
    } catch (long long p) {
        return *iter;
    }
}


int main() {
    freopen("autogrill.input2.txt", "r", stdin);
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
