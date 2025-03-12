#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math




    
# } Driver Code Ends

#User function Template for python3

class Solution:
    
    #Function to find the first position with different bits.
    def posOfRightMostDiffBit(self,m,n):
        #Your code here
        if(n == m):
            return -1
        i = 0
        while(n | m):
            i += 1
            if((n&1) != (m&1)):
                return i
            n >>= 1
            m >>= 1
        return i


#{ 
 # Driver Code Starts.
    
def main():
    
    T=int(input())
    
    while(T>0):
        
        m=int(input())
        n=int(input())
        ob=Solution()
        print(math.floor(ob.posOfRightMostDiffBit(m,n)))
        
        
        
        
        T-=1
        print("~")
    
    




if __name__=="__main__":
    main()
# } Driver Code Ends