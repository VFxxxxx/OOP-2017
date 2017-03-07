// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	const int N = 32;
	char letter;
	int letterToInt;
	int size = 0;
	int count_letters[N];
	for (int i = 0; i < N; i++)
	{
		count_letters[i] = 0;
	}
	/**
	*считываем посимвольно , если i-ая буква из алфавита, то 
	*в увеличиваем значение массива count_letters[i]
	*и увеличиваем переменную size(общее кол-во букв в текстве не считая знаков)
	*/
	while (fin>>letter)
	{
		if (isalpha(letter)) 
		{
			letter = (char)tolower(letter);
			letterToInt = int(letter) + 192;
			size++;
			if (letterToInt >= 160 && letterToInt <= 175)
			{
				count_letters[letterToInt - 160]++;
			}
			if (letterToInt >= 224 && letterToInt <= 240)
			{
				count_letters[letterToInt - 207]++;
			}
		}
	}
	if (size != 0)
	{
		cout << "Frequency:" << "\n";
		for (int i = 0, j = 160; i < 15; i++, j++)
		{
			cout << char(j) << " " << count_letters[i] / size << "\n";
		}
		for (int i = 15, j = 224; i < N; i++, j++)
		{
			cout << char(j) << " " << count_letters[i] / size << "\n";
		}
	}
	else
	{
		cout << "Your text is empty";
	}
	return 0;
}

