//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    string maxNum;

    void findMax(string& s, int k, int index) {
        if (k == 0 || index == s.size()) return;

        char maxDigit = *max_element(s.begin() + index, s.end());

        // Only reduce k if a better digit is available for swapping
        if (maxDigit != s[index]) {
            for (int i = s.size() - 1; i > index; --i) {
                if (s[i] == maxDigit) {
                    swap(s[i], s[index]);
                    if (s > maxNum)
                        maxNum = s;
                    findMax(s, k - 1, index + 1);
                    swap(s[i], s[index]); // backtrack
                }
            }
        } else {
            // No better digit, move to next index
            findMax(s, k, index + 1);
        }
    }

    string findMaximumNum(string& s, int k) {
        maxNum = s;
        findMax(s, k, 0);
        return maxNum;
    }
};


//GFG POTD solution for 09 May


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends