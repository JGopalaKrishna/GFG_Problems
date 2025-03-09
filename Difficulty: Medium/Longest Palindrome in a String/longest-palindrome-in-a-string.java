//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();

            Solution ob = new Solution();
            System.out.println(ob.longestPalindrome(S));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    static String expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return s.substring(left + 1, right);
    }

    static String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }

        String longestPalin = "";
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes (single character center)
            String pal1 = expandAroundCenter(s, i, i);
            if (pal1.length() > longestPalin.length()) {
                longestPalin = pal1;
            }

            // Even length palindromes (two character center)
            String pal2 = expandAroundCenter(s, i, i + 1);
            if (pal2.length() > longestPalin.length()) {
                longestPalin = pal2;
            }
        }

        return longestPalin;
    }
}