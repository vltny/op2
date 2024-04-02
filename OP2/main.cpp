#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Data.cpp"
#include <vector>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

vector<Data> dataList;

//РАБОТА С ФАЙЛАМИ
void FileSave() {
	ofstream fout("data.bin", ios::binary);
	if (fout.is_open()) {
		for (int i = 0; i < dataList.size(); i++) {
			Car car = dataList[i].getCar();
			Date date = dataList[i].getDate();
			Text text = dataList[i].getText();
			Client client = dataList[i].getClient();

			fout.write((char*)&car, sizeof(Car));
			fout.write((char*)&date, sizeof(Date));
			fout.write((char*)&text, sizeof(Text));
			fout.write((char*)&client, sizeof(Client));
		}
	}
	fout.close();
}

void FileLoad() {
	ifstream fin("data.bin", ios::binary);
	if (fin.is_open()) {
		Car car;
		Date date;
		Text text;
		Client client;
		while (fin.read((char*)&car, sizeof(Car))) {
			fin.read((char*)&date, sizeof(Date));
			fin.read((char*)&text, sizeof(Text));
			fin.read((char*)&client, sizeof(Client));

			Data data(car, date, text, client);
			dataList.push_back(data);
		}
	}
	fin.close();
}

//ВЫВОД ТАБЛИЦЫ
void PrintTableHeader() {
	cout << setiosflags(ios::left) << setw(3) << "Id" << setw(10) << "|Бренд" << setw(10) << "|Модель" << setw(13) << "|Гос.Номер" << setw(11) << "|Дата" << setw(25) << "|Причина обращения" << setw(25) << "|Примечание" << setw(10) << "|Фамилия" << setw(13) << "|Телефон" << endl;
	cout << setfill('=') << setw(120) << "=" << setfill(' ') << endl;
}

void PrintTableContent(vector<Data> data, int index) {
	char* brand = data[index].getCar().brand;
	char* model = data[index].getCar().model;
	char* license = data[index].getCar().licensePlate;

	int day = data[index].getDate().day;
	int month = data[index].getDate().month;
	int year = data[index].getDate().year;

	char* problem = data[index].getText().problem;
	char* note = data[index].getText().note;

	char* surName = data[index].getClient().surName;
	char* phone = data[index].getClient().phoneNumber;

	char brand_1[10]={"\0"};
	char brand_2[10]={ "\0" };
	char model_1[10]={ "\0" };
	char model_2[10]={ "\0" };
	char surName_1[10]={ "\0" };
	char surName_2[10]={ "\0" };

	char problem_1[25]={ "\0" };
	char problem_2[25]={ "\0" };
	char problem_3[25]={ "\0" };
	char problem_4[25]={ "\0" };
	char problem_5[25]={ "\0" };

	char note_1[25]={ "\0" };
	char note_2[25]={ "\0" };
	char note_3[25]={ "\0" };
	char note_4[25]={ "\0" };
	char note_5[25]={ "\0" };

	for (int i = 0; i < 9; i++) {
		brand_1[i] = brand[i];
		model_1[i] = model[i];
		surName_1[i] = surName[i];

		brand_2[i] = brand[i+9];
		model_2[i] = model[i+9];
		surName_2[i] = surName[i+9];
	}

	for (int i = 0; i < 24; i++) {
		problem_1[i] = problem[i];
		note_1[i] = note[i];

		problem_2[i] = problem[i+24];
		note_2[i] = note[i+24];

		problem_3[i] = problem[i + 48];
		note_3[i] = note[i + 48];

		problem_4[i] = problem[i + 72];
		note_4[i] = note[i + 72];

		problem_5[i] = problem[i + 96];
		note_5[i] = note[i + 96];
	}

	cout << setiosflags(ios::left) << setw(3) << index << setw(1) << "|" << setw(9) << brand_1 << setw(1)<<"|" << setw(9) << model_1 << setw(1) << "|" << setw(12) << license << setw(1)<< "|" << setw(2) << day << "." << setw(2) << month << "." << setw(4) << year << setw(1) << "|" << setw(24) << problem_1 << setw(1) << "|" << setw(24)  << note_1 << setw(1) << "|" << setw(9) << surName_1 <<setw(1) << "|" << setw(12) << phone << endl;
	if (brand_2[0] != '\0' or model_2[0] != '\0' or problem_2[0] != '\0' or note_2[0] != '\0' or surName_2[0] != '\0') {
		cout << setiosflags(ios::left) << setw(3) << "" << setw(1) << "|" << setw(9) << brand_2 << setw(1) << "|" << setw(9) << model_2 << setw(1) << "|" << setw(12) << "" << setw(1) << "|" << setw(10) << "" << setw(1) << "|" << setw(24)  << problem_2 << setw(1) << "|" << setw(24) << note_2 << setw(1) << "|" << setw(9) << surName_2 << setw(1) << "|" << setw(12) << "" << endl;
	}

	if (problem_3[0] != '\0' or note_3[0] != '\0') {
		cout << setiosflags(ios::left) << setw(3) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << setw(1) << "|" << setw(10) << "" << setw(1) << "|" << setw(24) << problem_3 << setw(1) << "|" << setw(24) << note_3 << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << endl;
	}

	if (problem_4[0] != '\0' or note_4[0] != '\0') {
		cout << setiosflags(ios::left) << setw(3) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << setw(1) << "|" << setw(10) << "" << setw(1) << "|" << setw(24) << problem_4 << setw(1) << "|" << setw(24) << note_4 << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << endl;
	}

	if (problem_5[0] != '\0' or note_5[0] != '\0') {
		cout << setiosflags(ios::left) << setw(3) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << setw(1) << "|" << setw(10) << "" << setw(1) << "|" << setw(24) << problem_5 << setw(1) << "|" << setw(24) << note_5 << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << endl;
	}

	cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
}

