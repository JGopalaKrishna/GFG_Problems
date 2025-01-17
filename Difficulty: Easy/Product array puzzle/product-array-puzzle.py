#User function Template for python3

class Solution:
    def productExceptSelf(self, arr):
        #code here
        n = len(arr)
        ans = [1] * n
        
        # Left product
        left = 1
        for i in range(n):
            ans[i] = left
            left *= arr[i]
        
        # Right product
        right = 1
        for i in range(n - 1, -1, -1):
            ans[i] *= right
            right *= arr[i]
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):

        arr = [int(x) for x in input().split()]

        ans = Solution().productExceptSelf(arr)
        print(*ans)
        print("~")

# } Driver Code Ends