class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(int x:nums) mp[x]++;
        for(auto x:mp) pq.push({x.second,x.first});
        vector<int> ans;
        for(int i=1;i<=k;i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};