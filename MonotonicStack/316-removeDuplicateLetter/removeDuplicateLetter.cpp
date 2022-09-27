#include<iostream>
#include<assert.h>
#include<vector>
#include<string.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution{
public:

    /**
     * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
     * 需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
     * 
     * 例1 
     *  输入：bcabc
     *  输出：abc
     * 例2
     *  输入：cbacdcbc
     *  输出：acdb
    */
    string removeDuplicateLetters(string s) {
        vector<int>visit(26),num(26);
        for(char ch:s)
        {
            num[ch-'a']++;
        }
        string res;
        for(char ch:s)
        {
            if(!visit[ch-'a'])
            {
                while(!res.empty()&&res.back()>ch&&num[res.back()-'a'])
                {
                    visit[res.back()-'a']=0;
                    res.pop_back();
                }
                res+=ch;
                visit[ch-'a']=1;
            }
                num[ch-'a']--;
        }
        return res;
    }
};

int main(){
    cout << "Start!" << endl;

    Solution S;
    string s;

    // 空字符串
    assert(S.removeDuplicateLetters("").compare("") == 0);

    // 长度=1的字符串
    assert(S.removeDuplicateLetters("a").compare("a") == 0);

    // 每个字母只出现一次的字符串-1
    assert(S.removeDuplicateLetters("acbd").compare("acbd") == 0);

    // 每个字母只出现一次的字符串-2
    assert(S.removeDuplicateLetters("cdba").compare("cdba") == 0);

    // 每个字母只出现一次的字符串-3
    assert(S.removeDuplicateLetters("dcba").compare("dcba") == 0);

    // 每个字母只出现一次的字符串-4
    assert(S.removeDuplicateLetters("abacb").compare("abc") == 0);

    // 去重复后为一条单调串的字符串-1
    assert(S.removeDuplicateLetters("acbdcdcab").compare("abcd") == 0);

    // 去重复后为一条单调串的字符串-2
    assert(S.removeDuplicateLetters("adbacbdcd").compare("abcd") == 0);

    // 去重复后为一条单调串的字符串-3
    assert(S.removeDuplicateLetters("acdbddcad").compare("abcd") == 0);

    // 去重复后可以写成两条单调串-1
    assert(S.removeDuplicateLetters("bdbcadabc").compare("adbc") == 0);

    // 去重复后可以写成两条单调串-2
    assert(S.removeDuplicateLetters("cbacdcbc").compare("acdb") == 0);

    cout << "Finished!" << endl;
}