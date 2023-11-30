#include <iostream>
using namespace std;



int main()
{
	setlocale(0, "RU");
	// Задание 24
	//
	//для n = 2, m = 2, f = (1 и 2) - рузультат = (153.0166666667 и 306.0166666667) (firstSummand = 1/60 + secondSummand = 153)
	//для n = 3, m = 3, f = (1 и 2) - рузультат = (784.0005050505 и 1568.0005050505) (firstSummand = 1/1980 + secondSummand = 784)

	int n, m, f;

	cout << "введите n ";
	cin >> n;
	cout << "введите m ";
	cin >> m;
	cout << "введите f ";
	cin >> f;

	double firstSummand = 1, secondSummand = 0;

	int firstSummand_firstEl, firstSummand_secondEl = 4;

	for (int j = 1; j <= n; j++)
	{
		firstSummand_firstEl = j * j;
		firstSummand_secondEl *= j;

		firstSummand *= firstSummand_firstEl + firstSummand_secondEl;
	}

	int secondSummand_firstEl = 5, secondSummand_secondEl = 1;

	for (int i = 1; i <= m; i++)
	{
		secondSummand_firstEl *= 5;
		secondSummand_secondEl *= i;

		secondSummand += secondSummand_firstEl + secondSummand_secondEl;
	}

	firstSummand = 1 / firstSummand;
	secondSummand *= f;

	double result = firstSummand + secondSummand;
	cout << "y = " << result;
}


