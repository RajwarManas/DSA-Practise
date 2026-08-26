class Solution {
public:
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> ans;

    void dfs(string word, string& beginWord, vector<string>& path) {
        if (word==beginWord) {
            reverse(path.begin(),path.end());
            ans.push_back(path);
            reverse(path.begin(),path.end());
            return;
        }
        for (string& p : parent[word]) {
            path.push_back(p);
            dfs(p,beginWord,path);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        bool found = false;
        while(!q.empty() && !found) {
            int size=q.size();
            unordered_set<string> levelVisited;
            for(int i=0;i<size;i++) {
                string word=q.front();
                q.pop();
                string next=word;
                for(int j=0;j<word.size();j++) {
                    char org=next[j];
                    for(char k='a';k<='z';k++) {
                        if (k==org) continue;
                        next[j]=k;
                        if (!dict.count(next)) continue;
                        if (!visited.count(next)) {
                            visited.insert(next);
                            levelVisited.insert(next);
                            q.push(next);
                            parent[next].push_back(word);
                        }
                        else if (levelVisited.count(next)) {
                            parent[next].push_back(word);
                        }
                        if (next==endWord) found=true;
                    }
                    next[j]=org;
                }
            }
        }
        if (!visited.count(endWord)) return {};
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);
        return ans;
    }
};