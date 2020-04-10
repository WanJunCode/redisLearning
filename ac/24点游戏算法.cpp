#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check24(const vector<int> &nums, int index, double result, bool &isSuccess)
{
    if (index == 4)   //递归结束条件
    {
        if (abs(result - 24) < 1e-6)
            isSuccess = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
            check24(nums, index + 1, result + nums[index], isSuccess);
        else if (i == 1)
            check24(nums, index + 1, result - nums[index], isSuccess);
        else if(i==2)
            check24(nums, index + 1, result * nums[index], isSuccess);
        else
            check24(nums, index + 1, result / nums[index], isSuccess);
        if (isSuccess)
            return;
    }
}

int main()
{
    vector<int>nums(4);
    while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3])
    {
        sort(nums.begin(), nums.end());
        bool isSuccess = false;
        do {
            check24(nums, 0, 0, isSuccess);
            if (isSuccess)
                break;
        } while (next_permutation(nums.begin(), nums.end()));
        if (isSuccess)
            cout << "true" << endl;
        else
            cout << "false" << endl;       
    }
    return 0;
}