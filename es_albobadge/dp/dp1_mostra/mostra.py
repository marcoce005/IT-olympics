import sys

sys.stdin = open('mostra_input_7.txt')
sys.stdout = open('output.txt', 'w')

def solve():
    input()
    N, M = map(int, input().split())
    V = list(map(int, input().split()))
    G = list(map(int, input().split()))

    if M == 0:
        return N
    if N == 0:
        return 0

    tot = 0
    pos = 0
    for v in range(0, N):
        if len(G) == pos:
            tot += 1
            continue
        if max(G) <= V[v]:
            tot += 1
            continue
        for g in range(pos, len(G)):
            if (V[v] < G[g]):
                tot += 2
                G[g] = -1
                pos = g + 1
                break
            if g == len(G) - 1 and V[v] > G[g]:
                tot += 1
                break
         
        
    return tot


T = int(input())

for t in range(1, T+1):
    print("Case #" + str(t) + ":", solve())