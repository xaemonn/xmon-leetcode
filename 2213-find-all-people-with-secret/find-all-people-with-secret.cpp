class Solution {
public:
   
    bool comp(vector<int>& a, vector<int> & b){
        return a[2]<b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>> mp;
        for(auto i:meetings){
            int u=i[0];
            int v=i[1];
            int t=i[2];
            mp[t].push_back({u,v});
        }
       vector<bool> knows(n,false);
       knows[0]=true;
       knows[firstPerson]=true;
       
        for(auto it:mp){
            queue<int> q;
            map<int,vector<int>> adj;
            auto temp=it.second;
            set<int> seen;
            for(auto p:temp){
               int u=p.first;
               int v=p.second;
               adj[u].push_back(v);
               adj[v].push_back(u);
               if(knows[u] && !seen.count(u)){
                q.push(u);
                seen.insert(u);
               }
               if(knows[v] && !seen.count(v)){
                q.push(v);
                seen.insert(v);
               }
            }

          

            while(!q.empty()){
                auto node=q.front();
                q.pop();
                for(auto nnode:adj[node]){
                    if(!knows[nnode])
                   { knows[nnode]=true;
                    q.push(nnode);}
                }
            }
        }


        vector<int> ans;
        for(int i=0; i<n; i++){
            if(knows[i]){
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};