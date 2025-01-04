from collections import defaultdict

class Solution:
    def subarrayXor(self, arr, k):
        # code here
        prefix_xor = 0
        result = 0
        freq_map = defaultdict(int)
        freq_map[0] = 1  
        for num in arr:
            prefix_xor ^= num
            if prefix_xor ^ k in freq_map:
                result += freq_map[prefix_xor ^ k]
            freq_map[prefix_xor] += 1
        
        return result

#{ 
 # Driver Code Starts
if __name__ == "__main__":
    tc = int(input())

    for _ in range(tc):
        arr = list(map(int, input().split()))
        k = int(input())

        obj = Solution()
        print(obj.subarrayXor(arr, k))
        print("~")

# } Driver Code Ends