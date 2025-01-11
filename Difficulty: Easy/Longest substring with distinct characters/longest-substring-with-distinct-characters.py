#User function Template for python3

class Solution:
    def longestUniqueSubstr(self, s):
        # code here
        last_seen={}
        max_len=0
        start=0
        
        for end in range(len(s)):
            if s[end] in last_seen and last_seen[s[end]]>= start:
                start = last_seen[s[end]]+1
            last_seen[s[end]]=end
            max_len = max(max_len,end-start+1)
        return max_len


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        ans = solObj.longestUniqueSubstr(s)

        print(ans)

        print("~")
# } Driver Code Ends