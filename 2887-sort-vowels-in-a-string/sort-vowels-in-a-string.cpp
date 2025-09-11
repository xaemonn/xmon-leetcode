class Solution {
public:
    string sortVowels(string s) {

        set<char> vow={'a','e','i','o','u','A','E','I','O','U'};
        vector<char> v;
        int len=s.length();
        for(int i=0; i<len;i++){
            if(vow.count(s[i])){
                v.push_back(s[i]);
                s[i]='.';
            }
        }

        sort(v.begin(),v.end());

        int idx=0;

        for(int i=0; i<len ;i++){
            if(s[i]=='.'){
                s[i]=v[idx];
                idx++;
            }
        }

        return s;
    }
};