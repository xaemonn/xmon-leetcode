class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int len=s.length();
        vector<bool> ok(len,true);
        string t="";

        for(int i=0; i<len ;i++){
            if(s[i]=='*'){
                ok[i]=false;
                auto it=pq.top();
                pq.pop();
                ok[-it.second]=false;
            }else{
                pq.push({s[i],-i});
            }
        }

        for(int i=0; i<len;i++){
            if(ok[i]){
                t+=s[i];
            }
        }

       

        return t;
    }
};