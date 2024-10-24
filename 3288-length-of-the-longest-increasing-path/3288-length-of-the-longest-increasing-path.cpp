class Solution {
public:
    int maxPathLength(vector<vector<int>>& coords, int k) {
    int x = coords[k][0], y = coords[k][1];
    sort(begin(coords), end(coords), [](const auto &a, const auto &b){
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
    vector<int> before, after;
    for (const auto &c : coords)
        if (c[0] < x && c[1] < y)
            insertLIS(before, c[1]);
        else if (c[0] > x && c[1] > y) 
            insertLIS(after, c[1]);
    return 1 + before.size() + after.size();
}
void insertLIS(vector<int> &ms, int y) {
    if (auto it = lower_bound(begin(ms), end(ms), y); it == end(ms))
        ms.push_back(y);
    else
        *it = y;      
}

};