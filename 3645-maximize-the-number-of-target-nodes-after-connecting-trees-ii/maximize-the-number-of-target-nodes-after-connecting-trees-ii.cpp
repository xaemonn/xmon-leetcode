class Solution {
public:
    vector<vector<int>> build(vector<vector<int>>& edges){
        vector<vector<int>> adj(edges.size()+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    void dfs(vector<int>& color,int node, int parent , vector<vector<int>>&edges, int& even , int& odd){
        if(color[node]==0){
        even++;
        }else{
            odd++;
        }
        for(auto v:edges[node]){
            if(v!=parent){
                color[v]=color[node]^1;
                dfs(color,v,node,edges,even,odd);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
          auto listA=build(edges1);
          auto listB=build(edges2);
          vector<int> clr1(listA.size(),0);
           vector<int> clr2(listB.size(),0);
           int even1,odd1,even2,odd2;
           clr1[0]=0; clr2[0]=0;
           dfs(clr1,0,-1,listA,even1,odd1);
           dfs(clr2,0,-1,listB,even2,odd2);
           int maxx=max(even2,odd2);

           vector<int> ans(listA.size(),0);

           for(int i=0; i<listA.size();i++){
                if(clr1[i]==0){
                    
                    ans[i]=even1+maxx;
                }else{
                    ans[i]=odd1+maxx;
                }
           }

           return ans;
    }
};