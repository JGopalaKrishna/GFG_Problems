class Solution {
  public:
   static bool cmp(int &a, int &b) {
        
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        return s1+s2 > s2+s1;
    }
    string findLargest(vector<int> &a) {
        // code here
       int sum = accumulate(a.begin(),a.end(),0);
        if(sum == 0){
            return "0";
        }
        sort(begin(a),end(a), cmp);
        string ans;
        for(int i=0;i<a.size();i++){
            ans+=to_string(a[i]);
        }
        return ans;
    }
};
//GFG POTD solution for 16 August