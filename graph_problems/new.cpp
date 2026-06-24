#include <iostream>
#include <vector>
using namespace std;

long long countSubarraysWithAtLeastOneZero(const vector<int> &arr)
{
    long long n = arr.size();
    long long totalSubarrays = n * (n + 1) / 2;
    long long subarraysWithoutZero = 0;
    long long maxGain = 0;

    for (int i = 0; i < n;)
    {
        if (arr[i] == 1)
        {
            int start = i;
            while (i < n && arr[i] == 1)
            {
                i++;
            }
            int end = i;
            long long length = end - start;

            long long subarraysInOnesSegment = (long long)length * (length + 1) / 2;
            subarraysWithoutZero += subarraysInOnesSegment;

            maxGain = max(maxGain, length);
        }
        else
        {
            i++;
        }
    }
    long long initialCount = totalSubarrays - subarraysWithoutZero;
    if (maxGain%2==1)
        return initialCount+1 +( (maxGain/2)*((maxGain+1)/2));
    else if (maxGain!=0)
    {
        return initialCount +1+ ((maxGain / 2) * (maxGain)/2);
    }else{
        return initialCount;
    
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << countSubarraysWithAtLeastOneZero(arr) << endl;

    return 0;
}
