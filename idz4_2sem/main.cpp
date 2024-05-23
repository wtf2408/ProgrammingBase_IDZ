// дан файл f компоненты которого целые числа. Ни одна из компонент файла не равна нулю. Файл f содержит столько же отриц. чисел, сколько и положительных. Используя доп. файл h переписать комп. файла f в файл g так, чтобы в файл g не было двух соседних чисел с одним знаком.
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("f.txt");
    ofstream fout("g.txt");
    fstream f("h.txt");
    bool currentIsPositive;
    int a, hcount;
    fin >> a;
    if (a > 0)
        currentIsPositive = true;
    else
        currentIsPositive = false;
    fout << a;

    while (!fin.eof())
    {
        fin >> a;
        if (currentIsPositive){
            if(a > 0) // если того же знака (оба положительные) 
            {
                f << a; // запись в временный файл
            }
            else {
                fout << a;
                currentIsPositive = false;
            }
        }
        else {
            if(a > 0){
                fout << a;
                currentIsPositive = true;
            }
            else f << a;
        }
    }
    

    f.close();
    fin.close();
    fout.close();

    return 0;
}
