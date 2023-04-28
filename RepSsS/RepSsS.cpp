
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

// Some using tesst
#define test 13
// Randomizer
#define random(a,b) (a + rand()%(b + 1 - a));

// __ Example test __
//___________________

// Function work

// 1

float searchMax(float a, float b, float c, float d) {

	float max = a;

	(max < b) ? max = b : max;
	(max < c) ? max = c : max;
	(max < d) ? max = d : max;
	
	return max;
}

// 2

void showInterval(int a, int b) {

	if (a > b) swap(a, b);

	cout << " Result: ";
	for (int i = b - 1; i > a; i--)
	{
		cout << " " << i;
	}
}

// 3

void drawRec(int a) {

	int curNum = 5;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cout << " " << curNum++;
		}
		cout << endl;
	}
}

// 4

bool upSybol(char sym) {

	if (sym >= 'A' && sym <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}

// 5

int* createArray(int size = 8) {

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = i;
	}
	
	return array;
}

void showArray(int* array) {

	int size = _msize(array) / sizeof(array[0]);

	cout << " Result: ";
	for (int i = 0; i < size; i++)
	{
		cout << " " << array[i];
	}
}


// 6

int** createArray(int a, int b, int size1 = 12, int size2 = 12) {

	if (a > b) swap(a, b);

	int** array = new int* [size1];
	for (int i = 0; i < size1; i++)
	{
		array[i] = new int[size2];

		for (int j = 0; j < size2; j++)
		{
			array[i][j] = random(a, b);
		}
	}

	return array;
}

void showArray(int** array) {

	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	int size1 = _msize(array) / sizeof(array[0]);

	float buf = 0;

	cout << " Result: ";
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			buf += array[i][j];
			cout << " " << array[i][j];
		}

		cout << endl;
	}

	cout << endl;

	cout << " Res sr_A: " << buf / (size1 * size2);

}

// 7

void showMaxMinArray(int** array) {

	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	int size1 = _msize(array) / sizeof(array[0]);

	int max = array[0][0];
	int min = array[0][0];

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			(max < array[i][j]) ? max = array[i][j] : max;
			(min > array[i][j]) ? min = array[i][j] : min;
		}
	}

	cout << " Result: " << "MAX == " << max << "; MIN == " << min;
}

// 8

bool searchNuminArray(int* array, int a) {

	int size = _msize(array) / sizeof(array[0]);

	for (int i = 0; i < size; i++)
	{
		if (a == array[i]) {
			return true;
		}
	}

	return false;
}

// 9

int* getarrayNech(int* array) {

	int size = _msize(array) / sizeof(array[0]);
	int sizeNech = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] % 2 != 0) sizeNech++;
	}

	int* arrayNech = new int[sizeNech];
	sizeNech = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] % 2 != 0) arrayNech[sizeNech++] = array[i];
	}

	return arrayNech;
}

// 10

void deleteArrayInd(int* &array, int index) {

	int size = _msize(array) / sizeof(array[0]);
	int* buf_array = new int[size - 1];

	index -= 1;

	for (int i = 0; i < index; i++)
	{
		buf_array[i] = array[i];
	}

	for (int i = index + 1; i < size; i++)
	{
		buf_array[i - 1] = array[i];
	}

	delete[] array;
	array = buf_array;
}

// 11

void deleteStrinArray(int** &array, int index) {
	
	index -= 1;

	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	int size1 = _msize(array) / sizeof(array[0]);

	int** buf_array = new int* [size1 - 1];

	for (int i = 0; i < index; i++)
	{
		buf_array[i] = new int[size2];

		for (int j = 0; j < size2; j++)
		{
			buf_array[i][j] = array[i][j];
		}
	}

	for (int i = index + 1; i < size1; i++)
	{
		buf_array[i - 1] = new int[size2];

		for (int j = 0; j < size2; j++)
		{
			buf_array[i - 1][j] = array[i][j];
		}
	}

	delete[] array[index];
	delete[] array;

	array = buf_array;

}

// 12

string showStr(string path,int index) {

	index -= 1;

	string str;
	ifstream in(path);

	if (in.is_open())
	{
		while (getline(in, str))
		{
			if (index == 0) {
				break;
			}
			index--;
		}
	}
	else {
		cout << " Error (File is not be found)!!!";
		in.close();
		return 0;
	}

	cout << " Result: " << str;
	in.close();

	return str;
}

// 13

bool searchStrinStr(string str, string ex_str) {

	bool flag = false;
	int step_str = 0;

	for (int i = 0; i < str.size(); i++)
	{
		// Выход при удачном сочетании
		if (ex_str[step_str] == '\0') {
			break;
		}

		if (str[i] == ex_str[step_str]) {
			
			flag = true;
			step_str++;
		}
		else {

			// Обновление
			flag = false;
			step_str = 0;
		}

		
	}

	return flag;
}

// 14

// Структура человека
struct People {

	string Name = "noname";
	int age = -1;
	float height = -1;
	float weight = -1;
};

People* createList(int size = 3) {

	People* list = new People[size];

	for (int i = 0; i < size; i++)
	{
		cout << " : Add people ( " << i + 1 << " )" << endl;

		cout << " Enter name: ";
		cin >> list[i].Name;
		system("cls");

		cout << " Enter age: ";
		cin >> list[i].age;
		system("cls");

		cout << " Enter height: ";
		cin >> list[i].height;
		system("cls");

		cout << " Enter weight: ";
		cin >> list[i].weight;
		system("cls");
	}

	return list;
}

void showList(People* list) {

	for (int i = 0; i < 3; i++)
	{
		cout << " NUM (" << i + 1 << ")" << endl;
		cout << " Name: " << list[i].Name << ": Age: " << list[i].age << ": Height: " << list[i].height << ": Weight: " << list[i].weight;
		cout << endl;
	}
}


int main()
{
	// Start options
	srand(unsigned(time(NULL)));

#if test == 1
	float max = searchMax(10.2, 5.5, 9.2, 14.1);
	cout << " Result max: " << max;
#elif test == 2
	showInterval(12, 2);

#elif test == 3
	drawRec(12);

#elif test == 4
	cout << " Result: " << (upSybol('a') ? "True" : "False");

#elif test == 5
	int* array = createArray();
	showArray(array); 

#elif test == 6
	int** array = createArray(2, 900);
	showArray(array); 

#elif test == 7
	int** array = createArray(2, 900);
	showArray(array);

	showMaxMinArray(array);

#elif test == 8
	int* array = createArray();
	showArray(array);

	cout << " Result: " << searchNuminArray(array, 9);
 
#elif test == 9
	int* array = createArray();
	showArray(array);

	int* arrayNech = getarrayNech(array);
	showArray(arrayNech);

#elif test == 10
	int* array = createArray();
	showArray(array);

	deleteArrayInd(array, 3);
	showArray(array); 

#elif test == 11
	int** array = createArray(2, 900);
	showArray(array);

	deleteStrinArray(array, 1);
	showArray(array);

#elif test == 12
	string str = showStr("Test.txt", 1);

#elif test == 13
	string str = showStr("Test.txt", 1);

	string ex_str = "2023";
	cout << " Result: " << searchStrinStr(str, ex_str);

#elif test == 14
	People* list = createList();
	showList(list);

#endif 

}

