def maxSum(n, nums):
    ans = nums[0]
    maxEnd = nums[0]
    for i in range(1,n):
        maxEnd = max(maxEnd+nums[i], nums[i])
        ans = max(ans, maxEnd)
    
    return ans

n = int(input())
nums = list(map(int, input().split()))
res = maxSum(n, nums)
print(res)