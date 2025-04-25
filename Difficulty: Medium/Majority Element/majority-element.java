//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Geeks {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().majorityElement(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static int majorityElement(int arr[]) {
        // code here
        int candidate = 0;
        for(int i = 0; i < 32; ++i){
            int x = 1 << i;
            int count = 0;
            for(int j = 0 ;j < arr.length; ++j){
                if((arr[j] & x) != 0){
                    ++count;
                }
            }
            
            if(count > arr.length / 2){
                candidate |= x;
            }
        }
        
        int count = 0;
        for(int num : arr){
            if(candidate== num){
                ++count;
            }
        }
        
        return count > arr.length / 2 ? candidate : -1;
    }
}