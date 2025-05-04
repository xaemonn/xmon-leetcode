class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        map<pair<int,int>,int> mp;
        for(int i=0; i<n ;i++){
            sort(dominoes[i].begin(),dominoes[i].end());
            mp[{dominoes[i][0],dominoes[i][1]}]++;
        }

        int ans=0;
        for(auto it:mp){
            if(it.second>=2){
                ans+=((it.second)*(it.second-1)/2);
            }
        }

        return ans;
    }
};