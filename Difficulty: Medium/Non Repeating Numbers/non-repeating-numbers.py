#User function Template for python3

class Solution:
	def singleNumber(self, arr):
		# Code here
		l=[0]*(max(arr)+1)
		for i in arr:
		    l[i]^=i
		ans = []
		for i in l:
		    if i != 0:
		        ans.append(i)
		return ans
		


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        ans = ob.singleNumber(arr)

        print(" ".join(map(str, ans)))
        tc -= 1
        print("~")

# } Driver Code Ends