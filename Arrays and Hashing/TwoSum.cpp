class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> finalAnswer;
        int f = 0;
        for(int a = 0; a < nums.size(); a++)
        {
            for(int b = f; b < nums.size(); b++)
            {
                if(b == (nums.size() - 1))
                {
                    continue;
                }
                else if(nums[a] + nums[b+1] == target)
                {
                    finalAnswer.push_back(a);
                    finalAnswer.push_back(b+1);
                    return finalAnswer;
                }
            }
            f++;
        }
        return finalAnswer;
    }
};