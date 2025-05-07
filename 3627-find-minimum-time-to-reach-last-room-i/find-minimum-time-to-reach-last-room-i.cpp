class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>  pq;

        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int x=it.second.first;
            int y=it.second.second;

            if(x+1<n){
                int newtime= max(time+1, moveTime[x+1][y]+1);
                if(dist[x+1][y]>newtime){
                    dist[x+1][y]=newtime;
                    pq.push({newtime,{x+1,y}});
                }
            }
             if(y+1<m){
                int newtime= max(time+1, moveTime[x][y+1]+1);
                if(dist[x][y+1]>newtime){
                    dist[x][y+1]=newtime;
                    pq.push({newtime,{x,y+1}});
                }
            }
             if(x-1>=0){
                int newtime= max(time+1, moveTime[x-1][y]+1);
                if(dist[x-1][y]>newtime){
                    dist[x-1][y]=newtime;
                    pq.push({newtime,{x-1,y}});
                }
            } if(y-1>=0){
                int newtime= max(time+1, moveTime[x][y-1]+1);
                if(dist[x][y-1]>newtime){
                    dist[x][y-1]=newtime;
                    pq.push({newtime,{x,y-1}});
                }
            }
        }

        return dist[n-1][m-1];
    }
};