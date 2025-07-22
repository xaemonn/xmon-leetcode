class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0;
        map<int,int> mp;
        long long sum=0;
        long long ans=0;
        for(int r=0; r<nums.size(); r++){
            sum+=nums[r];
            mp[nums[r]]++;
           

            while(mp[nums[r]]>1){
                mp[nums[l]]--;
                sum-=nums[l];
                l++;
            }

             ans=max(sum,ans);

        }

        return ans;
    }
};