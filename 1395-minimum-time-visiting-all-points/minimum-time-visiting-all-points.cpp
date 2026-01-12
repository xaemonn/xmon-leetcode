class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;

        for(int i=1; i<points.size(); i++){
            int x2=points[i][0];
            int y2=points[i][1];
            int x1=points[i-1][0];
            int y1=points[i-1][1];

            int val1=abs(x2-x1);
            int val2=abs(y2-y1);
            ans+=max(val1,val2);
        }

        return ans;
    }
};