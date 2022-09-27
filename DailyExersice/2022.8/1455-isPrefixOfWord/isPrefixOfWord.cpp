#include <string>

using std::string;

class Solution{
public:
    int isPrefixOfWord(string sentence, string searchWord){
        int ind = 0, p = 0, length = sentence.size(), wordcnt = 1;
        while(ind < length){
            if (sentence[ind] == searchWord[p]){
                ++ind;
                ++p;
            } else {
                p = 0;
                wordcnt++;
                while(ind < length && sentence[ind] != ' ')
                    ++ind;
                ++ind;
            }
            if (p == searchWord.size())
                return wordcnt;
        }
        return -1;
    }
};