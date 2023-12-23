#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaring variables
static int N;
static long long M;
static int *V;
static int B;

// Declaring functions
int quadri(int N, long long M, int *V)
{
      int b=0, c, i, j=0;
    long long s=0;
    bool modificato=false;
    
    for(i=0; i<N; i++) {
        s += V[i];
        if(s>M) {
            modificato=true;
            break;
        } 
        b++;
    }
    if(modificato==false) return b;
    
    for(int i=1; i<N; i++) {
        c=0;
        s=0;
        j=i;
        modificato=false;
        for(int j=i; j<N; j++) {
            s += V[j];
            if(s>M) {
                modificato=true;
                break;
            }
            c++;
        }
        if(b>c && modificato) b=c;
        else {
            if(modificato==false) break;
        }
    }
    return b;
};

int main()
{
    FILE *fr, *fw;

    fr = fopen("abc_quadri.input26.txt", "r");
    fw = fopen("output.txt", "w");

    // Iterators used in for loops
    int i0;

    // Reading input
    fscanf(fr, "%d %lld", &N, &M);
    V = (int *)malloc(N * sizeof(int));
    for (i0 = 0; i0 < N; i0++)
    {
        fscanf(fr, "%d", &V[i0]);
    }

    // Calling functions
    B = quadri(N, M, V);

    // Writing output
    fprintf(fw, "%d\n", B);

    fclose(fr);
    fclose(fw);
    return 0;
}
