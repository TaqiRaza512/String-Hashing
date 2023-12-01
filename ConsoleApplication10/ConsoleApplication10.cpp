#include<iostream>
#include<fstream>
#include<string>
#include"NumberSystems.h"
using namespace std;

int main()
{
	string input;
	cout << "Please enter any string : ";
	getline(cin,input);
	NumberSystems A(input);
	A.ConvertArrayTo32();
	A.SinglingTheArrays();
	A.PrintingTheSingling();
	A.BitsLoad32();
	vector<char> vec=A.Five_Pairs();

	cout << endl << endl;
	for (int ri=0;ri<vec.size();ri++)
	{
		cout << vec[ri]<<" ";
	}
	
}