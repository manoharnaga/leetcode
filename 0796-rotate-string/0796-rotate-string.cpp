class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            int f = 1;
            for(int j=i,cnt=0;cnt<n;cnt++,j=(j+1)%n){
                if(s[j]!=goal[cnt]){
                    f=0;
                    break;
                }
            }
            if(f) return true;
        }
        return false;
    }
};