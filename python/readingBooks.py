n = int(input())
times = list(map(int, input().split()))

total = sum(times)
longest = max(times)

print(max(total, 2 * longest))