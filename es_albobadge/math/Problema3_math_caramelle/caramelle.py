import sys
import math

sys.stdin = open('caramelle_input_1.txt')
sys.stdout = open('output.txt', 'w')

def solve(t):
    input()
    N = int(input().strip())
    V = list(map(int, input().strip().split()))

    lcm = 1
    for i in V:
        lcm = lcm * i // math.gcd(lcm, i)

    print(f"Case #{t}: {lcm}")


T = int(input().strip())

for t in range(1, T+1):
    solve(t)

sys.stdout.close()