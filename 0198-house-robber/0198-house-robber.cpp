class Solution {
public:
    int rob(vector<int>& a) {
        int x = 0,y = 0;
        for(int i=0;i<a.size();i++){
            if(i%2){
                x = max(x+a[i],y);
            }
            else{
                y = max(x,y+a[i]);
            }
        }
        return  max(x,y);
    }
};