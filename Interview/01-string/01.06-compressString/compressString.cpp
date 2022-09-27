#include <string>

using std::string;
using std::to_string;

class Solution{
    public:
    string compressString(string S){
        const int len = S.size();
        if (len < 3)
            return S;
        string res = "";

        char c = S[0];
        int cnt = 1;
        for (int i = 1; i < len; ++i){
            if (S[i] == c)
                ++cnt;
            else{
                res.push_back(c);
                res.append(to_string(cnt));
                c = S[i];
                cnt = 1;
            }
        }
        res.push_back(c);
        res.append(to_string(cnt));
        return res.size() < len ? res : S;
    }
};