void PrintTableContent(vector<Data> data) {
	int size = data.size();

	for (int index = 0; index < size; index++) {
		char* brand = data[index].getCar().brand;
		char* model = data[index].getCar().model;
		char* license = data[index].getCar().licensePlate;

		int day = data[index].getDate().day;
		int month = data[index].getDate().month;
		int year = data[index].getDate().year;

		char* problem = data[index].getText().problem;
		char* note = data[index].getText().note;

		char* surName = data[index].getClient().surName;
		char* phone = data[index].getClient().phoneNumber;

		char brand_1[10]{ "\0" };
		char brand_2[10]{ "\0" };
		char model_1[10]{ "\0" };
		char model_2[10]{ "\0" };
		char surName_1[10]{ "\0" };
		char surName_2[10]{ "\0" };

		char problem_1[25]{ "\0" };
		char problem_2[25]{ "\0" };
		char problem_3[25]{ "\0" };
		char problem_4[25]{ "\0" };
		char problem_5[25]{ "\0" };

		char note_1[25]{ "\0" };
		char note_2[25]{ "\0" };
		char note_3[25]{ "\0" };
		char note_4[25]{ "\0" };
		char note_5[25]{ "\0" };

		for (int i = 0; i < 9; i++) {
			brand_1[i] = brand[i];
			model_1[i] = model[i];
			surName_1[i] = surName[i];

			brand_2[i] = brand[i + 9];
			model_2[i] = model[i + 9];
			surName_2[i] = surName[i + 9];
		}

		for (int i = 0; i < 24; i++) {
			problem_1[i] = problem[i];
			note_1[i] = note[i];

			problem_2[i] = problem[i + 24];
			note_2[i] = note[i + 24];

			problem_3[i] = problem[i + 48];
			note_3[i] = note[i + 48];

			problem_4[i] = problem[i + 72];
			note_4[i] = note[i + 72];

			problem_5[i] = problem[i + 96];
			note_5[i] = note[i + 96];
		}

		cout << setiosflags(ios::left) << setw(3) << index << setw(1) << "|" << setw(9) << brand_1 << setw(1) << "|" << setw(9) << model_1 << setw(1) << "|" << setw(12) << license << setw(1) << "|" << setw(2) << day << "." << setw(2) << month << "." << setw(4) << year << setw(1) << "|" << setw(24) << problem_1 << setw(1) << "|" << setw(24) << note_1 << setw(1) << "|" << setw(9) << surName_1 << setw(1) << "|" << setw(12) << phone << endl;
		if (brand_2[0] != '\0' or model_2[0] != '\0' or problem_2[0] != '\0' or note_2[0] != '\0' or surName_2[0] != '\0') {
			cout << setiosflags(ios::left) << setw(3) << "" << setw(1) << "|" << setw(9) << brand_2 << setw(1) << "|" << setw(9) << model_2 << setw(1) << "|" << setw(12) << "" << setw(1) << "|" << setw(10) << "" << setw(1) << "|" << setw(24) << problem_2 << setw(1) << "|" << setw(24) << note_2 << setw(1) << "|" << setw(9) << surName_2 << setw(1) << "|" << setw(12) << "" << endl;
		}

		if (problem_3[0] != '\0' or note_3[0] != '\0') {
			cout << setiosflags(ios::left) << setw(3) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << setw(1) << "|" << setw(10) << "" << setw(1) << "|" << setw(24) << problem_3 << setw(1) << "|" << setw(24) << note_3 << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << endl;
		}

		if (problem_4[0] != '\0' or note_4[0] != '\0') {
			cout << setiosflags(ios::left) << setw(3) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << setw(1) << "|" << setw(10) << "" << setw(1) << "|" << setw(24) << problem_4 << setw(1) << "|" << setw(24) << note_4 << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << endl;
		}

		if (problem_5[0] != '\0' or note_5[0] != '\0') {
			cout << setiosflags(ios::left) << setw(3) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << setw(1) << "|" << setw(10) << "" << setw(1) << "|" << setw(24) << problem_5 << setw(1) << "|" << setw(24) << note_5 << setw(1) << "|" << setw(9) << "" << setw(1) << "|" << setw(12) << "" << endl;
		}

		cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
	}
}

