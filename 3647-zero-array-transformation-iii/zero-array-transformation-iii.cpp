class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        priority_queue<int> available;   //max heap
        priority_queue<int, vector<int>, greater<int>> used;
        
        sort(queries.begin(),queries.end());

        int pos=0;   //pointer to iterate on queries
        int count=0;
        for(int i=0; i<n ;i++){

            while(pos<q && queries[pos][0]==i){
                //left end == current idx
                available.push(queries[pos][1]);
                pos++;
            }

            nums[i]-=used.size();

            while(nums[i]>0 && !available.empty() && available.top()>=i){
                // curr idx se pehle end hone vali ignore
                used.push(available.top());
                available.pop();
                nums[i]--;
                count++;
            }

            if(nums[i]>0)  return -1;
            

            // remove query ending at curr idx
            while(!used.empty() && used.top()==i){
                used.pop();
            }
        } 
       return queries.size()- count;
    }
};