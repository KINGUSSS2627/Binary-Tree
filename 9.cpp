/*Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.*/

#include <bits/stdc++.h>
using namespace std;
bool canPlaceCows(vector<int> &v, int cows, int dist)
{
    int coord = v[0], cnt = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - coord >= dist)
        {
            cnt++;
            coord = v[i];
        }
        if (cnt >= cows)
            return true;
    }
    return false;
}
int solve(vector<int> &v, int cow)
{
    // after sorting the array of stalls we can get min and max distance and make a search space and since if gap of x is not possible then gap>x is also not possible :. monotonic and we can apply binary search
    sort(v.begin(), v.end());
    int low = 0, high = v[v.size() - 1] - v[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (canPlaceCows(v, cow, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
int main()
{
    vector<int> v = {1, 2, 4, 8, 9};
    int cow = 3;
    cout << solve(v, cow) << endl;
    return 0;
}