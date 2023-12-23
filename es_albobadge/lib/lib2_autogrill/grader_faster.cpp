#include <iostream>
#include <vector>
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort

using namespace std;

vector<int> aperti;

// std::sort with inlining
struct compare {
    // the compiler will automatically inline this
    bool operator()(const int a, const int b) {
        return a < b;
    }
};

void inizia()
{
    return;
}

void apri(long long p)
{
    aperti.push_back(p);
}

void chiudi(long long p)
{
    remove(aperti.begin(), aperti.end(), p);
}

long long chiedi(long long p)
{
    if (aperti.empty())
        return -1;
    sort(aperti.begin(), aperti.end(), compare{});
    return *(lower_bound(aperti.begin(), aperti.end(), p));
}

int main()
{
    freopen("autogrill.input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int Q;
    cin >> Q;

    inizia();

    for (int i = 0; i < Q; i++)
    {
        long long p;
        char t;
        cin >> t >> p;
        if (t == 'a')
            apri(p);
        else if (t == 'c')
            chiudi(p);
        else
            cout << chiedi(p) << endl;
    }

    return 0;
}
