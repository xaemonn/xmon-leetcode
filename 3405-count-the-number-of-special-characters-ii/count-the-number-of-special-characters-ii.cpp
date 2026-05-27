class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int> up(26,-1),low(26,-1);
        for(int i=0; i<n ;i++){
            if(word[i]>='A'&& word[i]<='Z'){
                if(up[word[i]-'A']==-1){
                    up[word[i]-'A']=i;
                }
            }
        }
        for(int i=n-1; i>=0 ;i--){
            if(word[i]>='a'&& word[i]<='z'){
                if(low[word[i]-'a']==-1){
                 low[word[i]-'a']=i;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<26 ;i++){
            if(low[i]!=-1 && up[i]!=-1 && low[i]<up[i]){
                cout<<i<<" ";
                cnt++;
            }
        }
        return cnt;
    }
};