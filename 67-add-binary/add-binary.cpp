class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.length();
        int n2=b.length();
        string ans="";
        if(n1<n2){
            return addBinary(b,a);
        }

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        char carry='0';
        for(int i=0; i<n2; i++){
            if(a[i]=='1' && b[i]=='1'){
                if(carry=='0'){
                    ans+='0';
                    carry='1';
                }else{
                    ans+='1';
                    carry='1';
                }
            }
            else if((a[i]=='1' && b[i]=='0') || (a[i]=='0' && b[i]=='1')){
                  if(carry=='1'){
                    ans+='0';
                  }else{
                    ans+='1';
                  }
            } else{
                if(carry=='1'){
                    ans+='1';
                }else{
                    ans+='0';
                }
                carry='0';
            }
        }

        if(n1>n2){
            for(int i=n2; i<n1; i++){
                if(a[i]=='1'){
                    if(carry=='1'){
                        ans+='0';
                        carry='1';
                    }else{
                        ans+='1';
                    }
                }else{
                    if(carry=='0'){
                        ans+='0';
                    }else{
                        ans+='1';
                        carry='0';
                    }
                }
            }
        }

        if(carry=='1'){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};