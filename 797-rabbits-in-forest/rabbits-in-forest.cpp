class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(auto it:answers){
            mp[it]++;
        }

        int ans=0;
        for(auto it:mp){
            int grp_size=it.first+1;
            int rabbits=it.second;
            int groups=ceil((double)rabbits/(double)grp_size);
            ans+=groups*(grp_size);
        }

        return ans;
    }
};