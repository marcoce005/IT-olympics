import sys

# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

sys.stdin = open('muro_input_1.txt')
sys.stdout = open('output.txt', 'w')


def solve():
    input() # prima riga vuota

    N, Q = map(int, input().split())
    L = list(map(int, input().split()))

    muro = []
    for i in range(0, N):
        muro.append(-1)

    L.sort()
    L.reverse()
    pos = 0

    for i in range(0, Q):
        if L[i] == N:
            for j in range(0, N):
                muro[j] = i
            pos = 1
        else:
            if N - pos - L[i] >= 0:
                for y in range(pos, L[i] + pos):
                        muro[y] = i
                pos += 1
            else:
                pos += 1
                break

    r = 0
    for n in set(muro):
        if n != -1:
            r += 1

    print(f"Case #{t}: {r}")


T = int(input().strip())

for t in range(1, T + 1):
    solve()