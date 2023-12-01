#include "NumberSystems.h"
#include<iostream>
#include<fstream>
using namespace std;
NumberSystems::NumberSystems(string Arr)
{
	array = Arr;
	size = array.size();
	structsArray = new Letter[size];
	Singling = nullptr;

}
void NumberSystems::ConvertToBinary(int value,int index)
{
	int remainder = 0;
	int place = 7;

	while (value>0)
	{
		remainder = value % 2;
		value = value / 2;
		structsArray[index].Bits[place]=remainder;
		place--;
	}
}
void NumberSystems::ConvertArrayTo32()
{
	for (int ri=0;ri<size;ri++)
	{
		ConvertToBinary(array[ri],ri);
	}

}
void NumberSystems::SinglingTheArrays()
{
	SinglingSize = size * 8;
	int count = 0;

	Singling = new int[SinglingSize];
	int temp=0;
	for (int ri=0;ri<size;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
			Singling[temp] = structsArray[ri].Bits[ci];
			temp++;
		}	
	}
}
void NumberSystems::PrintingTheSingling()
{
	cout << "\n";
	int temp = 0;

	for (int ri=0;ri<size;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
			cout << Singling[temp]<<" ";
			temp++;
		}
	}
}
void NumberSystems::BitsLoad32()
{
	Bits32 = new char[32];
	char val;
	ifstream Rdr("32Bits.txt");
	for (int ri=0;ri<32;ri++)
	{
		Rdr >> val;
		Bits32[ri] = val;
	}
	
}

vector<char> NumberSystems::Five_Pairs()
{
	vector<char> vec(0);

	int count = 0, temp=0;
	for (int ri = (SinglingSize-1);ri>=0;)
	{
		FivePairs = new int[5];
		int power = 0;

		while (count<5)
		{
			if (Singling[ri] == 0 or Singling[ri] == 1)
			{
				FivePairs[count] = Singling[ri];
			}
			else
			{
				FivePairs[count] = 0;
			}
			ri--;
			count++;
		}
		count = 0;
		int value = 0;

		while (count<5)
		{
			value += FivePairs[count] * pow(2, count);
			count++;
		}

		char number = Bits32[value];
		vector<char>::iterator it;
		it = vec.begin();
		vec.insert(it,number);
		count = 0;

		delete[] FivePairs;

	}
	return vec;

}
