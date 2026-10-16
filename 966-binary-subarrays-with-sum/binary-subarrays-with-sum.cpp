class Solution {
public:
int numSubarraysWithSum(vector<int>& nums, int goal) {
int n = nums.size();
int i = 0;
int j = 0;
    int window_sum = 0;
    int result = 0;
    int count_zeroes = 0;

    while (j < n) {
        window_sum += nums[j];

        while (i < j && (nums[i] == 0 || window_sum > goal)) {
            if (nums[i] == 0) {
                count_zeroes++;
            } else {
                count_zeroes = 0;
            }

            window_sum -= nums[i];
            i++;
        }

        if (window_sum == goal) {
            result += 1 + count_zeroes;
        }

        j++;
    }
    return result;
}

};
