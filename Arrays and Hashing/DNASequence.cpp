class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> finalAnswer;
        vector<string> container;//Place every 10 string in here. If a dupe is found then push that 10 string to finalAnswer
        int start = 1;
        int end = 10;
        std::string::iterator it_start = s.begin() + (start - 1);
        std::string::iterator it_end = s.begin() + end;
        while(end <= s.length())
        {
            string combinedString(it_start, it_end);
            cout << combinedString << endl;
            if(checkDupe(combinedString, container) == true && checkDupe(combinedString, finalAnswer) == false)
            {
                finalAnswer.push_back(combinedString);
            }
            else
            {
                container.push_back(combinedString);
            }
            start++;
            end++;
            it_start = s.begin() + (start - 1);
            it_end = s.begin() + end;
        }
        return finalAnswer;
    }

    bool checkDupe(const std::string& a, const std::vector<std::string>& b)
    {
    for (const std::string& str : b)
    {
        if (str == a)
        {
            return true;
        }
    }
    return false;
    }
};