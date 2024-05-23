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

void task3()
{
    // дана матрица, получить одномерный массив, эл. которого равен сред. ариф. строки, если оно больше 10, иначе 0.
    int matrix[10][10], n, m, resultArray[10];
    cout << "enter row count: "; 
    cin >> n;
    cout << "enter colum count: "; 
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            cout << "enter array element: "; 
            cin >> matrix[i][j];
        }
    } 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }  
    

    for (int i = 0; i < n; i++)
    {
        int arithmeticMean = 0;
        for (int j = 0; j < m; j++) 
        {
            arithmeticMean += matrix[i][j];
        }
        arithmeticMean /= m;
        if (arithmeticMean > 10) resultArray[i] = arithmeticMean;
        else resultArray[i] = 0;
        
    }

    for (int i = 0; i < n; i++) cout << resultArray[i] << endl;
    
    
}
int main()
{
    task3();
}