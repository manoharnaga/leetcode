class Solution {
public:
    vector<int> getRow(int n) {
        // if(n==1) return {1};
        n++;
        vector<int> a = {1};
        for(int i=1;i<n;i++){
            vector<int> b(i+1);
            b[0] = a[0];
            b.back() = a.back();
            for(int j=1;j<a.size();j++){
                b[j] = a[j-1]+a[j];
            }
            a = b;
        }
        return a;
    }
};