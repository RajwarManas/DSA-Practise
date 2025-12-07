class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, n = s.size();
        int arr[91] = {0};
        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && arr[s[i]] < arr[s[i + 1]]) {
                ans -= arr[s[i]];
            } else
                ans += arr[s[i]];
        }
        return ans;
    }
};