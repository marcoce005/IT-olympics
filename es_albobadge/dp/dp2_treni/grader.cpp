#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int onlysuper(int n, int arr[])
{
  int tot = 0;
  for (int i = 0; i < n; i++)
    tot += arr[i];
  return tot;
}

int onlyhyper(int n, int arr[])
{
  int tot = 0, tot2 = 0;
  for (int i = 0; i < n; i += 2)
    tot += arr[i];
  for (int i = 1; i < n; i += 2)
    tot2 += arr[i];
  if (tot > tot2)
    return tot;
  else
    return tot2;
}

int special(int n, int super[], int hyper[])
{
  int tot = 0;
  super[0] > hyper[0] ? tot += super[0] : tot += hyper[0];
  for (int i = 1; i < n; i++)
  {
    if (i == n - 2)
    {
      tot += super[i] + super[i + 1];
      break;
    }
    if (super[i] + super[i + 1] > hyper[i + 1])
    {
      tot += super[i];
    }
    else
    {
      tot += hyper[++i];
    }
  }
  return tot;
}

int special2(int n, int super[], int hyper[])
{
  int tot = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == n - 2)
    {
      tot += super[i] + super[i + 1];
      break;
    }
    if (super[i] + super[i + 1] > hyper[i + 1])
    {
      tot += super[i];
    }
    else
    {
      tot += hyper[++i];
    }
  }
  return tot;
}

int tempo_massimo(int n, int super[], int hyper[])
{
  if (n == 1 && super[0] >= hyper[0])
    return super[0];
  else if (n == 1)
    return hyper[0];
  //if (n == 1) return super[0] >= hyper[0] ? super[0] : hyper[0];
	
  if (super[0] < hyper[0])
    super[0] = hyper[0];

	//super[0] = super[0] >= hyper[0] ? super[0] : hyper[0];
	
	if(hyper[1] > super[0] + super[1])
		super[1] = hyper[1];
	else
		super[1] = super[0] + super[1];
	
	for (int i = 2; i < n; i++) {
		if ((super[i-2] + hyper[i]) > (super[i-1] + super[i]))
			super[i] = super[i-2] + hyper[i];
		else
			super[i] = super[i-1] + super[i];
	}
	return super[n-1];

  /*if (n == 1 && super[0] >= hyper[0])
    return super[0];
  else if (n == 1)
    return hyper[0];

  if (hyper[1] > super[0] + super[1]) {
    super[1] = hyper[1];
  }
  else{
    super[1] = super[0] + super[1];
  }

  for (int i = 2; i < n; i++)
  {
    if ((super[i - 2] + hyper[i]) > (super[i-1] + super[i]))
    {
      super[i] = super[i - 2] + hyper[i];
    } else
    {
      super[i] = super[i - 1] + super[i];
    }
  }
  return super[n - 1];*/
}

int main()
{
  int n;
  FILE *in = stdin, *out = stdout;
  in = fopen("./input.txt", "r");
  out = fopen("./output.txt", "w");
  assert(fscanf(in, "%d", &n) == 1);

  int *a = (int *)calloc(n, sizeof(int));
  int *b = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
  {
    assert(fscanf(in, "%d", a + i) == 1);
    assert(fscanf(in, "%d", b + i) == 1);
  }

  int answ = tempo_massimo(n, a, b);
  fprintf(out, "%d\n", answ);

  free(a);
  free(b);

  fclose(in);
  fclose(out);

  return EXIT_SUCCESS;
}