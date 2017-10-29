#pragma once
#include <string>


class Record
{
public:
	Record(std::string line)
	{
		input = line;
	}
	void extractData();
	std::string getCode()
	{
		return symbol;
	}
	long getQuantity()
	{
		return quantity;
	}
	long getPrice()
	{
		return price;
	}
	long long getTradeTime()
	{
		return tradeTime;
	}

private:
	std::string input;
	std::string symbol;
	long long tradeTime;
	long quantity;
	long price;


};