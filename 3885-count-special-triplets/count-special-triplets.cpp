class Solution {
public:
    const int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mpl,mpr;
           
        for(int i=0; i<n ;i++){
            mpr[nums[i]]++;
        }

        int res=0;
        for(int i=0; i<n ;i++){
            int x=nums[i];

            if(--mpr[x]==0){
                mpr.erase(x);

            }

            int req=2*x;
            if(mpr.count(req) && mpl.count(req)){
                long long ways=((long long)mpl[req]* (long long)mpr[req])%mod;
                res=(res+ways)%mod;
            }

            mpl[x]++;
        }
        return res;
    }
};