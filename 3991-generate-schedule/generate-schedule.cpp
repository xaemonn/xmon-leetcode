class Solution {
public:

    bool recur(int day,vector<pair<int,int>>& v, vector<vector<int>>& ans,vector<int>& last, int total,vector<bool>& vis){
        if(day==total){
            return true;
        }

        

        for(int i=0; i<v.size(); i++){
             if(vis[i]) continue;
            int home=v[i].first;
            int away=v[i].second;
            if(last[home]!=day-1 && last[away]!=day-1){
                     int last1=last[home];
                     int last2=last[away];
                    ans.push_back({home,away});
                    last[home]=day;
                    last[away]=day;
                     vis[i]=true;
                     if(recur(day+1,v,ans,last,total,vis)){
                         return true;
                     }

                    vis[i]=false;
                last[home]=last1;
                last[away]=last2;
                ans.pop_back();
                    
                }
        }


        return false;
    }
    vector<vector<int>> generateSchedule(int n) {
        vector<pair<int,int>> v;
        int total=n*(n-1);

        for(int i=0; i<n ;i++){
            for(int j=0; j<n;j++){
                if(i!=j)
                {v.push_back({i,j});}
            }
        }

        vector<vector<int>> ans;

        vector<int> last(n,-3);

        int day=0;
         vector<bool> vis(total,false);
         random_shuffle(v.begin(), v.end());

        if(recur(day,v,ans,last, total,vis)){
            return ans;
        }else{
            return {};
        }

       


        return ans;
        
    }
};