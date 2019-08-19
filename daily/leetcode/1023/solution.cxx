#include<vector>
#include<string>

using namespace std;

/**
 * 字符串匹配经典问题，双重指针
 * 在未找到第一个匹配的时候需要持续的消耗掉前缀
 * 当前缀和后缀中出现 Pattern中不存在的大写字母肯定是错误的，因为只能用小写字母来填充
 * 
 * functions ->  isupper islower isalpha isdigit 
 */
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for(int i = 0;i < queries.size();i++)
            result.push_back(isMatch(queries[i],pattern));
        return result;
    }

    bool isMatch(string& nested,string& pattern){
        int nidx = 0;
        int pidx = 0;
        for(;nidx < nested.size();nidx++){
            if(pidx < pattern.size() && nested[nidx] == pattern[pidx])pidx++;
            else{
                if(isupper(nested[nidx]))return false;
            }
        }
        // 完全匹配才可以
        if(pidx == pattern.size()) return true;

        return false;
    }
};