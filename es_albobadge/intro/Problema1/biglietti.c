#include <assert.h>
#include <stdio.h>
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

int compra(int N, int M, int A, int B) {
    // N biglietti singoli
    int min = N * A;

    //se basta un solo carnet allora 
    //il costo minimo è quello tra i biglietti singolo
    //ed un singolo carnet 
    if(M >= N)
        return MIN(min, B);
    
    //se invece il carnet è più piccolo di N
    //calcolo tutte le combinazioni tra carnet e biglietti
    //singoli e determino il minimo
    int nM = (int)ceil(N / (float)M);
    for (int i = nM; i > 0; i--) {
        //calcolo il numero di biglietti singoli necessari
        int d = N - (i * M);

        //calcolo il costo della coppia carnet + biglietti singoli
        int p = (i * B) + (d <= 0 ? 0 : d * A);
        min = MIN(min, p);
    }

    return min;
}

int main() {
    FILE *f_in, *f_out;
    int N, M, A, B;

    f_in = fopen("input.txt", "r");
    f_out = fopen("output.txt", "w");
    assert(NULL != f_in);
    assert(NULL != f_out);

    assert(4 == fscanf(f_in, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(f_out, "%d\n", compra(N, M, A, B));

    fclose(f_in);
    fclose(f_out);

    return 0;
}
