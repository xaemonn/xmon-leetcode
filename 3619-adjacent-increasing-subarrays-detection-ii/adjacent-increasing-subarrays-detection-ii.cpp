class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> end(n,1);
        for(int i=1; i<n;i++){
            if(nums[i]>nums[i-1]){
                end[i]=end[i-1]+1;
            }
        } //max len inc subarray ending at i

        vector<int> start(n,1);

        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                start[i]=start[i+1]+1;
            }
        } //max len inc subarray starting at i

        int ans=1;

        for(int i=0; i<n-1 ;i++){
            ans=max(ans,min(end[i],start[i+1]));
        }

        return ans;


    }
};