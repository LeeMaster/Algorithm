// Bad Solution On2
/**
 * find the sub array template to solve easy but contain the repeated compute 
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0,j = 0;
        int res = INT_MAX;
        for (;i < nums.size();i++){
            int sum = 0;
            int ans = 0;
            for(j = i;j < nums.size();j++){
                sum += nums[j];
                ans ++ ;
                if (sum >= s){
                    res = min(res,ans);
                    break;
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

// Common Solution On 
/**
 * use the queue structure 
 */ 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        queue<int> queue;
        int res = INT_MAX;
        int sum = 0;
        for(vector<int>::iterator it = nums.begin();it != nums.end();++it){
            sum += *it;
            queue.push(*it);
            while(sum >= s){
                res = min(res,(int)queue.size());
                sum -= queue.front(); // optimize the repeat computing
                queue.pop();
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

// Slid window solution Onlogn 
// left with the right keep a window then left will be zero and the right will be 1 and then do iterate 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int left = 0, right = 0;
        for(vector<int>::iterator it = nums.begin();it != nums.end();++it){
            while(sum < s && right < nums.size()){
                sum += nums[right ++];
            }
            while(sum >= s && left >= 0){
                res = min(res,right - left);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};


