class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        for(int i=0;i+n-1<m;i++){
            int f=0;
            for(int j=0;j<n;j++){
                // cout<<haystack[i]<<needle[i+j]<<" ";
                if(needle[j]!=haystack[i+j]){
                    f=1;
                    break;
                }
            }
            // cout<<"\n";
            if(!f) return i;
        }
        // cout<<"\n";
        return -1;
    }
};