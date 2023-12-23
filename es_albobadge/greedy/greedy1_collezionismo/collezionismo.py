import sys


def solve(t):
    input()

    N, K = map(int, input().strip().split())
    # N == statuine
    # K == scaffali
    C = list(map(int, input().strip().split()))
    C.sort()

    differenze = []
    for i in range(N - 1):
        differenze.append(C[i] - C[i + 1])
    differenze.sort()

    risultato = C[N - 1] - C[0]
    for i in range(K - 1):
        risultato += differenze[i]

    print(f"Case #{t}: {risultato}")

sys.stdin = open('collezionismo_input_2.txt')
sys.stdout = open('output.txt', 'w')

T = int(input().strip())

for t in range(1, T+1):
    solve(t)

sys.stdout.close()