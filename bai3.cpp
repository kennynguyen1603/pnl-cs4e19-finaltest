#include <iostream>
#include <string>
using namespace std;

// Hàm mã hóa chuỗi theo định dạng <ký tự><số lần xuất hiện>
string encodeString(const string &s)
{
    if (s.empty())
        return "";

    string result = "";
    int count = 1;

    for (size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            result += s[i - 1] + to_string(count);
            count = 1;
        }
    }

    result += s[s.length() - 1] + to_string(count);

    return result;
}

int main()
{
    string s;

    cout << "Nhap chuoi can ma hoa: ";
    cin >> s;

    cout << "Chuoi da ma hoa: " << encodeString(s) << endl;

    return 0;
}
