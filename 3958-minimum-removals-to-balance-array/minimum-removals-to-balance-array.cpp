class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=n;
        int j=0;
        for(int i=0; i<n ;i++){
            while(j<n && nums[j]<=1LL*nums[i]*k){
                j++;
            }
            int arr_len=j-i;  //which we are keepin
            int dlt=n-arr_len;
            ans=min(ans,dlt);
        }
        return ans;
    }
};