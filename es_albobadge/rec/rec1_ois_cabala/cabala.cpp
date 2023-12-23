#include <bits/stdc++.h>
#include <queue>

using namespace std;

void occulta(int N, int M, priority_queue<long long>& risultato, long long current, int last = 0) {

    if (N == 0) {
        risultato.emplace(current % M);
        return;
    }
    
    risultato.emplace(current % M);
        
    if (last != 3) {
        occulta(N - 1, M, risultato, current * 10 + 3, 3);
    }

    if (last != 6) {
        occulta(N - 1, M, risultato, current * 10 + 6, 6);
    }
    
    if (last != 9) {
        occulta(N - 1, M, risultato, current * 10 + 9, 9);
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for(int i = 0; i != T; i++){
        int N, M;
        cin >> N >> M;
        
        priority_queue<long long> numeri;
        long long current;
        
        occulta(N, M, numeri, current);

        cout << numeri.top() << " ";
    }
}

