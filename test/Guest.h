#pragma once

#include "Account.h"
#include "VIP.h"

class Guest :
public Account
{
public:
	bool rentItem(string itemId) override;
	bool isConcreteAccount(string type) override;
	Account* promote() override;
};
