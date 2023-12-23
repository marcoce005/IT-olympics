import sys
from collections import defaultdict

sys.stdin = open('cestini_input_1.txt')
sys.stdout = open('output.txt', 'w')

def solve(t):
    input() # Prima riga vuota

    N, M, Q = map(int, input().strip().split())
    S = input().strip()

    pile = defaultdict(list)
    for i in range(0, M):
        pile[str(i)] = []
    for c in S:
        pile["0"].insert(0, c)

    risposta = ""
    for i in range(Q):
        w, *args = input().strip().split()
        a, b = map(int, args)

        if w == 's':
            tmp = pile[str(a)][0]
            pile[str(a)].pop(0)
            pile[str(b)].insert(0, tmp)
            pass

        elif w == 'c':
            risposta += pile[str(a)][len(pile[str(a)]) - b - 1]


    print(f"Case #{t}:", risposta)


T = int(input().strip())

for t in range(1, T+1):
    solve(t)

sys.stdout.close()