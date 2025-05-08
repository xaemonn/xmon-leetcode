class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>,   greater<pair<pair<int,int>,pair<int,int>>>>  pq;

        pq.push({{0,0},{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first.first;
            int type=it.first.second;
            int x=it.second.first;
            int y=it.second.second;

            if(x+1<n){
                int newtime=0;
                if(type==0) {newtime= max(time+1, moveTime[x+1][y]+1);}
               else{  newtime= max(time+2, moveTime[x+1][y]+2);}

               if(dist[x+1][y]>newtime){
                    dist[x+1][y]=newtime;
                    pq.push({{newtime,!type},{x+1,y}});
            }
            }

            if(y+1<m){
                int newtime=0;
                if(type==0) {newtime= max(time+1, moveTime[x][y+1]+1);}
               else{ newtime= max(time+2, moveTime[x][y+1]+2);}

               if(dist[x][y+1]>newtime){
                    dist[x][y+1]=newtime;
                    pq.push({{newtime,!type},{x,y+1}});
            }
            }
             if(y-1>=0){
                int newtime=0;
                if(type==0) {newtime= max(time+1, moveTime[x][y-1]+1);}
               else{ newtime= max(time+2, moveTime[x][y-1]+2);}

               if(dist[x][y-1]>newtime){
                    dist[x][y-1]=newtime;
                    pq.push({{newtime,!type},{x,y-1}});
            }
            }
            if(x-1>=0){
                int newtime=0;
                if(type==0) {newtime= max(time+1, moveTime[x-1][y]+1);}
               else{ newtime= max(time+2, moveTime[x-1][y]+2);}

               if(dist[x-1][y]>newtime){
                    dist[x-1][y]=newtime;
                    pq.push({{newtime,!type},{x-1,y}});
            }
            }
        }
        return dist[n-1][m-1];
    }
};