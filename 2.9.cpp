  
#include <iostream>

int func(int a, int b)
{
	if (a >= b)
	{
		func(a - b, b);
	}
	else
	{
		return a;
	}
}

int main()
{
	int x, y;
	std::cin >> x >> y;
	std::cout << func(x, y) << std::endl;

	system("pause");
	return 0;
}
