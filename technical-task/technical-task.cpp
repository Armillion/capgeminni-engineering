// technical-task.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "technical-task.h"

//Phone struct specific implementations

//default constructor
PhoneShop::Phone::Phone() : brandName(), modelName(), formFactor(), 
							screenSize(), yearOfIssue(), price(0) {}

//full constructor
PhoneShop::Phone::Phone(string brand, string model, string ffactor,
	string year, string sSize, double p)
{
	brandName = brand;
	modelName = model;
	formFactor = ffactor;
	yearOfIssue = year;
	screenSize = sSize;
	price = p;
}

//destructor
PhoneShop::Phone::~Phone() {}


//Phone Shop specific implementations

//constructor
PhoneShop::PhoneShop() 
{
	phoneList = new vector<Phone>;
}

//destructor
PhoneShop::~PhoneShop()
{
	delete phoneList;
}

//method implementations

//complexity: O(1)
void PhoneShop::addPhone(string brand, string model, string ffactor,
	string year, string screenSize, double price)
{
	Phone newPhone(brand, model, ffactor, year, screenSize, price);
	phoneList->push_back(newPhone);
}

//a phone is defined by all of its variables
//we could have 2 phones with same parameters but different prices for example
//compoexity: O(n) due to iteration over entire list
void PhoneShop::deletePhone(string brand, string model, string ffactor,
	string year, string screenSize, double price)
{
	for (int i = 0; i < phoneList->size(); i++)
	{
		if (brand == (*phoneList)[i].brandName &&
			model == (*phoneList)[i].modelName &&
			ffactor == (*phoneList)[i].formFactor &&
			year == (*phoneList)[i].yearOfIssue &&
			screenSize == (*phoneList)[i].screenSize &&
			price == (*phoneList)[i].price)
		{
			phoneList->erase(phoneList->begin() + i);
			return;
		}
	}

	cout << "Didnt find the phone with entered parameters" << endl;
}

//shows all phones
//complexity: O(n) due to iteration over entire list
void PhoneShop::report()
{
	cout << "Brand \t Model \t Form Factor \t Year of Issue \t Screen Size \t Price" << endl;
	for (int i = 0 ; i < phoneList->size(); i++)
	{
		cout << (*phoneList)[i].brandName << " \t " << (*phoneList)[i].modelName << " \t " <<
			(*phoneList)[i].formFactor << " \t " << (*phoneList)[i].yearOfIssue << " \t " <<
			(*phoneList)[i].screenSize << " \t " << (*phoneList)[i].price << endl;
	}
}

//shows all phones of a given brand
//complexity: O(n) due to iteration over entire list
void PhoneShop::show(string brand)
{
	for (int i = 0 ; i < phoneList->size(); i++)
	{
		if ((*phoneList)[i].brandName == brand)
		{
			cout << (*phoneList)[i].brandName << " \t " << (*phoneList)[i].modelName << " \t " <<
				(*phoneList)[i].formFactor << " \t " << (*phoneList)[i].yearOfIssue << " \t " <<
				(*phoneList)[i].screenSize << " \t " << (*phoneList)[i].price << endl;
		}
	}
}

//shows all phones of a given form and screen size
//complexity: O(n) due to iteration over entire list
void PhoneShop::show(string ffactor,string ssize)
{
	for (int i = 0; i < phoneList->size(); i++)
	{
		if ((*phoneList)[i].formFactor == ffactor && (*phoneList)[i].screenSize == ssize)
		{
			cout << (*phoneList)[i].brandName << " \t " << (*phoneList)[i].modelName << " \t " <<
				(*phoneList)[i].formFactor << " \t " << (*phoneList)[i].yearOfIssue << " \t " <<
				(*phoneList)[i].screenSize << " \t " << (*phoneList)[i].price << endl;
		}
	}
}


