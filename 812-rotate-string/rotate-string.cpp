class Solution {
public:
string rotateString(string str, int k) {
    int n = str.length();
    if (n == 0) return str;  

    k = k % n; 
    if (k == 0) return str; 
    return str.substr(n - k) + str.substr(0, n - k);
}

    bool rotateString(string s, string goal) {
        for(int i=0;i<s.length();i++){
            if(rotateString(s,i)==goal)return true;
        }
        return false;
    }

    
};