#include <iostream>
#include <vector>
#include <algorithm> // Include this header for reverse
#include <cstring>
using namespace std;

vector<int> getDigits(long long x)
{
    vector<int> digits;
    while (x > 0)
    {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

long long dp[20][2][10];

long long countValidNumbers(int pos, bool tight, int last_digit, vector<int> &digits)
{
    if (pos == digits.size())
        return 1;

    if (dp[pos][tight][last_digit] != -1)
        return dp[pos][tight][last_digit];

    long long result = 0;
    int limit = tight ? digits[pos] : 9;

    for (int digit = 0; digit <= limit; digit++)
    {
        if (digit != last_digit)
        {
            result += countValidNumbers(pos + 1, tight && (digit == limit), digit, digits);
        }
    }

    return dp[pos][tight][last_digit] = result;
}

long long countNumbers(long long x)
{
    if (x < 0)
        return 0;
    vector<int> digits = getDigits(x);
    memset(dp, -1, sizeof(dp));
    return countValidNumbers(0, true, -1, digits);
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << countNumbers(b) - countNumbers(a - 1) << endl;

    return 0;
}