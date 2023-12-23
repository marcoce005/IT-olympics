#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

// Declaring variables
static int N;
static int* V;
static long long int numero_ribaltamenti = 0;

int Max(int n, int* arr) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] >= max) { max = arr[i]; }
    return max;
}

// Declaring functions
long long int paletta_sort(int N, int* V) {
    int max = Max(N, V), index_max, cont = 0;
    for (int i = 0; i < N; i++) {
        if (V[i] == max) {
            index_max = i;
            while (index_max != N - 1) {
                if (V[index_max + 2] <= max) {
                    numero_ribaltamenti++;
                    V[index_max] = V[index_max + 2];
                    V[index_max + 2] = max;
                    index_max += 2;
                } else {
                    numero_ribaltamenti = -1;
                    return -1;
                }
            }
            paletta_sort(--N, V);
        }
    }
    return numero_ribaltamenti;
}

int main() {
    freopen("input00.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    V = (int*)malloc(N * sizeof(int));
    for (int i0 = 0; i0 < N; i0++)
        fscanf(stdin, "%d ", &V[i0]);
    
    // Calling functions
    numero_ribaltamenti = paletta_sort(N, V);

    // Writing output
    fprintf(stdout, "%lld\n", numero_ribaltamenti);
    
    //fclose(fr);
    //fclose(fw);
    return 0;
}
