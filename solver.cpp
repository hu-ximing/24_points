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

int calc_eq(vector<int> nums, vector<char> opers)
{
    int ans = nums[0];
    for (int i = 1; i < (int)nums.size(); i++)
    {
        if (ans % nums[i] != 0 && opers[i - 1] == '/')
        {
            return -1;
        }
        ans = calc(ans, nums[i], opers[i - 1]);
    }
    return ans;
}

string eq_to_string(vector<int> nums, vector<char> opers)
{
    string s;
    s += Str(nums[0]);
    for (int i = 0; i < (int)nums.size() - 1; i++)
    {
        if (i > 0 &&
            (opers[i - 1] == '+' || opers[i - 1] == '-') &&
            (opers[i] == '*' || opers[i] == '/'))
        {
            s = Str("(") + s + Str(")");
        }
        s += Str(" ") + Str(opers[i]) + Str(" ") + Str(nums[i + 1]);
    }
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
                    if (calc_eq(nums, opers) == 24)
                    {
                        solutions.insert(eq_to_string(nums, opers));
                    }
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
                    if (calc_eq(his, opers) == 24)
                    {
                        solutions.insert(eq_to_string(his, opers));
                        return;
                    }
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
