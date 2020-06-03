#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h> 
#include <sys/types.h>
#include <fcntl.h> 


using namespace std;
struct Data {
	string Name;
	double CPU_frequency;
	double RAM_size;
	double HardDriveCapacity;
	double Price;
};
void MiddleLevel1() {
	/* Создать бинарный файл с информацией о наличии компьютеров для продажи:
	   - название компьютера;
       - частота процессора;
       - объем оперативной памяти;
       - объем жесткого диска;
       - цена. 
	Определить общую стоимость предложенных к продаже компьютеров, у которых частота 
	процессора более 2 ГГц/сек фирмы «Asus» и напечатать информацию о них. */

	cout << "________MiddleLevel1________" << endl;
	cout << "Size of Item struct: " << sizeof(Data) << " bytes";
	string namesExamples[] = { "Asus", "Asus", "Lenovo", "Apple" };
	const int N = 4;
	Data* data = new Data[N];
	char path[] = "Middle1.bin";
	cout << endl << endl << "Generated data:" << endl;
	for (size_t i = 0; i < N; i++)
	{
		cout << (data[i].Name = namesExamples[i]) << "\t" << (data[i].CPU_frequency = 1 + rand() % 4) << "\t" << (data[i].RAM_size = 125 + rand() % 4) << "\t" << (data[i].HardDriveCapacity = 937 + rand() % 64) << "\t" << (data[i].Price = 40000 + rand() % 10000) << endl;
	}
	FILE* f_out, * f_in;
	f_out = fopen(path, "wb");
	fwrite(data, sizeof(Data), N, f_out);
	fclose(f_out);
	delete[] data;
	data = nullptr;

	cout << endl << endl << "Read from file:" << endl;
	Data* restoredDB = new Data[N];
	f_in = fopen(path, "rb");
	fread(restoredDB, sizeof(Data), N, f_in);
	fclose(f_in);
	double sum;
	for (size_t i = 0; i < N; i++)
	{
		cout << restoredDB[i].Name << "\t" << restoredDB[i].CPU_frequency << "\t" << restoredDB[i].RAM_size << "\t" << restoredDB[i].HardDriveCapacity << "\t" << restoredDB[i].Price << endl;
		sum += data[i].Price;
	}
	cout << "Общая стоимость компьютеров Asus с частотой процессора более 2Ггц: " << sum <<  endl;
	system("pause");
	system("cls");
}

void MiddleLevel2() {

	/*Ввести в Memo или в StringGrid некоторое количество символов русского алфавита и записать их
	в бинарный файл. Переписать бинарный файл так, чтобы символы «*» были заменены символами «+». 
	Распечатать символы до и после изменения данных в файле.*/

	cout << "________MiddleLevel2________" << endl;
	string j = "с*т*р*о*ч*к*а";
	ofstream f("Middle2.bin", ios::binary | ios::trunc | ios::out); 
	f.write(j.c_str(), j.length() + 1); 
	f.flush(); 
	char cstrin[14]; 
	fstream f1("Middle2.bin", ios::binary | ios::in); 
	f1.read(cstrin, 14); 
	replace(begin(cstrin), end(cstrin), '*', '+');
	cout << cstrin << endl;
}

struct Client
{
	string name;
	float monthCost;
	int monthsPaidTotal;
	int nextMonthsPaid;

	void calc()
	{
		nextMonthsPaid = monthsPaidTotal - 1;
	}

	void writeToFile(const char* path)
	{
		ofstream stream(path, ios::binary);
		int nameLength = name.length() + 1;

		stream.write((char*)&nameLength, sizeof(int));
		stream.write((char*)name.c_str(), nameLength);
		stream.write((char*)&monthCost, sizeof(float));
		stream.write((char*)&monthsPaidTotal, sizeof(int));
		stream.write((char*)&nextMonthsPaid, sizeof(int));

		stream.close();
	}

	void readFromFile(const char* path)
	{
		ifstream stream(path, ios::binary);
		int nameLength;
		stream.read((char*)&nameLength, sizeof(int));
		char* buffer = new char[nameLength];
		stream.read(buffer, nameLength);
		name = buffer;
		delete[]buffer;
		stream.read((char*)&monthCost, sizeof(float));
		stream.read((char*)&monthsPaidTotal, sizeof(int));
		stream.read((char*)&nextMonthsPaid, sizeof(int));
		stream.close();
	}

	void printInfo()
	{
		cout << "Name: " << name;
		cout << "\nMonth Cost: " << monthCost;
		cout << "\nMonths Paid: " << monthsPaidTotal;
		cout << "\nNext Months Paid: " << nextMonthsPaid << "\n";
	}
};
void MiddleLevel3() {
	/*Создать бинарный файл, компонентами которого является структура, содержащая следующие поля :
	- Фамилия и инициалы клиентов кабельной сети;
	- Стоимость оплаты услуг кабельной сети за месяц;
	- Количество месяцев, за которые заплатил клиент;
	- Количество месяцев, за которые заплатил клиент вперед.
	Переписать бинарный файл так, чтобы стоимость услуг кабельной сети была бы снижена на 5 %, 
	если клиент хочет оплатил вперед более чем за 3 месяца*/
	
	const char* PATH = "D:\\MiddleLevel3";

	Client client;

	client.name = "Alina Ivanova";
	client.monthCost = (rand() % 100) + 90;
	client.monthsPaidTotal = (rand() % 6) + 1;
	client.calc();

	cout << "Writing to file this info:\n\n";

	client.printInfo();

	client.writeToFile(PATH);

	Client fromFile;

	fromFile.readFromFile(PATH);

	if (fromFile.nextMonthsPaid > 3)
	{
		fromFile.monthCost -= (fromFile.monthCost / 100) * 5;

		fromFile.writeToFile(PATH);

		fromFile.readFromFile(PATH);
	}

	cout << "\nInfo from file (if next months paid > 3, subtract 5% from cost):\n\n";

	fromFile.printInfo();
}


int main() 
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	MiddleLevel1();
	MiddleLevel2();
	MiddleLevel3();
	return 0;
}