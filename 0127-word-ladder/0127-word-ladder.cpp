class Solution {
public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        int wl = beginWord.length();
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                for (int j = 0; j < wl; j++) {
                    string temp = word;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == word[j]) continue;
                        temp[j] = ch;
                        if (temp == endWord) return count + 1;
                        if (st.find(temp) != st.end()) {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    } 
};