#include"chian.h"

int main()
{
	dscpp::chain<int> c(1);
	//c.insert(0, 1);
	c.insert(1, 2);
	c.insert(1, 3);

	return 0;
}