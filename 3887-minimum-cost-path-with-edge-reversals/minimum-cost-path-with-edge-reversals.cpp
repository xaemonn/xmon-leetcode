class Solution {
public:
    typedef long long ll;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n),rev(n);
    using p=pair<ll,ll>;
   priority_queue<p,vector<p>, greater<p>> pq;
        for(auto i:edges){
            auto u=i[0];
            auto v=i[1];
            auto w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        vector<ll> dis(n,LLONG_MAX);

       
       
         dis[0]=0;
        pq.push({0,0});
       while(!pq.empty()){

           auto it=pq.top();
           pq.pop();
           ll cost=get<0>(it);
           ll u=get<1>(it);
           


           if(cost>dis[u]){
               continue;
           }

          for(auto p:adj[u]){
              ll v=p.first;
              ll w=p.second;
              if(cost+w< dis[v]){
                  pq.push({cost+w,v});
                  dis[v]=cost+w;
              }
          }

         
           
       }

         if(dis[n-1]==LLONG_MAX ){
             return -1;
         }
       return dis[n-1];

    }
};