#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) { 
        int n = nums.size();
        int violations = 0; 

        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                violations++;
            }
        }

        
        if (violations == 0) {
           
            return true;
        } else if (violations == 1) {
            
            return nums[n - 1] <= nums[0];
        } else {
           
            return false;
        }
    }
};