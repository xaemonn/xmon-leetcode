class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
       
        vector<set<int>> userLang(m + 1);
        for(int i = 0; i < m; i++) {
            for(int lang : languages[i]) {
                userLang[i + 1].insert(lang);
            }
        }
        
        
        set<int> usersToTeach;
        vector<pair<int,int>> problemPairs;
        
        for(auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            
            for(int lang : userLang[u]) {
                if(userLang[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            
            if(!canCommunicate) {
                problemPairs.push_back({u, v});
                usersToTeach.insert(u);
                usersToTeach.insert(v);
            }
        }
        
        if(problemPairs.empty()) return 0;
        
        // Try each language
        int ans = INT_MAX;
        
        for(int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for(int user : usersToTeach) {
                if(userLang[user].count(lang) == 0) {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        
        return ans;
    }
};
