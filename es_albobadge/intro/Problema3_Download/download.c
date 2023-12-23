#include <stdio.h>

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("download_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        int N, F, C;
        
        // scrivi in queste variabili la risposta
        int nf, nc;

        scanf("%d %d %d", &N, &F, &C);
        
        nf = 0;
        nc = 0;
        while (N - F >= 0)
        {
            N -= F;
            nf++;
        }

        while (N - C >= 0)
        {
            N -= C;
            nc++;
        }
        

        printf("Case #%d: %d %d\n", t, nf, nc);
    }
}
