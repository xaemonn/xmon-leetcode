class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int diags = n + m - 1;
        vector<int> ans;

        for (int i = 0; i < diags; i++) {
            vector<int> d;
            int row, col;

            if (i < m) {
                row = 0;
                col = i;
            } else {
                row = i - m + 1;
                col = m - 1;
            }

            while (row < n && col >= 0) {
                d.push_back(mat[row][col]);
                row++;
                col--;
            }

            if (i % 2 == 0) { 
                reverse(d.begin(), d.end());
            }

            ans.insert(ans.end(), d.begin(), d.end());
        }

        return ans;
    }
};
