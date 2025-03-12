#User function Template for python3
class Solution:
    def missingNumber(self, arr):
        # code here
        i=1
        arr.sort()
        while(i<=len(arr)):
            if(i!=arr[i-1]):
                return i
            i+=1
        return i


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    arr = list(map(int, input().split()))
    s = Solution().missingNumber(arr)
    print(s)

    print("~")
# } Driver Code Ends