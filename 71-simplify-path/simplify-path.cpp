class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string temp;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (temp == "..") {
                    if (!st.empty()) st.pop_back();
                } else if (!temp.empty() && temp != ".") {
                    st.push_back(temp);
                }
                temp = "";
            } else {
                temp += path[i];
            }
        }
        string ans = "";
        for (string s : st)
            ans += "/" + s;

        return ans.empty() ? "/" : ans;
    }
};