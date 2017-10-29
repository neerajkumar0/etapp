#include <Record.h>

void Record::extractData()
{
	int x = input.find(',');
	tradeTime = std::stoll(input.substr(0, x));
	int y = input.find(',', x + 1);
	symbol = input.substr(x + 1, (y - x - 1));
	int z = input.find(',', y + 1);
	quantity = std::stol(input.substr(y + 1, (z - y - 1)));
	price = std::stol(input.substr(z + 1));
}