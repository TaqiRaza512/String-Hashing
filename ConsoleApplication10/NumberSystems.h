#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Letter
{
	int Bits[8]{};
};

class NumberSystems
{
private:
	string array;
	int size;
	Letter* structsArray;
	int* Singling;
	int SinglingSize;
	char* Bits32;

	int* FivePairs;
	char* FinalArrayOF32Base;

public:
	NumberSystems(string Arr);
	void ConvertArrayTo32();
	void ConvertToBinary(int value, int index);
	void LetterConversion(char ch, int index);
	void SinglingTheArrays();
	void PrintingTheSingling();
	void BitsLoad32();
	vector<char> Five_Pairs();


};

