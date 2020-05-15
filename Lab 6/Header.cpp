#include "Header.h"

void DataEntry() {
	string fio;
	double payment;
	int PaidMonths;
	int PaidInAdvanceMonth;
	int n;

	cout << "������� ��������� ������: ";
	cin >> n;
	ofstream record("Buffer.bin", ios::binary | ios::app);
	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++) {
			cout << "������� ���:	";
			cin >> fio;
			cout << "��������� ������ ���������� �� �����:	";
			cin >> payment;
			cout << "���������� �������, �� ������� �������� ������:	";
			cin >> PaidMonths;
			cout << "���������� �������, �� ������� �������� ������ ������:	";
			cin >> PaidInAdvanceMonth;

			record << fio;
			record << payment << endl;
			record << PaidMonths << endl;

			if (i < n - 1) {
				record << PaidInAdvanceMonth << endl;
			}
			else
				record << PaidInAdvanceMonth;
			cout << "_____________________________________" << endl;

		}
	}
}
void DataReading(string fileName) {
	ifstream reading(fileName);
	ofstream record("Buffer.bin", ios::binary | ios::out);

	if (reading) {
		if (record) {
			string fio;
			double payment;
			int PaidMonths;
			int PaidInAdvanceMonth;
			int n;

			//��������� �� �����

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> fio;
				reading >> payment;
				reading >> PaidMonths;
				reading >> PaidInAdvanceMonth;

				record << fio << endl;
				record << payment << endl;
				record << PaidMonths << endl;
				if (i < n - 1) {
					record << PaidInAdvanceMonth << endl;
				}
				else
					record << PaidInAdvanceMonth;
			}
		}
	}
	reading.close();
	record.close();

}
void Print() {
	ifstream reading("Bufer.txt");
	if (reading) {
		string _fio;
		double _payment;
		int _PaidMonths;
		int _PaidInAdvanceMonth;
		int n;

		reading >> n;
		cout << "����������  " << n << endl << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "������ � �" << i + 1 << endl;

			reading >> _fio;
			cout << "������ �1 (���): " << _fio << endl;

			reading >> _payment;
			cout << "������ �2 (���): " << _payment << endl;

			reading >> _PaidMonths;
			cout << "������ �3 (���): " << _PaidMonths << endl;

			reading >> _PaidInAdvanceMonth;
			cout << "������ �4 (���): " << _PaidInAdvanceMonth << endl;
			cout << "_______________________________________" << endl;
		}
	}
}
void DataChache() {
	Copy();
	ifstream reading("Buffer.bin");
	ofstream record("Buffer.bin", ios::binary | ios::out);

	if (reading) {
		if (record) {
			string _fio;
			double _payment;
			int _PaidMonths;
			int _PaidInAdvanceMonth;
			int n;

			reading >> n;

			for (int i = 0; i < n; i++) {
				if (_PaidInAdvanceMonth >= 3)
				{
					reading >> _fio;
					record << _fio << endl;

					_payment = _payment - (_payment * 0.05);
					record << _payment << endl;

					reading >> _PaidMonths;
					record << _PaidMonths << endl;

					reading >> _PaidInAdvanceMonth;
					if (i < n - 1) {
						record << _PaidInAdvanceMonth << endl;
					}
					else
						record << _PaidInAdvanceMonth;
				}
			}

		}
	}
	reading.close();
	record.close();
	remove("Buffer_.bin");
}
void Copy() {
	ifstream reading("Buffer.bin");
	ofstream record("Buffer.bin", ios::binary | ios::out);
	if (reading)
	{
		if (record)
		{
			string _fio;
			double _payment;
			int _PaidMonths;
			int _PaidInAdvanceMonth;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _fio;
				record << _fio << endl;

				reading >> _payment;
				record << _payment << endl;

				reading >> _PaidMonths;
				record << _PaidMonths << endl;

				reading >> _PaidInAdvanceMonth;
				if (i < n - 1) {
					record << _PaidInAdvanceMonth << endl;
				}
				else
					record << _PaidInAdvanceMonth;
			}
		}
	}
	reading.close();
	record.close();
}
