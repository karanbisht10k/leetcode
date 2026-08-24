class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int>& cookies, vector<int>& child, int index) {
        if (index == cookies.size()) {
            int unfairness = 0;
            for (int x : child) {
                unfairness = max(unfairness, x);
            }
            ans = min(ans, unfairness);
            return;
        }
        for (int i = 0; i < child.size(); i++) {
            if (i > 0 && child[i] == child[i - 1])
                continue;

            child[i] += cookies[index];
            solve(cookies, child, index + 1);
            child[i] -= cookies[index];
            if (child[i] == 0)
                break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k, 0);
        solve(cookies, child, 0);
        return ans;
    }
};