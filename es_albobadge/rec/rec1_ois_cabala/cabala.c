#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

long long max = 0;

typedef struct s_nodo {
    long long n;
    struct s_nodo *sx, *dx;
} nodo;

typedef struct s_coppia {
    int n1;
    int n2;
} coppia;

coppia get_coppia(int n) {
    coppia c[3] = {{6, 9}, {3, 9}, {3, 6}};
    return c[(n / 3) - 1];
}

nodo *crea_nodo(long long val, int corrente, int livello) {
    if(corrente == livello) return NULL;

    coppia c = get_coppia(val - ((val / 10) * 10));

    corrente++;
    nodo *node = malloc(sizeof(nodo));
    node->n = val;
    node->sx = crea_nodo((10 * val) + c.n1, corrente, livello);
    node->dx = crea_nodo((10 * val) + c.n2, corrente, livello);

    return(node);
}

nodo *crea_albero(long long radice, int livelli) {
    return crea_nodo(radice, 0, livelli);
}

void visita(nodo *root, int N, int M) {
    if(root == NULL) return;
    if((root->n / (long long)pow(10, N - 1)) > 0) {
        if(max < root->n % M) {
            max = root->n % M;
        }
    }
    visita(root->sx, N, M);
    visita(root->dx, N, M);
    return;
}


long long occulta(long long N, int M) {
    max = 0;
    nodo *root3 = crea_albero(3, N);
    nodo *root6 = crea_albero(6, N);
    nodo *root9 = crea_albero(9, N);

    visita(root3, N, M);
    visita(root6, N, M);
    visita(root9, N, M);

    return max;
}


int main() {
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        fprintf(fw, "%lld ", occulta(N, M));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);

    return 0;
}