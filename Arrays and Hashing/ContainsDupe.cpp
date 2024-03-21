class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> numSet;

       for(int a : nums)
       {
           if(numSet.count(a) > 0)
           {
               return true;
           }
           numSet.insert(a);
       }
       return false;
    }
};