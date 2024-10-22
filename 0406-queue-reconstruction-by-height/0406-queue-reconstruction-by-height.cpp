class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),[](const auto& x,const auto& y){
            if(x[0]==y[0]) return x[1]<y[1];
            
            return x[0]>y[0];
        });
        vector<int> a;
        a.push_back(0);
        int n = v.size();
        
        for(int i=1;i<n;i++){
            int cnt = 0;
            if(v[i][1]==0){
                a.insert(a.begin(),i);
                continue;
            }
            int j=0;
            int flag = 0;
            for(;j<a.size();j++){
                if(v[a[j]][0]>=v[i][0]) cnt++;
                if(cnt==v[i][1]) break;
            }
            a.insert(a.begin()+j+1,i);
            // cout<<(j+1)<<" "<<a.size()<<"kk\n";
            // cout<<(j==((int)a.size()-1))<<"kk2\n";
            // if((j+1)==(int)a.size()) a.push_back(i);
        }
        
        // cout<<"[";
        // for(auto& it: v) cout<<"["<<it[0]<<","<<it[1]<<"],";
        // cout<<"]\n";
        vector<vector<int>> res;
        for(int i: a) res.push_back(v[i]);
        return res;
    }
};