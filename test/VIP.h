#pragma once

#include "Account.h"
#include "Guest.h"

class VIP :
	public Account
{
public:
	bool isConcreteAccount(string type) override;

	Account* promote() override;
};
