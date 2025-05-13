class Solution {
public:
    int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);

        for(auto ch:s){
            cnt[ch-'a']++;
        }

        for(int i=0; i<t; i++){
            vector<int> next(26);
            next[0]=cnt[25];   //a can come from z
            next[1]=(cnt[25]+cnt[0])%mod;   //b can come from z and a
            for(int i=2; i<26;i++){
                next[i]=cnt[i-1];
            }

            cnt=move(next);
        }

        int ans=0;
        for(int i=0; i<26;i++){
            ans=(ans+cnt[i])%mod;
        }

        return ans;
    }
};