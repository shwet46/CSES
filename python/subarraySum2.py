import sys
input = sys.stdin.readline

def solve():
    n, x = map(int, input().split())
    sums = {0: 1}
    curr_sum = 0
    count = 0
    
    arr = list(map(int, input().split()))
    
    for a in arr:
        curr_sum += a
        count += sums.get(curr_sum - x, 0)
        sums[curr_sum] = sums.get(curr_sum, 0) + 1
    
    print(count)


if __name__ == "__main__":
    solve()