#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Account.h"
#include "Guest.h"
#include "VIP.h"

using namespace std;


class AccountManager
{
private:
	DynamicArray<Account*> accList;
public:
	void addAccount()
	{
		accList.add(new Guest());
	}

	bool rent(int id, string things)
	{
		// Assume `id` is the index of accList for short sample
		if (id < 0 || id >= accList.size()) return false;

		return accList.get(id)->rentItem(things);
	}

	void promote(int id)
	{
		if (id < 0 || id >= accList.size()) cout << "Can't find this account";
		
		Account* newTier = accList.get(id)->promote();
		if (newTier == NULL)
		{
			cout << "This is already the highest tier." << endl;
		}
		else
		{
			accList.set(id, newTier);
		}
	}

	void displayGroup(string type)
	{
		cout << "Display ground " << type << endl;
		for (int i = 0; i < accList.size(); i++)
		{
			Account* currentAccount = accList.get(i);
			if (currentAccount->isConcreteAccount(type)) currentAccount->displayAccount();
		}
	}
};

int main() {
	AccountManager man;
	cout << "Added 2 guest accounts." << endl;
	man.addAccount();
	man.addAccount();
	man.displayGroup("guest");

	cout << endl << "Rent a book:" << endl;
	man.rent(0, "Book");
	man.displayGroup("guest");
	
	cout << endl << "Promote:" << endl;
	man.promote(0);
	man.displayGroup("guest");
	man.displayGroup("vip");
	
	return 0;
}