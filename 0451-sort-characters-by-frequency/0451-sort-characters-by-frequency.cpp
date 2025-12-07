class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> um ;
        for(int i=0;i<s.size();i++) {
            um[s[i]]++;
        }
        vector<pair<int,char>> v ;
        for(auto &it : um) {
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
         string ans;
        for (auto &p : v) {
            ans.append(p.first, p.second);
        }
        return ans;

    }
};