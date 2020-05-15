#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h> 
#include <sys/types.h>
#include <fcntl.h> 

#pragma warning(disable : 4996)

using namespace std;
struct Data {
	string Name;
	double CPU_frequency;
	double RAM_size;
	double HardDriveCapacity;
	double Price;
};

void DataEntry();
void DataReading(string fileName);
void Print();
void DataChache();
void Copy();

