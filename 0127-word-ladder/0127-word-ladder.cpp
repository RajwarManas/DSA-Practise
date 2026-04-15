class Solution {
public:
    bool oneLetterDiff(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int s=wordList.size(),count=0;
        vector<int> vis(s,0);
        queue<string> q;
        bool wordFound=false;
        q.push(beginWord);
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                auto word=q.front();
                if(word==endWord) {
                    while(!q.empty()) q.pop();
                    wordFound=true;
                    break;
                }
                q.pop();
                for(int i=0;i<s;i++) {
                    if(oneLetterDiff(wordList[i],word)&&!vis[i]) {
                        q.push(wordList[i]);
                        vis[i]=1;
                    }
                }
            }
            count++;
        }
        return wordFound? count: 0 ;
    }
};