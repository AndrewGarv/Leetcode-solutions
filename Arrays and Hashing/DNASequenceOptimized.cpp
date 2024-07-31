#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(const std::string& s) {
        std::vector<std::string> finalAnswer;
        std::unordered_set<std::string> seenSequences; // Store seen sequences
        std::unordered_set<std::string> duplicateSequences; // Store duplicate sequences

        int n = s.length();
        if (n < 10) {
            return finalAnswer; // No possible sequences of length 10
        }

        for (int i = 0; i <= n - 10; ++i) {
            std::string currentSequence = s.substr(i, 10);
            if (seenSequences.find(currentSequence) != seenSequences.end()) {
                if (duplicateSequences.find(currentSequence) == duplicateSequences.end()) {
                    finalAnswer.push_back(currentSequence);
                    duplicateSequences.insert(currentSequence);
                }
            } else {
                seenSequences.insert(currentSequence);
            }
        }

        return finalAnswer;
    }
};