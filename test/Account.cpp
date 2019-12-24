#include "Account.h"
#include <iostream>

using namespace std;

DynamicArray<string> Account::getRentList() {
	return rentList;
}
	bool Account::rentItem(string itemId)
	{
		rentList.add(itemId);
		return true;
	}

	void Account::displayAccount()
	{
		cout << "Start account information." << endl;
		for (int i = 0; i < rentList.size(); i++)
		{
			cout << rentList.get(i) << endl;
		}
		cout << "End account information." << endl;
	}
