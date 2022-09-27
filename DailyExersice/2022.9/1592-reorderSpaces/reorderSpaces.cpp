#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution{
public:
    string reorderSpaces(string text) {
        int spcnt = 0, wdcnt = 0, i = 0;
        const int length = text.size();

        while(i < length) {
            if (text[i] != ' ') {
                ++wdcnt;            // 遇到字母后单词计数加一
                do {
                    ++i;            // 跳过所有字母
                }
                while (i < length && text[i] != ' ');
            }
            while (i < length && text[i] == ' ') {
                ++i;
                ++spcnt;            // 计算遇到的连续空格的数量
            }
        }

        int intersp = wdcnt == 1 ? 0 : spcnt / (wdcnt - 1); // 单词间的空格数量

        int begin = 0;
        while (text[begin] == ' ')
            ++begin;

        int pos = begin;
        // 依次处理每一个单词和它后面空格的数量；
        for (int i = 0; i < wdcnt; ++i) {
            while(text[pos] != ' ')
                ++pos;
            int j;
            for (j = 0; text[pos + j] == ' '; ++j)
                ;
            if (j > intersp){
                text.erase(text.begin() + pos, text.begin() + pos + j - intersp);
            }
            else if (j < intersp){
                text.insert(pos, intersp - j, ' ');
            }
            pos += intersp;
        }
        for (int i = text.size(); i < length; ++i)
            text.push_back(' ');

        return {text.begin() + begin, text.begin() + begin + length};
    }
};