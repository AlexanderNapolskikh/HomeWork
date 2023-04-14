
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 27.03.23
// Yandex test

string readFile(string path) {

	fstream in(path);
	string str;
	string buf = "";

	if (in.is_open()) {

		while (getline(in,str))
		{
			buf += str;
		}
	}
	else {
		cout << "\n\tError opening FILE !!!";
	}

	in.close();
	return buf;
}

int testStr(string str) {

	int indexC = -1;
	int bolInd = -1;
	for (int i = 0; i < size(str); i++)
	{

		if (str[i] == '{') {

			bolInd++;
			if(bolInd == 0)
				indexC = i + 1;
		}
		else if(str[i] == '}') {

			bolInd--;
			if (bolInd == -1)
			{
				indexC = -1;
				bolInd = -1;
			}

		}
	}
	
	return indexC;
}

void main()
{
	string path = "Test.txt";
	cout << " Result :: " << testStr(readFile(path));

}


