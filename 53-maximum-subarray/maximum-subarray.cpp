class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int best=INT_MIN;

        for(int i=0; i<n ;i++){
            sum=max(nums[i],sum+nums[i]);
            best=max(best,sum);
           
        }

        return best;

    }
};