class Solution {
public:
    
    int findNextEvent(vector<vector<int>>& events, int currEnd) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] > currEnd)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int recur(vector<vector<int>>& events, int curr, int left, vector<vector<int>>& dp) {
        if (left == 0 || curr == events.size()) return 0;
        if (dp[curr][left] != -1) return dp[curr][left];

       
        int notTake = recur(events, curr + 1, left, dp);

       
        int next = findNextEvent(events, events[curr][1]);
        int take = events[curr][2] + recur(events, next, left - 1, dp);

        return dp[curr][left] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); 
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return recur(events, 0, k, dp);
    }
};
