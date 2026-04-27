#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<vector>
using namespace std;
int counT = 0, counF = 0;
int ReadPostiveNumber(string);
int ReadLevelNumber(string);
int ReadtypeveNumber(string);
int LevelandtypeGuestions(int level, int type);
void Returnguestions(int number, int level, int type);
int  RandomNumbersGenerete();
void startGame1();
void startGame2();
void startGame3();
void startGame4();
void startGame5();
void startGame6();
void startGame7();
void startGame8();
void startGame9();
int EndTheGame2();
int EndTheGame();
int main()
{
	srand(time(NULL));
	Returnguestions(ReadtypeveNumber("Please enter guestions type :)\n Enter 1 for [+] Enter 2 for [-] Enter 3 for[*]"), ReadLevelNumber("please enter level of guestions [1/ 2/ 3]"), ReadPostiveNumber("How many guestions do wnat to answer ?"));

	EndTheGame();
	
	return 0;
}

int ReadPostiveNumber(string massege)
{
	int number = 0;
	do {
		cout << massege << endl;
		cin >> number;

	} while (number <= 0);
	return number;



}
int ReadLevelNumber(string massege)
{
	int level = 0;
	do {
		cout << massege << endl;
		cin >> level;

	} while (level <= 0);
	return level;



}
int ReadtypeveNumber(string massege)
{
	int type = 0;
	do {
		cout << massege << endl;
		cin >> type;

	} while (type <= 0);
	return type;
}
void Returnguestions(int type,int level,int number)
{
	for (int i = 0; i < number; i++)
	{
		LevelandtypeGuestions(level,type);
}

}
int LevelandtypeGuestions(int level, int type)
{
	if (level == 1 && type == 1)
		startGame1();
	else if (level == 2 && type == 2)
		startGame2();
	else if (level == 3 && type == 3)
		startGame3();
	else if (level == 1 && type == 2)
		startGame4();
	else if (level == 1 && type == 3)
		startGame5();
	else if (level == 2 && type == 3)
		startGame6();
	else if (level == 3 && type == 2)
		startGame7();
	else if (level == 2 && type == 1)
		startGame8();
	else if (level == 3 && type == 1)
		startGame9();

	return type;
}
int  RandomNumbersGenerete()
{
	int randomNum = rand() % 100;
	return randomNum;
}
void startGame1()
{
	int array[2] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };

    }
	
	int X;
	
	cout << array[0] << " + " << array[1] << " = ?" << endl;
	cin >> X;
	if (X == array[0] + array[1])
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}

	

}
void startGame2()
{

	int array[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };

	}

	int X;

	cout << array[0] << " - " << array[1]<<" - " <<array[2]<< " = ?" << endl;
	cin >> X;
	if (X == array[0] -array[1]-array[2])
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}

	



}
void startGame3()
{

	int array[4] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };

	}

	int X;

	cout << array[0] << " * " << array[1] << " * " << array[2] << " = ?" << endl;
	cin >> X;
	if (X == array[0] * array[1] * array[2])
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}

	



}
void startGame4()
{

	int array[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };
	}

	int X;

	cout << array[0] << " - " << array[1] << " = ?" << endl;
	cin >> X;
	if (X == array[0] - array[1] )
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}

	



}
void startGame5()
{

	int array[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };
	}

	int X;

	cout << array[0] << " * " << array[1] << " = ?" << endl;
	cin >> X;
	if (X == array[0] * array[1])
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}





}
void startGame6()
{

	int array[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };

	}

	int X;

	cout << array[0] << " x " << array[1]<<" x " << array[2] << " = ?" << endl;
	cin >> X;
	if (X == array[0] * array[1]*array[2])
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}





}
void startGame7()
{


	int array[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };

	}

	int X;

	cout << array[0] << " - " << array[1] << " - " << array[2] <<"-" << array[3] << " = ?" << endl;
	cin >> X;
	if (X == array[0] - array[1] - array[2]-array[3])
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}
}
void startGame8()
{


	int array[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };
	}

	int X;

	cout << array[0] << " - " << array[1] << " - " << array[2] << "-" << array[3] << " = ?" << endl;
	cin >> X;
	if (X == array[0] - array[1] - array[2] - array[3])
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}
}
void startGame9()
{


	int array[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int x = RandomNumbersGenerete();
		array[i] = { x };

	}

	int X;

	cout << array[0] << " - " << array[1] << " - " << array[2] << "-" << array[3] << " = ?" << endl;
	cin >> X;
	if (X == array[0] - array[1] - array[2] - array[3])
	{
		cout << "Yes is TRUE\n";
		counT++;
		system("color A7");
	}

	else
	{
		cout << "No is FALSE\n";
		counF++;
		system("color 47");
	}
}
int EndTheGame()
{
	cout << "\t\t________________________________\t\t\n";
	cout << "\t\t           GAME OVER\n";
	cout << "Your TRUE Answers is =" << counT << endl;
	cout << "Your FALSE answers is =" << counF << endl;
	if (counT > counF)
		cout << "You'r math is very gooooood :)" << endl;
	else
		cout << "Try Again  :( " << endl;
	string word = "YES";
	cout << "Do you want try again ? [YES/NO]\n";
	cin >> word;
	if (word == "YES")
	{
	
	Returnguestions(ReadtypeveNumber("Please enter typr"), ReadLevelNumber("please enter level of guestions 1 2 3"), ReadPostiveNumber("How many guestions do wnat to answer ?"));
	EndTheGame2();
}
	else
		return 0;
}
int EndTheGame2()
{
	cout << "\t\t________________________________\t\t\n";
	cout << "\t\t           GAME OVER\n";
	cout << "Your TRUE Answers is =" << counT << endl;
	cout << "Your FALSE answers is =" << counF << endl;
	if (counT > counF)
		cout << "You'r math is very gooooood :)" << endl;
	else
		cout << "Try Again  :( " << endl;
	string word = "YES";
	cout << "Do you want try again ? [YES/NO]\n";
	cin >> word;
	if (word == "YES")
		Returnguestions(ReadtypeveNumber("Please enter typr"), ReadLevelNumber("please enter level of guestions 1 2 3"), ReadPostiveNumber("How many guestions do wnat to answer ?"));

	else
		return 0;
}
