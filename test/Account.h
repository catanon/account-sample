#pragma once

#include <string>
#include "DynamicArray.h"

using namespace std;

class Account {
protected:
	DynamicArray<string> rentList;
public:
	DynamicArray<string> getRentList();
	virtual bool rentItem(string itemId);
	virtual bool isConcreteAccount(string type) = 0;
	void displayAccount();
	virtual Account* promote() = 0;
};
