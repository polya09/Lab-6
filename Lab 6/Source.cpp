
#include"Header.h"

void MiddleLevel1() {
	/* ������� �������� ���� � ����������� � ������� ����������� ��� �������:
	   - �������� ����������;
       - ������� ����������;
       - ����� ����������� ������;
       - ����� �������� �����;
       - ����. 
	���������� ����� ��������� ������������ � ������� �����������, � ������� ������� 
	���������� ����� 2 ���/��� ����� �Asus� � ���������� ���������� � ���. */

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
	cout << "����� ��������� ����������� Asus � �������� ���������� ����� 2���: " << sum << endl;
	system("pause");
	system("cls");
}

void MiddleLevel2() {

	/*������ � Memo ��� � StringGrid ��������� ���������� �������� �������� �������� � �������� ��
	� �������� ����. ���������� �������� ���� ���, ����� ������� �*� ���� �������� ��������� �+�. 
	����������� ������� �� � ����� ��������� ������ � �����.*/

	cout << "________MiddleLevel2________" << endl;
	string j = "�*�*�*�*�*�*�";
	ofstream f("Middle2.bin", ios::binary | ios::trunc | ios::out); 
	f.write(j.c_str(), j.length() + 1); 
	f.flush(); 
	char cstrin[14]; 
	fstream f1("Middle2.bin", ios::binary | ios::in); 
	f1.read(cstrin, 14); 
	replace(begin(cstrin), end(cstrin), '*', '+');
	cout << cstrin << endl;
}

void MiddleLevel3() {
	/*������� �������� ����, ������������ �������� �������� ���������, ���������� ��������� ���� :
	- ������� � �������� �������� ��������� ����;
	- ��������� ������ ����� ��������� ���� �� �����;
	- ���������� �������, �� ������� �������� ������;
	- ���������� �������, �� ������� �������� ������ ������.
	���������� �������� ���� ���, ����� ��������� ����� ��������� ���� ���� �� ������� �� 5 %, 
	���� ������ ����� ������� ������ ����� ��� �� 3 ������*/
	
	DataEntry();
	string fileName = "Middle3.bin" ;
	DataReading(fileName);
	Print();
	DataChache();
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