import sys

# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

sys.stdin = open("./rettangolo_input_1.txt")
sys.stdout = open('output.txt', 'w')


def solve(t):
    input() # prima riga vuota

    x1, y1 = map(int, input().strip().split())
    x2, y2 = map(int, input().strip().split())
    x3, y3 = map(int, input().strip().split())

    vetX = [x1, x2, x3]
    vetY = [y1, y2, y3]

    tmp = []
    for i in vetX:
        if i not in tmp:
            tmp.append(i)
        else:
            dup = i
    tmp.remove(dup)
    x4 = tmp[0]

    tmp.clear()
    for i in vetY:
        if i not in tmp:
            tmp.append(i)
        else:
            dup = i
    tmp.remove(dup)
    y4 = tmp[0]

    print(f"Case #{t}: {x4} {y4}")


T = int(input().strip())

for t in range(1, T + 1):
    solve(t)

sys.stdout.close()