#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            solve(nums, ans, index + 1);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};
int main()
{

    return 0;
}