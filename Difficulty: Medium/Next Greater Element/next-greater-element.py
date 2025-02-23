# User function Template for python3

class Solution:
    # Function to find the next greater element for each element of the array.
    def nextLargerElement(self, arr):
        n = len(arr)
        res = [-1] * n  # Initialize result array with -1
        stack = []  # Monotonic stack
    
        for i in range(n - 1, -1, -1):  # Traverse from right to left
            while stack and stack[-1] <= arr[i]:
                stack.pop()  # Remove elements smaller than arr[i]
    
            if stack:
                res[i] = stack[-1]  # Next greater element found
    
            stack.append(arr[i])  # Push current element to stack
    
        return res


#{ 
 # Driver Code Starts
# Initial Template for Python 3

t = int(input())  # number of test cases
for _ in range(t):
    arr = list(map(int, input().split()))  # input array
    s = Solution().nextLargerElement(arr)  # find the next greater elements

    # Output formatting
    if s:
        print(" ".join(map(str, s)))  # Print next greater elements
    else:
        print("[]")  # Print empty list if no next greater element is found
    print("~")
# } Driver Code Ends