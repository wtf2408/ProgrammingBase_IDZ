#include<iostream>
using namespace std;

struct Plane
{
    std::string arrivePlace;
    int number;
    int travelTime;
};
bool haveOne(int num)
{
    while (num)
    {
        if (num%10 == 1) return true;
        num /= 10;
    }
    return false;
}

int main()
{
    Plane planes[10];
    int middleTime = 0;
    for (int i = 1; i < 11; i++)
    {
        planes[i-1].arrivePlace = "Place " + std::to_string(i);
        planes[i-1].number = i;
        planes[i-1].travelTime = (int)(i + 10)/2.2;
        middleTime += (int)(planes[i-1].travelTime);
    }
    middleTime /= 10.0;
    cout << "middleTime - " << middleTime << endl << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Arrive Place: " << planes[i].arrivePlace << " ";
        cout << "Number: " << planes[i].number << " ";
        cout << "TravelTime: " << planes[i].travelTime;
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        if (planes[i].travelTime - middleTime > 1 && !haveOne(planes[i].number)){
            cout << "Arrive Place: " << planes[i].arrivePlace << " ";
            cout << "Number: " << planes[i].number << " ";
            cout << "TravelTime: " << planes[i].travelTime;
            cout << endl;
        }
    }
    return 0;
}