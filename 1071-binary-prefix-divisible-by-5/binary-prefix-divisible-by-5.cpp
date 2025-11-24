class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> v(n);

       int prev=0;
        for(int i=0; i<n; i++){
            int curr=(prev*2+nums[i])%5;
            if(curr==0){
                v[i]=true;
            }else{
                v[i]=false;
            }
            prev=curr;
        }

        return v;

    }
};