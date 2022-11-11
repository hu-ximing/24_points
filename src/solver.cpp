#include "solver.h"

const set<int> operators = {'+', '-', '*', '/'};

template <typename T>
string Str(const T &t)
{
    stringstream ss;
    ss << t;
    return ss.str();
}

void _recur_solve(vector<int> nums, vector<int> his, set<string> &solutions);

int calc(int a, int b, char oper)
{
    int ans;
    switch (oper)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    }
    return ans;
}

int calc_eq(vector<int> nums, vector<char> opers, vector<int> orders)
{
    while (nums.size() > 1)
    {
        int n = orders[0];
        orders.erase(orders.begin());
        for (int i = 0; i < (int)orders.size(); i++)
        {
            if (orders[i] > n)
            {
                orders[i]--;
            }
        }
        if (opers[n] == '/' && (nums[n + 1] == 0 || nums[n] % nums[n + 1] != 0))
        {
            return -1;
        }
        int res = calc(nums[n], nums[n + 1], opers[n]);
        nums.erase(nums.begin() + n);
        opers.erase(opers.begin() + n);
        nums[n] = res;
    }
    return nums[0];
}

string eq_to_string(vector<int> nums, vector<char> opers, vector<int> orders)
{
    string s;
    for (int i = 0; i < orders.size(); i++)
    {
        s += Str(nums[i]) + Str(" ") +
             Str(orders[i]) + Str(opers[i]) + Str(" ");
    }
    s += Str(nums.back());
    return s;
}

// method 1
set<string> stl_solve(vector<int> nums)
{
    set<string> solutions;
    sort(nums.begin(), nums.end());
    do
    {
        vector<char> opers;
        for (char oper1 : operators)
        {
            for (char oper2 : operators)
            {
                for (char oper3 : operators)
                {
                    opers = {oper1, oper2, oper3};
                    vector<int> orders = {0, 1, 2};
                    do
                    {
                        if (calc_eq(nums, opers, orders) == 24)
                        {
                            solutions.insert(eq_to_string(nums, opers, orders));
                        }
                    } while (next_permutation(orders.begin(), orders.end()));
                }
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));

    return solutions;
}

// method 2
set<string> recur_solve(vector<int> nums)
{
    set<string> solutions;
    _recur_solve(nums, {}, solutions);
    return solutions;
}

void _recur_solve(vector<int> nums, vector<int> his, set<string> &solutions)
{
    if (nums.size() == 0)
    {
        vector<char> opers;
        for (char oper1 : operators)
        {
            for (char oper2 : operators)
            {
                for (char oper3 : operators)
                {
                    opers = {oper1, oper2, oper3};
                    vector<int> orders = {0, 1, 2};
                    do
                    {
                        if (calc_eq(nums, opers, orders) == 24)
                        {
                            solutions.insert(eq_to_string(nums, opers, orders));
                        }
                    } while (next_permutation(orders.begin(), orders.end()));
                }
            }
        }
    }
    vector<int> tmp = nums;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        his.push_back(nums[i]);
        tmp.erase(tmp.begin() + i);
        _recur_solve(tmp, his, solutions);
        tmp = nums;
        his.pop_back();
    }
}