//done using map to count repeting screen sizes
//and then finding printing and removing element 
//with most number of repetitions 3 times
//complexity: O(n) due to iteration over entire list
void PhoneShop::showTop3ScreenSizes()
{
	int top = 3;
	unordered_map<string, int> hash;
	for (int i = 0; i < phoneList->size(); i++)
	{
		hash[(*phoneList)[i].screenSize]++;
	}

	int count = 0;
	string res = "";
	for (int i = 0; i < top; i++)
	{
		for (auto i : hash) {
			if (count < i.second) {
				res = i.first;
				count = i.second;
			}
		}

		cout << i+1 << ". " << res << endl;
		hash.erase(res);
		count = 0;

		if (hash.empty())
			break;
	}
}
//worsk the same as the function above
//but insteard of finding and removing max of map 3 times
//we do it number of times equal to its number of elements
//complexity: O(n^2) due to nested loops
void PhoneShop::showMostPopularBrands()
{
	unordered_map<string, int> hash;
	for (int i = 0; i < phoneList->size(); i++)
	{
		hash[(*phoneList)[i].brandName]++;
	}

	int top = hash.size();
	int count = 0;
	string res = "";

	for (int i = 0; i < top; i++)
	{
		for (auto i : hash) {
			if (count < i.second) {
				res = i.first;
				count = i.second;
			}
		}

		cout << i+1 << ". " << res << endl;
		hash.erase(res);
		count = 0;
	}
}


int main()
{
	PhoneShop shop;
	string input;
	
	cout << "Type help for list of commands." << endl;
	while (1)
	{
		cin >> input;

		if (input == "help")
		{
			cout << "List of commands: \n " <<
				"add - allows to add a phone to the records \n" <<
				"delete - allows to delete a phone from the records \n" <<
				"report - shows all phones currently in the shop \n" <<
				"top3 - show top 3 most popular screen sizes in shop \n" <<
				"popular - shows all brands of phones in shop in order of popularity \n" <<
				"brand - show all phones of provided brand \n" <<
				"form / screen - show all phones of privided form factor and screen size \n" <<
				"exit - leave the program " << endl;
		}
		if (input == "add")
		{
			string stats[5];
			double p;
			cout << "Provide a brand: " << endl;
			cin >> stats[0];
			cout << "Provide a model: " << endl;
			cin >> stats[1];
			cout << "Provide a form factor: " << endl;
			cin >> stats[2];
			cout << "Provide a year of issue: " << endl;
			cin >> stats[3];
			cout << "Provide a screen size: " << endl;
			cin >> stats[4];
			cout << "Privide a price: " << endl;
			cin >> p;
			shop.addPhone(stats[0], stats[1], stats[2], stats[3], stats[4], p);
		}
		if (input == "delete")
		{
			string stats[5];
			double p;
			cout << "Provide a brand: " << endl;
			cin >> stats[0];
			cout << "Provide a model: " << endl;
			cin >> stats[1];
			cout << "Provide a form factor: " << endl;
			cin >> stats[2];
			cout << "Provide a year of issue: " << endl;
			cin >> stats[3];
			cout << "Provide a screen size: " << endl;
			cin >> stats[4];
			cout << "Privide a price: " << endl;
			cin >> p;
			shop.deletePhone(stats[0], stats[1], stats[2], stats[3], stats[4], p);
		}
		if (input == "top3")
		{
			shop.showTop3ScreenSizes();
		}
		if (input == "popular")
		{
			shop.showMostPopularBrands();
		}
		if (input == "brand")
		{
			string brand;
			cout << "Privide a brand name: " << endl;
			cin >> brand;
			shop.show(brand);
		}
		if (input == "form" || input == "screen")
		{
			string stats[2];
			cout << "Provide a form factor: " << endl;
			cin >> stats[0];
			cout << "Provide a screen size: " << endl;
			cin >> stats[1];
			shop.show(stats[0], stats[1]);
		}
		if (input == "report")
		{
			shop.report();
		}
		if (input == "exit")
		{
			return 0;
		}
	}

	return 0;
}
