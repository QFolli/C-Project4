//4. Решить задачу о размене T набором монет {1, 2, 5, 7, 10}

#include <iostream>
#include <vector>

#pragma warning(disable : 4996);

using namespace std;

int  find_minimum_coins(int T, vector<int> coins)
{

	int count = 0;
	if (T % 10 == 4)
	{
		T -= 14;
		count = 2;
		cout << "7 7 ";
	}
	for (int i = 0; i <= 4; i++)
	{
		while (T - coins[i] >= 0)
		{
			T -= coins[i];
			count++;
			cout << coins[i] << " ";
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<int> coins = { 10, 7, 5, 2, 1 };
	int T;
	cout << "Введите сумму для размена: ";
	cin >> T;
	cout << "Монеты, используемы для размена: " << endl;

	cout << "\nМинимальное количество монет для размена " << T << ": " << find_minimum_coins(T, coins) << endl;
}