import math

def solve():
    n, a, b = map(int, input().split())
    gcd_ab = math.gcd(a, b)

    c = list(map(int, input().split()))

    for i in range(n):
        c[i] %= gcd_ab

    c.sort()

    min_range = c[-1] - c[0]

    for i in range(n - 1):
        min_range = min(min_range, c[i] + gcd_ab - c[i + 1])

    print(min_range)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
