class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        ll n=nums.size();
        map<int,vector<int>> mp;
        for(int i=0; i<n ;i++){
            mp[nums[i]].push_back(i);
        }

        vector<ll> ans(n,0);

        for(auto& it:mp){
            vector<int> v=it.second;
            int num=it.first;
            int sz=v.size();
            vector<ll> pref(sz,0);
            pref[0]=v[0];
            for(int i=1; i<sz; i++){
                 pref[i]=v[i]+pref[i-1];
            }

            for(int i=0; i<sz; i++){
                ll idx=v[i];
                ll l=i;
                ll r=sz-i-1;
                if(i>=1) ans[idx]= (idx*l)-pref[i-1]+ (pref[sz-1]-pref[i])- (idx*r);
                else ans[idx]= (pref[sz-1]-pref[i])- (idx*r);
            }
        }

        return ans;

    }
};