class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int cnt=0;
        priority_queue<int,vector<int>, greater<>> pq;
        sort(events.begin(),events.end());
       
       int idx=0;
       int n=events.size();
        for(int d=1; d<=1e5;d++){
            // end time<curr day
            while(!pq.empty() && pq.top()<d){
                pq.pop();
            }

            while(idx<n && events[idx][0]==d){
                pq.push(events[idx][1]);
                idx++;
            }

            if(pq.empty()){
                continue;
            }else{
                cnt++;  //attend the event
                pq.pop();
            }


        }

        return cnt;
    }
};