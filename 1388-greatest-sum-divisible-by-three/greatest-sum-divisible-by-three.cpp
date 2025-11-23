class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<int> mod1,mod2;
        int ans=0;
        int sum=0;

        for(int i=0;i<n ;i++){
           sum+=nums[i]%3;
           if(nums[i]%3==1){
            mod1.push_back(nums[i]);
           }else if(nums[i]%3==2){
            mod2.push_back(nums[i]);
           }
            ans+=nums[i];
        }

        if(sum%3==0){
            return ans;
        }

        sort(mod1.begin(),mod1.end());
        sort(mod2.begin(),mod2.end());

        if(sum%3==1){
            int rem1=INT_MAX;
            if(mod1.size()>=1){
                rem1=min(rem1,mod1[0]);
            }
            if(mod2.size()>=2){
                rem1=min(rem1,mod2[0]+mod2[1]);
            }
            ans-=rem1;
            return ans;
        }

        if(sum%3==2){
            int rem1=INT_MAX;
            if(mod1.size()>=2){
                rem1=min(rem1,mod1[0]+mod1[1]);
            }
            if(mod2.size()>=1){
                rem1=min(rem1,mod2[0]);
            }
            ans-=rem1;
            return ans;
        }


       return 0;

    }
};