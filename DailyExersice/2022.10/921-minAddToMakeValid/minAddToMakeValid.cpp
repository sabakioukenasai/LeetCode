#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res=0,need=0;
        for(char c:s){
            if(c=='(')
                need++;
            if(c==')')
                need--;
            if(need==-1){
                res++;
                need=0;
            }
        }
        return res+need;
    }
};