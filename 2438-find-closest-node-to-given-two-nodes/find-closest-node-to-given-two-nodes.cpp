class Solution {
public:
    void bfs(int start, vector<int>& dist, vector<int>& edges){
        int n=edges.size();
        vector<bool> vis(n,false);
        vis[start]=true;
        dist[start]=0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
          
            if(edges[node]!=-1 && !vis[edges[node]]){
                dist[edges[node]]=dist[node]+1;
                q.push(edges[node]);
                vis[edges[node]]=true;
            }
        }


    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
          int n=edges.size();
           vector<int> dist1(n,1e9),dist2(n,1e9);
           bfs(node1,dist1,edges);
           bfs(node2,dist2,edges);

           int ans=-1;
           int mini=1e9;
           for(int i=0; i<n ;i++){
            if(mini>max(dist1[i],dist2[i])){
                mini=max(dist1[i],dist2[i]);
                ans=i;
            }
           }

           return ans;
    }
};