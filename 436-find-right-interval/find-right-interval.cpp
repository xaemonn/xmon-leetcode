class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
       int n=intervals.size();
       for(int i=0; i<n;i++){
       intervals[i].push_back(i);
       }

      
       sort(intervals.begin(),intervals.end());

       vector<int> ans(n);
       vector<int> start(n);
       for(int i=0; i<n ;i++){
        start[i]=intervals[i][0];
       }
       for(int i=0; i<n ;i++){
        auto& it=intervals[i];
         int st=it[0];
         int end=it[1];
         int idx=it[2];
         auto x=lower_bound(start.begin()+i,start.end(),end)-start.begin();
         if(x>=0 && x<n)
         {ans[idx]=intervals[x][2];}
         else{
            ans[idx]=-1;
         }

       }

       return ans;
    }
};