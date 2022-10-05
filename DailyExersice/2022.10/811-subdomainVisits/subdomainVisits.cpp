#include <unordered_map>
#include <vector>
#include <string>

using std::unordered_map;
using std::vector;
using std::string;

// 8ms > 96.62%, 11.4MB > 31.40%
class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        unordered_map<string, int> mp;
        for (string s : cpdomains) {
            auto space = s.find(' ');
            string num = s.substr(0, space);
            string domain = s.substr(space + 1);

            auto key = mp.find(domain);
            if (key == mp.end())
                mp.insert(std::pair<string, int>(domain, atoi(num.c_str())));
            else 
                mp.insert_or_assign(domain, atoi(num.c_str()) + key->second);

            int end = domain.length();
            while((end = domain.rfind('.', end - 1)) != -1) {
                string d = domain.substr(end + 1);
                key = mp.find(d);
                if (key == mp.end())
                    mp.insert(std::pair<string, int>(d, atoi(num.c_str())));
                else 
                    mp.insert_or_assign(d, atoi(num.c_str()) + key->second);
            }
        }

        vector<string> ans;
        for (auto itr : mp) {
            string s = std::to_string(itr.second) + ' ' + itr.first;
            ans.push_back(s);
        }
        return ans;
    }
};