#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

// int calc(int a, int b, char oper);

int calc_eq(vector<int> nums, vector<char> opers, vector<int> orders);

string eq_to_string(vector<int> nums, vector<char> opers, vector<int> orders);

set<string> stl_solve(vector<int> nums);

set<string> recur_solve(vector<int> nums);
