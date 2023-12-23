#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXIMUM 1002
int mat[MAXIMUM][MAXIMUM];

#define max(a,b) ((a) > (b) ? (a) : (b))


int solve(int t) {
    int N, M;
    scanf("%d %d", &N, &M);

    int V[N], G[M];
    for (int i = 0; i < N; i++)
        scanf("%d", &V[i]);
    for (int i = 0; i < M; i++)
        scanf("%d", &G[i]);

    for (int r = 0; r < N; r++) {
        mat[r][0] = r;
        for (int c = 0; c < M; c++) {
            mat[r + 1][c + 1] = max(mat[r + 1][c], mat[r][c + 1] + 1);
            if(V[r] < G[c])
                mat[r + 1][c + 1] = max(mat[r + 1][c + 1], mat[r][c] + 2);
        }
    }
    return mat[N][M];
}

int main() {
    freopen("mostra_input_8.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        printf("Case #%d: %d\n", t, solve(t));
    }
}