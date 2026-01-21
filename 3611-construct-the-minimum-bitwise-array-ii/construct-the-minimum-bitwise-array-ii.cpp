class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();

        vector<int> ans(n);

        for(int i=0; i<n ;i++){
            int num=nums[i];
            if(num%2==0){
                ans[i]=-1;
                continue;
            }
            for(int bit=30; bit>=0; bit--){
                int val=(1<<bit);
                if(num&val){
                    int temp=num-val;
                    if((temp| (temp+1))==num){
                        ans[i]=temp;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};