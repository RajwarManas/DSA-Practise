class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int arr[26]= {0};
        for(int i=0;i<s.size();i++) {
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++) {
            if(arr[t[i]-'a']==0) return false;
            else arr[t[i]-'a']--;
        }
        return true;
    }
};