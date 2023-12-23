import sys

sys.stdin = open('interruttori_input_1.txt')
sys.stdout = open('output.txt', 'w')

def solve():
    input()
    N, A, B = map(int, input().split())
    Z = [None] * A
    X = [None] * B
    Y = [None] * B

    graph = [[] for _ in range(131072)]
    distance = [None] * 131072
    visited = [None] * 131072
    queue = []

    for i in range(N):
        graph[i] = []
        distance[i] = float('inf')
        visited[i] = False

    for j in range(A):
        Z[j] = int(input())
        distance[Z[j]] = 1
        queue.append(Z[j])

    for j in range(B):
        X[j], Y[j] = map(int, input().split())
        graph[X[j]].append(Y[j])
        graph[Y[j]].append(X[j])
    
    result = 0
    while len(queue) > 0:
        head = queue.pop(0)
        if visited[head]: continue
        visited[head] = True
        result = head
        for i in graph[head]:
            distance[i] = min(distance[i], distance[head] + 1)
            queue.append(i)
    
    return (result, distance[result])


T = int(input())

for t in range(1, T+1):
    print("Case #{}: {} {}".format(t, *solve()))