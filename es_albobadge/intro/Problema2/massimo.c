#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 1000

// Declaring variables
static int N;
static int V[MAXN];

// Declaring functions
int trova_massimo(int N, int V[], int start, int end) {
    int i, j, pivot, temp;

   if(start<end){
      pivot=start;
      i=start;
      j=end;     
      
      while(i<j){
         while(V[i]<=V[pivot]&&i<end)
            i++;
         while(V[j]>V[pivot])
            j--;
         if(i<j){   
            temp=V[i];
            V[i]=V[j];
            V[j]=temp;
         }
      }

      temp=V[pivot];
      V[pivot]=V[j];
      V[j]=temp;
      trova_massimo(N,V,start,j-1);
      trova_massimo(N,V,j+1,end);
   }
   return V[N - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));

    for(int i = 0; i < N; i++) {
        assert(1 == scanf("%d", &V[i]));
    }

    printf("%d\n", trova_massimo(N, V, 0, N - 1));

    return 0;
}
