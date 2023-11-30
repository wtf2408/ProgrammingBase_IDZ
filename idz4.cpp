//20. Составить функцию, уменьшающую все эл. строки матрицы на значение наименьшего эл. строки, если все эл. строки положительные.
#include<iostream>
using namespace std;

int matrix[10][10], rowCount, columnCount;

void SubtractMinInRow(int rowIndex)
{
    int minEl;
    bool minInit = false, allElIsPositive = true;
    for (int i = 0; i < columnCount; i++)
    {
        if (matrix[rowIndex][i] > 0){
            if (!minInit) {
                minEl = matrix[rowIndex][i]; 
                minInit = true;
            }
            else{
                if (matrix[rowIndex][i] < minEl) minEl = matrix[rowIndex][i];
            }   
        }
        else allElIsPositive = false;
    } 
    if (allElIsPositive)
    {
        for (int i = 0; i < columnCount; i++)
        {
            matrix[rowIndex][i] -= minEl;
        }
    }
    
}

void PrintMatrix(int rowCount, int columnCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    cout << "Enter row count (<= 10)\n"; cin >> rowCount;
    cout << "Enter column count (<= 10)\n"; cin >> columnCount;

    int rowIndex;

    cout << "Enter row index (<= " << rowCount << ")\n"; cin >> rowIndex;
    cout << "Fill matrix row (" << columnCount << " elemnts)\n";
    for (int i = 0; i < columnCount; i++) cin >> matrix[rowIndex-1][i];
    
    
    PrintMatrix(rowCount, columnCount);
    SubtractMinInRow(rowIndex-1);
    PrintMatrix(rowCount, columnCount);

    return 0;
}

