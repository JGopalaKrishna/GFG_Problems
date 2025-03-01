//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> countStack;
        stack<string> resultStack;
        int i = 0, num = 0;
        string curr = "";

        while (i < s.length()) {
            if (isdigit(s[i])) {
                num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                countStack.push(num);
            } 
            else if (s[i] == '[') {
                resultStack.push(curr);
                curr = "";
                i++;
            } 
            else if (s[i] == ']') {
                int n = countStack.top();
                countStack.pop();
                string temp = resultStack.top();
                resultStack.pop();
                for (int j = 0; j < n; j++) {
                    temp += curr;
                }
                curr = temp;
                i++;
            } 
            else {
                curr += s[i];
                i++;
            }
        }
        return curr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends