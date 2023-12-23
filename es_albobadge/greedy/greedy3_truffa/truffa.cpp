#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int sfangate(int N, int V[]) {
    int tot = 0;
    for (int i = 0; i < N; i++)
        tot += V[i];
    if (tot > 0)
        return 0;
    else if(tot == 0)
        return 1;
    
    vector<int> V2;
    for (int i = 0; i < N; i++) {
        if (V[i] < 0)
            V2.push_back(V[i] * -1);
    }

    sort(V2.begin(), V2.end(), greater<int>());

    int pos, truffe = 0;
    for (auto k : V2) {
        truffe++;
        tot = 0;
        for (int j = 0; j < N; j++) {
            if (V[j] == k * -1)
                pos = j;
        }
        V[pos] = V[pos] * -1;
        for (int i = 0; i < N; i++)
            tot += V[i];
        if (tot >= 0)
            return truffe;   
    }
    return 0;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}