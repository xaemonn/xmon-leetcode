class Solution {
public:
    typedef long long ll;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ll req = ceil((double)success / (double)spells[i]);
            auto idx = lower_bound(potions.begin(), potions.end(), req);
            ans.push_back(m - (idx - potions.begin()));
        }
        return ans;
    }
};
