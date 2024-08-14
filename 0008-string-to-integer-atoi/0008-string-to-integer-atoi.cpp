class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int start = 0;
        for(;start<s.size();start++){
            if(s[start]=='-') sign = -1;
            if(s[start]=='+' || s[start]=='-'){
                if(start+1<s.size() && !(s[start+1]>='0' && s[start+1]<='9')) return 0;
            }
            if(s[start]>='0' && s[start]<='9') break;
            if(!(s[start]=='-' || s[start]=='+' || s[start]==' ')) return 0;
        }
        while(start<s.size() && s[start]=='0') start++;
        if(start==s.size() || !(s[start]>='0' && s[start]<='9')) return 0;
        int end = start;
        for(;end+1<s.size();end++){
            if(!(s[end+1]>='0' && s[end+1]<='9')) break;
        }
        if(start>end) return 0; 
        string v = s.substr(start,end-start+1);
        s = v;
        long long val = 0;
        long long mult = 1;
        for(int i=s.size()-1;i>=0;i--){
            val += (mult*(s[i]-'0'));
            // if(mult==1000000000000000000){
            //     cout<<mult<<"\n";
            //     cout<<(mult>(long long)INT_MAX)
            // }
            if(mult>(long long)INT_MAX){
                // cout<<"yes\n";
                if(sign==-1) return INT_MIN;
                else return INT_MAX;
            }
            mult*=10ll;
        }
        val *= sign;
        val = min(val,(long long)INT_MAX);
        val = max(val,(long long)INT_MIN);
        return (int)val;
    }
};