class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0;
        string ans;
        int i=0;
        for(;i<min(n,m);i++){
            if(a[i]=='1' && b[i]=='1'){
                if(carry) ans+="1";
                else      ans+="0";
                carry = 1;
            }
            else if((a[i]=='0' && b[i]=='1') || (a[i]=='1' && b[i]=='0')){
                if(carry) ans += "0";
                else      ans += "1";
            }
            else{
                if(carry) ans+="1";
                else      ans+="0";
                carry = 0;
            }
        }
        // cout<<i<<"\n";
        if(i<n){
            while(i<n){
                if(a[i]=='1'){
                    if(carry) ans+="0";
                    else      ans+="1";
                }
                else{
                    if(carry) ans+="1";
                    else      ans+="0";
                    carry = 0;
                }
                i++;
            }
        }
        if(i<m){
            while(i<m){
                if(b[i]=='1'){
                    if(carry) ans+="0";
                    else      ans+="1";
                }
                else{
                    if(carry) ans+="1";
                    else      ans+="0";
                    carry = 0;
                }
                i++;
            }
        }
        if(carry) ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};