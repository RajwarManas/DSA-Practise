class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())return false;
        int n = s.size();
        if (n == 0) return true;
        for (int start = 0; start < n; ++start) {
            if (goal[start] != s[0]) continue;
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (s[j] != goal[(start + j) % n]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        return false;
    }
};
