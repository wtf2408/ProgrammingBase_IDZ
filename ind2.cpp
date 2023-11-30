#include <iostream>
using namespace std;

void task1()
{
    // максимальный эл., не содержащий 5.

    int arr[100], n, max = 5;
    cout << "enter array length: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "enter array element: "; 
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        bool contain5 = false;
        int temp = arr[i];
        while (temp)
        {
            if(temp % 10 == 5) contain5 = true;
            temp /= 10;
        }
        
        if (!contain5)
        {
            if (max == 5) max = arr[i];
            else if (max < arr[i]) max = arr[i];
        } 
    }
    cout << "max = " << max;
}
void task2()
{
    // сумма эл. массива, расположенных между 1 и 2 чет. эл.
    
    int arr[100], n, resultSum = 0;
    bool start = false, end = false;
    cout << "enter array length: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "enter array element: "; 
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            if (!start) start = true;
            else end = true;
        } 
        else if (start && !end) resultSum += arr[i];
        
    }
    cout << "resultSum = " << resultSum;
}


void main()
{
    task2();
}
