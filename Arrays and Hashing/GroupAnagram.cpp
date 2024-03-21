class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<string> input;
        std::vector<vector<string>> finalAnswer;
       for(int a = 0; a < strs.size(); a++)
       {
           for(int b = a+1; b < strs.size(); b++)
           {
               if(isAnagram(strs[a], strs[b]) == true)
               {
                   input.push_back(strs[b]);
                   strs[b] = "XYZInvalid";
               }
           }
           input.push_back(strs[a]);
           finalAnswer.push_back(input);
           input.clear();
        for (auto it = strs.begin(); it != strs.end(); ) 
        {
        if (*it == "XYZInvalid") 
		    {
            it = strs.erase(it);  
            } 
        else 
		    {
                ++it;  
            }
        }      

       }
       return finalAnswer;

    }

    bool isAnagram(string s, string t) {
    if(s.length() != t.length())
    {
        return false;
    }
    for(int a = 0; a < t.length(); a++)
    {
        for(int b = 0; b < t.length(); b++)
        {
            if(t[a] == s[b])
            {
                s.erase(b, 1);
                break;
            }
        }
    }

    

    if(s.length() <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
};