void PrintTable() {
	int select = -1;
	while (select != 0) {
		system("cls");
		PrintTableHeader();
		PrintTableContent(dataList);
		cout << "(0 - Назад)\n" << endl;

		cout << "Ввод >> ";
		cin >> select;
	}
}

//ДОБАВЛЕНИЕ
void Add() {
	system("cls");

	Car tempCar;
	Date tempDate;
	Text tempText;
	Client tempClient;
	char temp[10] = {};
	const char* formatYear = "%Y";
	const char* formatMonth = "%m";
	const char* formatDay = "%d";

	cout << "Введите марку автомобиля: \nВвод >> ";
	cin.ignore();
	cin.getline(tempCar.brand, 20);
	cin.clear();

	cout << "\nВведите модель автомобиля: \nВвод >> ";
	cin.getline(tempCar.model, 20);
	cin.clear();

	cout << "\nВведите номер автомобиля: \nВвод >> ";
	cin >> setw(13) >> tempCar.licensePlate;
	cin.clear();
	cin.ignore(1000, '\n');

	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	strftime(temp, 5, formatYear, timeinfo);
	tempDate.year = atoi(temp);
	strftime(temp, 5, formatMonth, timeinfo);
	tempDate.month = atoi(temp);
	strftime(temp, 5, formatDay, timeinfo);
	tempDate.day = atoi(temp);

	cout << "\nОпишите проблему: \nВвод >> ";
	cin.getline(tempText.problem, 150);
	cin.clear();

	cout << "\nПримечания: \nВвод >> ";
	cin.getline(tempText.note, 150);
	cin.clear();

	cout << "\nВведите имя клиента: \nВвод >> ";
	cin >> setw(20) >> tempClient.name;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "\nВведите фамилию клиента: \nВвод >> ";
	cin >> setw(20) >> tempClient.surName;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "\nВведите отчество клиента: \nВвод >> ";
	cin >> setw(20) >> tempClient.patronymic;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "\nВведите номер телефона: \nВвод >> ";
	cin >> setw(13) >> tempClient.phoneNumber;
	cin.clear();
	cin.ignore(1000, '\n');

	Data data(tempCar, tempDate, tempText, tempClient);
	dataList.push_back(data);

	FileSave();
}

//УДАЛЕНИЕ
void Deleting() {
	system("cls");
	int index{};
	cout << "Введите ID удаляемой записи: \n";
	cin >> index;

	int select{-1};
	if (index >= dataList.size()) {
		select = 0;
		Deleting();
	}
	while (select != 0) {
		system("cls");
		PrintTableHeader();
		PrintTableContent(dataList, index);

		cout << "Вы точно хотите удалить эту запись?" << endl;
		cout << "0 - Нет" << endl;
		cout << "1 - Да" << endl;

		cout << "\nВвод >> ";
		cin >> select;

		switch (select) {
		case 0:
			break;
		case 1:
			dataList.erase(dataList.begin() + index);
			select = 0;

			FileSave();
			break;
		default:
			cout << "Неверное значение!" << endl;
			break;
		}
	}
}

