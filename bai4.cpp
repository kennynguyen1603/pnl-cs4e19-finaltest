#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

vector<int> superPrimeNumber(int n)
{
    vector<int> result;
    queue<int> q;

    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);

    while (!q.empty())
    {
        int current = q.front(); // Lấy phần tử đầu tiên của hàng đợi
        q.pop();                 // Loại bỏ phần tử đầu tiên của hàng đợi

        // Nếu số hiện tại <= n thì thêm vào kết quả
        if (current <= n)
        {
            result.push_back(current);
        }

        // Thêm các số mới tạo thành từ current nếu <= n và là số nguyên tố
        for (int i : {1, 3, 7, 9})
        { // Thêm các chữ số vào cuối để tạo số mới
            int next = current * 10 + i;
            if (next <= n && isPrime(next))
            {
                q.push(next); // Nếu số mới là số nguyên tố thì thêm vào hàng đợi
            }
        }
    }

    // Sắp xếp kết quả
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    int n;
    cout << "Nhap so n: ";
    cin >> n;

    vector<int> superPrimes = superPrimeNumber(n);

    for (const auto &prime : superPrimes)
    {
        cout << prime << " ";
    }

    return 0;
}
