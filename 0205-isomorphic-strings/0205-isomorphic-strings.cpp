class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false ;
        unordered_map<char,char> stot,ttos;
        for(int i=0;i<s.size();i++) {
            char a=s[i];
            char b=t[i];
            if(stot.find(a)!=stot.end()&&stot[a]!=b) return false;
            if(ttos.find(b)!=ttos.end()&&ttos[b]!=a) return false;
            stot[a]=b;
            ttos[b]=a;
        }
        return true;
    }
};