//ИЗМЕНЕНИЕ
void Edit() {
	system("cls");
	int index{};
	cout << "Удаление:" << endl;
	cout << "=========" << endl;
	cout << "Введите ID изменяемой записи: \n";
	cin >> index;

	int select = -1;
	if (index >= dataList.size()) {
		select = 0;
		Edit();
	}
	while (select != 0) {
		system("cls");
		PrintTableHeader();
		PrintTableContent(dataList, index);

		cout << "Что вы хотите изменить?\n";
		cout << "1 - Дата обращения\n";
		cout << "2 - Номер автомобиля\n";
		cout << "3 - ФИО\n";
		cout << "4 - Причина обращения\n";
		cout << "5 - Номер телефона\n";
		cout << "\n(0 - Назад)\n" << endl;

		cout << "Ввод >> ";
		cin >> select;

		Car tempCar;
		Date tempDate;
		Text tempText;
		Client tempClient;

		switch (select)
		{
		case 0:
			break;
		case 1:
			cout << "\nВведите день:\nВвод >> ";
			cin >> tempDate.day;
			cout << "\nВведите месяц:\nВвод >> ";
			cin >> tempDate.month;
			cout << "\nВведите год:\nВвод >> ";
			cin >> tempDate.year;
			dataList[index].setDate(tempDate);

			FileSave();
			break;
		case 2:
			tempCar = dataList[index].getCar();
			cout << "\nВведите номер:\n";
			cin >> setw(13) >> tempCar.licensePlate;
			dataList[index].setCar(tempCar);

			FileSave();
			break;
		case 3:
			tempClient = dataList[index].getClient();
			cout << "\nВведите имя:\nВвод >> ";
			cin >> setw(20) >> tempClient.name;
			cout << "\nВведите фамилию:\nВвод >> ";
			memset(tempClient.surName, '\0', 20);
			cin >> setw(20) >> tempClient.surName;
			cout << "\nВведите отчество:\nВвод >> ";
			cin >> setw(20) >> tempClient.patronymic;
			dataList[index].setClient(tempClient);

			FileSave();
			break;
		case 4:
			tempText = dataList[index].getText();
			cout << "\nВведите причину обращения:\nВвод >> ";
			cin.clear();
			cin.ignore();
			memset(tempText.problem, '\0', 150);
			cin.getline(tempText.problem, 150);
			dataList[index].setText(tempText);

			FileSave();
			break;
		case 5:
			tempClient = dataList[index].getClient();
			cout << "\nВведите номер телефона:\nВвод >> ";
			cin >> setw(13) >> tempClient.phoneNumber;
			dataList[index].setClient(tempClient);

			FileSave();
			break;
		default:
			cout << "Неверное значение!\n" << endl;
			break;
		}
	}
}


