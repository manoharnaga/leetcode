class Solution {
public:
    string removeKdigits(string num, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<num.size();i++){
            int val = num[i]-'0';
            while(!pq.empty() && pq.top().first>val && k>0){
                pq.pop();
                k--;
            }
            pq.push({val,i});
        }
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        //     pq.pop();
        // }
        while(!pq.empty() && k>0){
            pq.pop();
            k--;
        }
        priority_queue<pair<int,int>> temp;
        while(!pq.empty()){
            temp.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        string ans;
        while(!temp.empty()){
            ans+=to_string(temp.top().second);
            temp.pop();
        }
        while(!ans.empty() && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans.empty()) return "0";
        return ans;
    }
};