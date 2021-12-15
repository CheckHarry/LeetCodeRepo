#include <string>
#include <vector>
#include <unordered_map>

using namespace std;





unordered_map<char, string> Mapping = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
};
vector<string> letterCombinations(string digits) {
    vector<string> to_return;
    if (digits.size() == 0) return vector<string>({});
    if (digits.size() == 1) {
        string temp = "";
        for (char x : Mapping[digits[0]]) to_return.push_back(temp + x);
        return to_return;
    }
    for (string l : letterCombinations(digits.substr(1))) {
        for (char x : Mapping[digits[0]]) to_return.push_back(x + l);
    }
    return to_return;
}

