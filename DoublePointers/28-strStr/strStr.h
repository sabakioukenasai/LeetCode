#ifndef LEETCODE_STRSTR
#define LEETCODE_STRSTR

#include <string>
#include <array>
using std::array;
using std::string;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        if (needle.length() > haystack.length())
            return -1;
        array<int, 26> map {};
        int len = needle.length(), end = haystack.length(), i;
        // 构造转移表
        for (i = len - 2; i >= 0; --i)
            if (!map[needle[i] - 'a'])
                map[needle[i] - 'a'] = len - 1 - i;
        for (i = 0; i < 26; ++i)
            if (!map[i])
                map[i] = len;
        int start = 0;
        while(start <= end - len)
        {
            i = len;
            while (i >= 0 && haystack[start + i] == needle[i])
                --i;
            if (i < 0)
                return start;
            else
                start += map[haystack[start + len - 1] - 'a'];
        }
        return -1;
    }
};

#endif