#include "VIP.h"
#include "Guest.h"

bool VIP::isConcreteAccount(string type) 
{
	if (type == "vip") return true;
	return false;
}

Account* VIP::promote() 
{
	return NULL;
}
