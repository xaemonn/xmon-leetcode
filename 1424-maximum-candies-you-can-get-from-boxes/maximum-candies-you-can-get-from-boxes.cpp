class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, 
                   vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {
        
        int n = status.size();
        queue<int> q;
        vector<bool> hasbox(n, false);     
          
        vector<bool> vis(n, false);   
        
        for (int box : initialBoxes) {
            hasbox[box] = true;
            if(status[box]==1)
            {q.push(box);}
        }
        
        int ans = 0;
        
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            
           if(vis[box]) continue;
           vis[box]=true;
           ans+=candies[box];


           for(int key: keys[box]){
            status[key]=1;
            if(hasbox[key] && !vis[key]){
                q.push(key);
            }
           }
            
           
            for (int box2 : containedBoxes[box]) {
                hasbox[box2]=true;
                if(status[box2]==1 && !vis[box2]){
                    q.push(box2);
                }
            }

        }
        
        return ans;
    }
};
