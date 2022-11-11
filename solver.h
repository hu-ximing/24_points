#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

int calc(int a, int b, char oper);

int calc_eq(vector<int> nums, vector<char> opers);

string eq_to_string(vector<int> nums, vector<char> opers);

set<string> stl_solve(vector<int> nums);

set<string> recur_solve(vector<int> nums);
