#include "Guest.h"
#include "VIP.h"

	bool Guest::rentItem(string itemId) 
	{
		if (rentList.size() == 2) return false;
		return Account::rentItem(itemId);
	}

	bool Guest::isConcreteAccount(string type) 
	{
		if (type == "guest") return true;
		return false;
	}

	Account* Guest::promote() 
	{
		Account* newTier = new VIP;
		for (int i = 0; i < rentList.size(); i++)
		{
			newTier->rentItem(rentList.get(i));
		}
		return newTier;
	}

