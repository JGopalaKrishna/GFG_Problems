//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s1 = br.readLine();
            String s2 = br.readLine();

            Solution ob = new Solution();
            int ans = ob.editDistance(s1, s2);
            System.out.println(ans);

            System.out.println("~");
        }
    }
}

// } Driver Code Ends

class Solution {
    public int editDistance(String s1, String s2) {
        // Code here
        
        int n=s1.length();
        int m=s2.length();
        int[][] dp=new int[n+1][m+1];
        for(int[] row:dp)Arrays.fill(row,-1);
        return f(s1,s2,n,m,dp);
    }
    private int f(String s1,String s2, int i,int j,int[][] dp)
    {
        if(i==0)return j;
        if(j==0)return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1.charAt(i-1)==s2.charAt(j-1))
        {
            return dp[i][j]=f(s1,s2,i-1,j-1,dp);
        }
        int rem=f(s1,s2,i-1,j,dp);
        int insert=f(s1,s2,i,j-1,dp);
        int replace = f(s1,s2,i-1,j-1,dp);
        
        return dp[i][j]=1+Math.min(rem,Math.min(insert,replace));
    }
}