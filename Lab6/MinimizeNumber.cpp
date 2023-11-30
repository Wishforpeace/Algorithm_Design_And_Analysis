#include <iostream>

using namespace std;

string removeToMinimize(string a, int k)
{
    string result = "";
    for (int i; i < a.size(); i++)
    {
        while (k > 0 && !result.empty() && result.back() > a[i])
        {
            result.pop_back();
            k--;
        }
        result.push_back(a[i]);
    }
    return result;
}
int main()
{
    string a;
    int k;
    cout << "请输入n位的正整数: ";
    cin >> a;
    cout << "请输入删除的数k: ";
    cin >> k;
    string minNum = removeToMinimize(a, k);
    cout << "最小的整数位: " << minNum << endl;
} 