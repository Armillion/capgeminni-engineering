// technical-task.h: plik dołączany dla standardowych systemowych plików dołączanych,
// lub pliki dołączane specyficzne dla projektu.

#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class PhoneShop {
private:

	//this represents a single phone avalible in our shop
	struct Phone {
		string brandName,
				modelName,
				formFactor,
				yearOfIssue,
				screenSize;
		double price;

		Phone();
		Phone(string brand, string model, string ffactor,
			  string year, string sSize, double p);
		~Phone();
	};

	std::vector<Phone>* phoneList;

public:
	//constructors and destructors
	PhoneShop();
	~PhoneShop();

	//metohds
	void addPhone(string brand, string model, string ffactor,
		string year, string screenSize, double price);
	void deletePhone(string brand, string model, string ffactor,
		string year, string screenSize, double price);
	void report();
	void show(string brand);					//show by brand
	void show(string ffactor, string ssize);	//show by form factor and screen size
	void showTop3ScreenSizes();			
	void showMostPopularBrands();

	//optioonal
	void saveToFile();
	void loadFromFlie(string filePath);
};

// TODO: W tym miejscu przywołaj dodatkowe nagłówki wymagane przez program.
