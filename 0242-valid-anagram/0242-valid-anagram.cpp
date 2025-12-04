class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false ;
        unordered_map<char,int> um ;
        for(int i=0;i<s.size();i++) {
            um[s[i]]++;
        }
        for(int i=0;i<s.size();i++) {
            if(um[t[i]]==0) return false ;
            else um[t[i]]--;
        }
        return true;
    }
};