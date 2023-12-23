#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// #define MAXN 1005
// int dp[MAXN][MAXN];

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct dati
{
    int x, y, v;
} cella;

void u_cella(cella *cell, int x, int y, int v)
{
    cell->x = x;
    cell->y = y;
    cell->v = v;
}

#define max(a,b) ((a) > (b) ? (a) : (b))

/* int c() {
    for (int i = 0; i < )
} */

/* int f(x, y) {
    if (x == 0 || y == 0)
        return 0;
}
 */
int solve(int t)
{
    int N, M;
    scanf("%d %d", &N, &M);

    int V[N], G[M];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &G[i]);
    }

    cella arr[(N * M) + 3];
    u_cella(&arr[0], -1, 0, 1);
    u_cella(&arr[1], 0, -1, 0);
    u_cella(&arr[2], -1, -1, 2);

    int cont = 3;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) {
            int val1 = max(f(x-1, y) + 1, f(x, y-1));
            int val2 = 0;
            if (G[j] > V[i]) {
                val2 = f(x-1, y-1) + 2;
            }
            u_cella(&arr[cont++], i, j, max(val1, val2));
        }
    }

    return arr[(N*M)+2].v;
}
int main()
{
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("mostra_input_7.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);

    for (t = 1; t <= T; t++)
    {
        printf("Case #%d: %d\n", t, solve(t));
    }
}