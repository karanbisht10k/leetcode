class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int target,
                    int start,vector<int>& curr) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i =start; i< candidates.size(); i++) {
            
            if (candidates[i] >target)
                continue;

            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, target, 0, curr);
        return ans;
    }
};