class Solution {
  public:
    bool check(vector<int>& arr, int h){
        int cnt = 0;
        for(int i:arr){
            cnt += (i>=h);
        }
        return cnt>=h;
    }
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        int e = arr[0];
        for(int i=1;i<n;i++){
            e = max(arr[i], e);
        }
        int s = 0;
        int ans = 0;
        while(s<=e){
            int mid = (s+e) / 2;
            if(check(arr, mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};
//GFG POTD solution for 18 August