class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);

        for(int i=0; i<n ;i++){
            int val=-1;
            for(int j=0; j<nums[i]; j++){
                if((j| (j+1))==nums[i]){
                    val=j;
                    break;
                }
            }
            ans[i]=val;
        }

        return ans;
    }
};