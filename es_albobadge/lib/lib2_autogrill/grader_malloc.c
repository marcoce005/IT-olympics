#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

long long aperti[100000];
int current_index = 0;
int real_size = 0;
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int get_real_size() {
    int array_size = sizeof(aperti) / sizeof(long long);
    int size = 0;
    for (int i = 0; i < array_size; i++)
    {
        if(aperti[i] != 0)
            size++;
    }
    real_size = size;
    return size;
}
void inizia()
{
    return;
}

void apri(long long p)
{
    aperti[current_index++] = p;
    get_real_size();
}

void chiudi(long long p)
{
    int array_size = sizeof(aperti) / sizeof(long long);
    int index = -1;
    for (int i = 0; i < array_size; i++)
    {
        if(aperti[i] == p)
            index = i;
    }

            for(int i=index; i<get_real_size()-1; i++)
        {
            aperti[i] = aperti[i + 1];
        }
        aperti[real_size] = 0;
    real_size--;
}

long long chiedi(long long p)
{
    get_real_size();
    if (real_size == 0)
        return -1;
    qsort(aperti, real_size, sizeof(long long), cmpfunc);
    for (size_t i = 0; i < real_size; ++i)
    {
        if (aperti[i] > p)
        {
            if (i == 0)
            {
                return aperti[i];
            }
            int prev = aperti[i - 1];
            if (prev > 10000)
            {
                return aperti[i];
            }
            if (abs(p - prev) > abs(p - aperti[i]))
                return prev;
            else
                return aperti[i];
        }
        else if (aperti[i] == p)
            return aperti[i];
    }

    return -1;
}

int main()
{
    FILE *fptr;
    fptr = fopen("autogrill.input0.txt", "r");

    char buf[10];
    fgets(buf, 10, fptr);
    int Q = atoi(&buf[0]);
    inizia();

    char buffer[100];
    int i = 0;

    FILE *fout;
    fout = fopen("output.txt", "w");

    for (size_t i = 0; i < Q; i++)
    {
        fgets(buffer, 100, fptr);
        char t = buffer[0];
        long long p = atoi(&buffer[2]);
        if (t == 'a')
            apri(p);
        else if (t == 'c')
            chiudi(p);
        else
        {
            fprintf(fout, "%i\n", chiedi(p));
        };
    }

    return 0;
}