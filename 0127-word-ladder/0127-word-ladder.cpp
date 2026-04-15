class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string,bool> um;
        unordered_map<string,bool> vis;
        int count=1,wl=beginWord.length();
        bool possible=0,wordFound=0;
        for(string& x:wordList) {
            if(x==endWord) possible=1;
            um[x]=1;
            vis[x]=0;
        }
        if(!possible) return 0;
        q.push(beginWord);
        vis[beginWord]=1;
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                string word=q.front();
                q.pop();
                for(int j=0;j<wl;j++) {
                    string copy=word;
                    for(int k=0;k<26;k++) {
                        copy[j]='a'+k;
                        if(um.find(copy)!=um.end()&&vis[copy]==0) {
                            q.push(copy);
                            vis[copy]=1;
                            if(copy==endWord) return count+1;
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
};