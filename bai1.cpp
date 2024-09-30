#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long TongUoc(long long n)
{
    long long sum = 0;
    for (long long i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main()
{
    int T;
    cin >> T;

    cout << endl;

    vector<long long> a;

    while (T--)
    {
        long long n;
        cin >> n;
        a.push_back(TongUoc(n));
    }

    cout << endl;

    for (const auto &x : a)
    {
        cout << x << endl;
    }
    return 0;
}