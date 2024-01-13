class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        for(int i=0;i<a.size();i++){
            int x=a[i];
            int f = 1;
            while(!s.empty() && x<0 && s.top()>0){
                if(s.top()==abs(x)){
                    f=0;
                    s.pop();
                    break;
                }
                if(s.top()>abs(x)){
                    f=0;
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(f)
                s.push(x);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};