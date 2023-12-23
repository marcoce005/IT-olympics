import sys

sys.stdin = open('calcio_input_2.txt')
sys.stdout = open('output.txt', 'w')

def solve(t):
    input() # prima riga vuota

    N, M, K, A, B = map(int, input().strip().split())

    X, Y = map(list, zip(*[map(int, input().strip().split()) for _ in range(K)]))

    ans = float("inf")

    space = [[0] * M for i in range(N)]
    for i in range(K):
        space[X[i]][Y[i]] += 1

    tot = 0
    for i in range(N - A + 1):
        for j in range(M - B + 1):
            for r in range(i, i + A):
                for c in range(j, j + B):
                    tot += space[r][c]
            if tot == 0:
                print(f"Case #{t}: {ans}")
                return
            if tot < ans:
                ans = tot
            tot = 0

    print(f"Case #{t}: {ans}")


T = int(input().strip())

for t in range(1, T+1):
    solve(t)

sys.stdout.close()
