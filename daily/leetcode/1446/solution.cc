class Solution {
public:
    int maxPower(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        auto left = 0;
        auto right = 1;

        auto ans = 1;
        auto temp = 1;

        while (right < s.size()){
            if (s[left] == s[right]){
                temp += 1;
                ans = max(ans, temp);
            }else{
                temp = 1;
                left = right;
            }

            right ++;
        }

        return ans;
    }
};