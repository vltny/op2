#include <iostream>
#include <cstring>

using namespace std;

struct Car {
	char brand[20] = {};
	char model[20] = {};
	char licensePlate[13] = {};
};

struct Date {
	int day={0};
	int month={0};
	int year={0};
};

struct Text {
	char problem[150] = {};
	char note[150] = {};
};

struct Client {
	char name[20] = {};
	char surName[20] = {};
	char patronymic[20] = {};
	char phoneNumber[13] = {};
};

class Data {
public:
	Data(Car car, Date date, Text text, Client client) {
		this->car = car;
		this->date = date;
		this->text = text;
		this->client = client;
	}

	Data() {}
	
	//Геттеры:
	Car getCar() {
		return car;
	}

	Date getDate() {
		return date;
	}

	Text getText() {
		return text;
	}

	Client getClient() {
		return client;
	}


	//Сеттеры:
	void setCar(Car car) {
		this->car = car;
	}

	void setDate(Date date) {
		this->date = date;
	}

	void setText(Text text) {
		this->text = text;

	}

	void setClient(Client client) {
		this->client = client;
	}

private:
	Car car={};
	Date date={};
	Text text = {};
	Client client={};

};