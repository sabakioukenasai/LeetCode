#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::string;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        // // plan A: 80ms > 9.01%, 8,3MB > 54.28%
        // // 运行较慢的原因是，提交的代码中添加了cout语句，所以降低了整体运行速度
        // const size_t length = s.size();
        // if (length < 2)
        //     return length;
        // int longest = 0, start = -1;
        // map<char, int> appear;

        // for (auto i = 0; i < length; ++i){
        //     auto findres = appear.find(s[i]);
        //     if (findres != appear.end()){
        //         start = max(start, findres->second);
        //     }
        //     longest = max(longest, i - start);
        //     appear[s[i]] = i;
        // }
        // return (int)longest;
        
        // planB: 12ms > 80.32%, 8.3MB > 54.41%
        const size_t length = s.size();
        if (length < 2)
            return length;
        int longest = 0, start = 0;
        map<char, int> appear;

        for (auto i = 0; i < length; ++i){
            if (appear[s[i]] != 0){
                start = max(start, appear[s[i]]);
            }
            longest = max(longest, i - start + 1);
            appear[s[i]] = i + 1;
        }
        return longest;

        /* 4ms 范例
        int f=0,max,r=1;
        if(s.size()==0){
            return 0;
        }
        for(int j=1;j<s.size();j++){
            for(int i =f;i<j;i++){
                if(s[i]==s[j]){
                    f=i+1;
                    break;
                }
            }
            max=j-f+1;
            r=r<max?max:r;
        }
        return r;
        */
    }
};