import sys

# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

sys.stdin = open('./newlines_input_1.txt')
sys.stdout = open('output.txt', 'w')


def solve(t):
    input() # prima riga vuota

    N = int(input().strip())
    W = list(map(int, input().strip().split()))
    W.append(-1)

    cont = 0
    line = []
    little = []

    """ for x in W:
        if x != -1:
            cont += x + 1
        else:
            cont -= 1
            line.append(cont)
            cont = 0 """

    for i in range(0, len(W)):
        if W[i] != -1:
            cont += W[i] + 1
        else:
            cont -= 1
            line.append(cont)
            try:
                little.append(cont + 1 + W[i + 1])
            except:
                break
            cont = 0
    k1 = max(line)
    k2 = min(little) - 1

    print(f"Case #{t}: {k1} {k2}")


T = int(input().strip())

for t in range(1, T + 1):
    solve(t)