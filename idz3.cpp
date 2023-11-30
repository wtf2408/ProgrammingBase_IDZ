#include<iostream>

using namespace std;

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