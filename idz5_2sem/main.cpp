#include<iostream>
#include<vector>

using namespace std;

int absMax(vector<int> arr){
    int max = abs(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (abs(arr[i]) > max)
            max = abs(arr[i]);
    }
    return max;
}
void print(vector<int> arr){
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){

    vector<int> arr = {1, 2, 3, -7, 16, -22, 11, 4};
    print(arr);
    int max = absMax(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0 && arr[i] > 0){
            arr[i] = max;
        }
    }
    print(arr);
    return 0;
}

