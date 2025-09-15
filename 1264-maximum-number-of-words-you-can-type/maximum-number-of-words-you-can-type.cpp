class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st;
        for(int i=0; i<brokenLetters.size(); i++){
            st.insert(brokenLetters[i]);
        }

        int cnt=0;
        string t=""; bool ok=true;
        for(int i=0; i<text.size(); i++){
            if(text[i]==' '){
                 t.clear();
                 if(ok){
                    cnt++;
                 }else{
                    ok=true;
                 }
            }else{
                t+=text[i];
                if(st.count(text[i])){
                    ok=false;
                }
            }
        }

        if(ok){
            cnt++;
        }

        return cnt;
    }
};