class Solution {
public:
    void sortColors(vector<int>& a) {
        vector<int> v(3,0);
        for(int val: a) v[val]++;
        int j=0;
        for(int i=0;i<a.size();i++){
            if(v[j]){
                a[i]=j;
                v[j]--;
            }
            else{
                j++;
                i--;
            }
        }
    }
};