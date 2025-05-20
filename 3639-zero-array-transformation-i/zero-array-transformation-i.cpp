class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> cnt(n+1,0);
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            cnt[l]+=1;
            cnt[r+1]-=1;
        }

      
        for(int i=1; i<=n; i++){
            cnt[i]+=cnt[i-1];
        }

        for(int i=0; i<n ;i++){
            if(nums[i]>cnt[i]){
                return false;
            }
        }

        return true;
    }
};