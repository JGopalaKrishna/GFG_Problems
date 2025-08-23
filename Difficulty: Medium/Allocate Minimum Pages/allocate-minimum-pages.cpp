class Solution {
    public:
    bool isValid(vector<int>&a,int mid,int k){
        int sum=0;
        int cnt=1;
        for(auto i:a){
            sum+=i;
            if(sum>mid){
                cnt++;
                sum=i;
            }
            if(cnt>k) return false;
        }
        return true;
    }
    int findPages(vector<int> &a, int k) {
        // code here
        if(a.size()<k) return -1;
        int low=*max_element(a.begin(),a.end());
        int high=0;
        for(auto i:a)
            high+=i;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(a,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
//GFG POTD solution for 23 August