//СОРТИРОВКА
void SortingByBrand() {
	system("cls");


	int select = -1;
	while (select != 0) {
		cout << "Сортировка по марке автомобиля:" << endl;
		cout << "===============================" << endl;
		cout << "1 - По возрастанию" << endl;
		cout << "2 - По убыванию" << endl;
		cout << "\n(0 - Назад)\n" << endl;

		cout << "Ввод >> ";
		cin >> select;

		vector<Data> dataTemp = dataList;
		Data dataTempor;
		system("cls");
		switch (select)
		{
		case 0:
			break;
		case 1:
			for (int i = 0; i < dataTemp.size(); i++) {
				for (int j = 0; j < dataTemp.size() - i - 1; j++) {
					if (strcmp(dataTemp[j].getCar().brand, dataTemp[j + 1].getCar().brand) > 0) {
						dataTempor = dataTemp[j];
						dataTemp[j] = dataTemp[j + 1];
						dataTemp[j + 1] = dataTempor;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < dataTemp.size(); i++) {
				for (int j = 0; j < dataTemp.size() - i - 1; j++) {
					if (strcmp(dataTemp[j].getCar().brand, dataTemp[j + 1].getCar().brand) < 0) {
						dataTempor = dataTemp[j];
						dataTemp[j] = dataTemp[j + 1];
						dataTemp[j + 1] = dataTempor;
					}
				}
			}
			break;
		default:
			cout << "Неверное значение!\n" << endl;
			break;
		}
		while (select != 0) {
			system("cls");
			PrintTableHeader();
			PrintTableContent(dataTemp);
			cout << "(0 - Назад)\n\nВвод >> ";
			cin >> select;
		}
	}
}

void SortingByDate() {
	system("cls");

	vector<Data> dataTemp = dataList;
	Data dataTempor;
	int select = -1;
	while (select != 0) {
		cout << "Сортировка по дате обращения:" << endl;
		cout << "=============================" << endl;
		cout << "1 - По возрастанию" << endl;
		cout << "2 - По убыванию" << endl;
		cout << "\n(0 - Назад)\n" << endl;

		cout << "Ввод >> ";
		cin >> select;

		system("cls");
		switch (select)
		{
		case 0:
			break;
		case 1:
			for (int i = 0; i < dataTemp.size(); i++) {
				for (int j = 0; j < dataTemp.size() - i - 1; j++) {
					if ((dataTemp[j].getDate().year > dataTemp[j+1].getDate().year) || 
						(dataTemp[j].getDate().year == dataTemp[j + 1].getDate().year && dataTemp[j].getDate().month > dataTemp[j + 1].getDate().month) || 
						(dataTemp[j].getDate().year == dataTemp[j + 1].getDate().year && dataTemp[j].getDate().month == dataTemp[j + 1].getDate().month && dataTemp[j].getDate().day > dataTemp[j + 1].getDate().day)) {
						dataTempor = dataTemp[j];
						dataTemp[j] = dataTemp[j + 1];
						dataTemp[j + 1] = dataTempor;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < dataTemp.size(); i++) {
				for (int j = 0; j < dataTemp.size() - i - 1; j++) {
					if ((dataTemp[j].getDate().year < dataTemp[j + 1].getDate().year) ||
						(dataTemp[j].getDate().year == dataTemp[j + 1].getDate().year && dataTemp[j].getDate().month < dataTemp[j + 1].getDate().month) ||
						(dataTemp[j].getDate().year == dataTemp[j + 1].getDate().year && dataTemp[j].getDate().month == dataTemp[j + 1].getDate().month && dataTemp[j].getDate().day < dataTemp[j + 1].getDate().day)) {
						dataTempor = dataTemp[j];
						dataTemp[j] = dataTemp[j + 1];
						dataTemp[j + 1] = dataTempor;
					}
				}
			}
			break;
		default:
			cout << "Неверное значение!\n" << endl;
			break;
		}
		while (select != 0) {
			system("cls");
			PrintTableHeader();
			PrintTableContent(dataTemp);
			cout << "(0 - Назад)\n\nВвод >> ";
			cin >> select;
		}
	}
}


void Sorting() {
	system("cls");

	int select = -1;
	while (select != 0) {
		system("cls");
		cout << "Сортировка:" << endl;
		cout << "===========" << endl;
		cout << "1 - По марке автомобиля" << endl;
		cout << "2 - По дате обращения" << endl;
		cout << "\n(0 - Назад)\n" << endl;

		cout << "Ввод >> ";
		cin >> select;

		system("cls");
		switch (select)
		{
		case 0:
			break;
		case 1:
			SortingByBrand();
			break;
		case 2:
			SortingByDate();
			break;
		default:
			cout << "Неверное значение!\n" << endl;
			break;
		}
	}
}

//ПОИСК
void SearchingByBrand() {
	system("cls");

	cout << "Поиск по марке автомобиля:" << endl;
	cout << "==========================" << endl;
	cout << "Введите марку:\n" << endl;

	cout << "Ввод >> ";
	char brand[20]{ "\0" };
	cin >> setw(20) >> brand;
	cin.clear();
	cin.ignore(1000, '\n');

	int select = -1;
	while (select != 0) {
		system("cls");
		PrintTableHeader();

		int size = dataList.size();
		for (int i = 0; i < size; i++) {
			if (_stricmp(dataList[i].getCar().brand, brand) == 0) {
				PrintTableContent(dataList, i);
			}
		}
		cout << "(0 - Назад)\n" << endl;
		cout << "Ввод >> ";
		cin >> select;
	}
}

void SearchingByLicense() {
	system("cls");

	cout << "Поиск по номеру автомобиля:" << endl;
	cout << "================================" << endl;
	cout << "Введите номер:\n" << endl;

	cout << "Ввод >> ";
	char license[13]{ "\0" };
	cin >> setw(13) >> license;
	cin.clear();
	cin.ignore(1000, '\n');

	int select = -1;
	while (select != 0) {
		system("cls");
		PrintTableHeader();

		int size = dataList.size();
		for (int i = 0; i < size; i++) {
			if (_stricmp(dataList[i].getCar().licensePlate, license) == 0) {
				PrintTableContent(dataList, i);
			}
		}
		cout << "(0 - Назад)\n" << endl;
		cout << "Ввод >> ";
		cin >> select;
	}
}

void SearchingByDate() {
	system("cls");

	cout << "Поиск по дате обращения:" << endl;
	cout << "========================" << endl;
	int year{}, month{}, day{};

	cout << "Введите день:" << endl;
	cout << "Ввод >> ";
	cin >> day;

	cout << "\nВведите месяц:" << endl;
	cout << "Ввод >> ";
	cin >> month;

	cout << "\nВведите год:" << endl;
	cout << "Ввод >> ";
	cin >> year;

	int select = -1;
	while (select != 0) {
		system("cls");
		PrintTableHeader();

		int size = dataList.size();
		for (int i = 0; i < size; i++) {
			if (dataList[i].getDate().year == year and dataList[i].getDate().month == month and dataList[i].getDate().day == day) {
				PrintTableContent(dataList, i);
			}
		}
		cout << "(0 - Назад)\n" << endl;
		cout << "Ввод >> ";
		cin >> select;
	}
}

void SearchingBySurname() {
	system("cls");

	cout << "Поиск по фио:" << endl;
	cout << "=============" << endl;
	cout << "Введите фамилию:\n" << endl;

	cout << "Ввод >> ";
	char surName[20]{ "\0" };
	cin >> setw(20) >> surName;
	cin.clear();
	cin.ignore(1000, '\n');

	int select = -1;
	while (select != 0) {
		system("cls");
		PrintTableHeader();

		int size = dataList.size();
		for (int i = 0; i < size; i++) {
			if (_stricmp(dataList[i].getClient().surName, surName) == 0) {
				PrintTableContent(dataList, i);
			}
		}
		cout << "(0 - Назад)\n" << endl;
		cout << "Ввод >> ";
		cin >> select;
	}
}

void Searching() {
	int select = -1;
	while (select != 0) {
		system("cls");
		cout << "Поиск:" << endl;
		cout << "======" << endl;
		cout << "1 - По марке автомобиля" << endl;
		cout << "2 - По номеру автомобиля" << endl;
		cout << "3 - По дате обращения" << endl;
		cout << "4 - По фио" << endl;
		cout << "\n(0 - Назад)\n" << endl;

		cout << "Ввод >> ";
		cin >> select;

		system("cls");
		switch (select)
		{
		case 0:
			break;
		case 1:
			SearchingByBrand();
			break;
		case 2:
			SearchingByLicense();
			break;
		case 3:
			SearchingByDate();
			break;
		case 4:
			SearchingBySurname();
			break;
		default:
			cout << "Неверное значение!\n" << endl;
			break;
		}
	}
}

void menu() {
	int select = -1;
	while (select != 0) {
		system("cls");
		cout << "Меню:" << endl;
		cout << "=====" << endl;
		cout << "1 - Просмотр записей" << endl;
		cout << "2 - Добавление записи" << endl;
		cout << "3 - Удаление записи" << endl;
		cout << "4 - Изменение записи" << endl;
		cout << "5 - Сортировка" << endl;
		cout << "6 - Поиск" << endl;
		cout << "\n(0 - Выход)\n" << endl;

		cout << "Ввод >> ";
		cin >> select;

		system("cls");
		switch (select)
		{
		case 0:
			break;
		case 1:
			PrintTable();
			break;
		case 2:
			Add();
			break;
		case 3:
			Deleting();
			break;
		case 4:
			Edit();
			break;
		case 5:
			Sorting();
			break;
		case 6:
			Searching();
			break;
		default:
			cout << "Неверное значение!\n" << endl;
			break;
		}
	}
}

int main() {
	system("chcp 1251 > nul");
	setlocale(LC_ALL, "RUS");

	FileLoad();
	menu();

	return 0;
}