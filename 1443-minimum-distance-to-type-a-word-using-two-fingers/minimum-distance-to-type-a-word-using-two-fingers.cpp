class Solution {
public:
    int dist(map<int, pair<int, int>>& mp, char to, char from) {
        int tox = mp[to - 'A'].first;
        int toy = mp[to - 'A'].second;

        int fromx = mp[from - 'A'].first;
        int fromy = mp[from - 'A'].second;

        return abs(tox - fromx) + abs(toy - fromy);
    }

    int solve(string word, int idx, int f1, int f2,
              map<int, pair<int, int>>& mp , vector<vector<vector<int>>>& dp) {
        int n = word.size();
        if (idx == n) {
            return 0;
        }
        
        if(f1==-1){
            f1=26;
        }
        if(f2==-1){
            f2=26;
        }
        if(dp[idx][f1][f2]!=-1){
            return dp[idx][f1][f2];
        }

        int d1 = 0;
        int d2 = 0;
        if (f1 == 26) {
            d1 = solve(word, idx + 1, word[idx]-'A', f2 , mp, dp);
        } else {
            d1 = dist(mp, word[idx], 'A'+f1) +
                 solve(word, idx + 1, word[idx]-'A', f2, mp, dp);
        }

        if (f2 == 26) {
            d2 = solve(word, idx + 1, f1 , word[idx]-'A', mp, dp);
        } else {
            d2 = dist(mp, word[idx], 'A'+f2) +
                 solve(word, idx + 1, f1, word[idx]-'A',  mp, dp);
        }

        return dp[idx][f1][f2]=min(d1, d2);
    }
    int minimumDistance(string word) {
        map<int, pair<int, int>> mp;

        for (int i = 0; i < 26; i++) {
            mp[i] = {i / 6, i % 6};
        }
        
        vector<vector<vector<int>>> dp(301,vector<vector<int>>(27,vector<int>(27,-1)));
        return solve(word, 0, -1 , -1 , mp ,dp );
    }
};