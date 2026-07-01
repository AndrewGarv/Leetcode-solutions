class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int beginMover = 0;
        int endMover = 0;
        int greatest = 0;
        std::unordered_set<char> charSet;

        while (endMover < s.size()) {
            if (charSet.find(s[endMover]) == charSet.end()) {
                charSet.insert(s[endMover]);
                greatest = std::max(greatest, endMover - beginMover + 1);
                endMover++;
            } else {
                charSet.erase(s[beginMover]);
                beginMover++;
            }
        }

        return greatest;
    }

    };

   
