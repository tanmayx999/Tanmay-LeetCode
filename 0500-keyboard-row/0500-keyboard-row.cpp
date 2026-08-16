#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Map each character to its keyboard row index (0, 1, or 2)
        string rowStr[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> charToRow;
        for (int i = 0; i < 3; ++i) {
            for (char c : rowStr[i]) {
                charToRow[c] = i;
            }
        }

        vector<string> result;
        for (const string& word : words) {
            int targetRow = charToRow[tolower(word[0])];
            bool isValid = true;
            
            for (char c : word) {
                if (charToRow[tolower(c)] != targetRow) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result.push_back(word);
            }
        }
        return result;
    }
};