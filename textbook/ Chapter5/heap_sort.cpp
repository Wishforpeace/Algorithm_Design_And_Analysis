#include <iostream>
using namespace std;
void PirntArray(int r[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
}
void SiftHeap(int r[], int k, int n)
{
    int i, j, temp;
    i = k;
    j = 2 * i + 1; // j 是i的左孩子
    while (j < n)
    {
        // 比较i的左右孩子，r[j]为较大孩子
        if (j < n - 1 && r[j] < r[j + 1])
        {
            j++;
        }
        // 不需要调整
        if (r[i] > r[j])
        {
            break;
        }
        else
        {
            // r[i]与较大孩子交换位置
            cout << "exchange:" << r[i] << "---" << r[j] << endl;
            temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i = j;
            j = 2 * i + 1;
        }
       
    }
}

void HeapSort(int r[], int n)
{
    int i, temp;
    for (i = (n - 1) / 2; i >= 0; i--)
    {
        SiftHeap(r, i, n);
    }
    PirntArray(r, n);
    for (i = 1; i <= n - 1; i++)
    {
        temp = r[0];
        r[0] = r[n - i];
        r[n - i] = temp;
        PirntArray(r, n);
        // n-i个数再次建堆
        SiftHeap(r, 0, n - i);
        PirntArray(r, n);
    }
}

int main()
{
    int r[] = {28, 35, 20, 32, 18, 12};
    int n = 6;
    HeapSort(r, n);
    
}