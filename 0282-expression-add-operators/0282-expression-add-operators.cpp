class Solution {
public:
    vector<string> ans;
    void backtrack(string &num, int idx, long long value,
    long long last, string expr, int target) {
        if (idx == num.size()) {
            if (value == target) ans.push_back(expr);
            return;
        }
        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break;
            string part = num.substr(idx, i - idx + 1);
            long long cur = stoll(part);
            if (idx == 0) backtrack(num, i + 1, cur, cur, part, target);
            else {
                backtrack(num, i + 1, value + cur, cur,expr + "+" + part, target);
                backtrack(num, i + 1, value - cur, -cur,expr + "-" + part, target);
                backtrack(num, i + 1,value - last + last * cur,last * cur,
                expr + "*" + part, target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        backtrack(num, 0, 0, 0, "", target);
        return ans;
    }
};
