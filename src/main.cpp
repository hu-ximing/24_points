#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "solver.h"

using namespace std;

random_device rd;
mt19937_64 mt(rd());
uniform_int_distribution<int> dist(1, 13);

void pause()
{
    printf("Press Enter to show solutions...: ");
    char c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    vector<int> nums(4);
    set<string> solutions;
    for (;;)
    {
        do
        {
            generate(nums.begin(), nums.end(), []()
                     { return dist(mt); });
            solutions = stl_solve(nums);
        } while (solutions.size() == 0);
        // show numbers
        for (int x : nums)
        {
            cout << x << " ";
        }
        cout << "\n\n";
        pause();
        // show solutions
        for (auto s : solutions)
        {
            cout << s << "\n";
        }
        cout << "\n-------------------\n\n";
    }
    return 0;
}
