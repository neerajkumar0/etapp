#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
#include <Record.h>
#include <EquityAnalysis.h>

using namespace std;

int main()
{
	ifstream infile("input.csv");
	if (!infile.good())
	{
		cout << "File not good" << endl;
		return 1;
	}

	string line;
	unordered_map<string, EquityAnalysis> trades;
	vector<string> symbols;
	while (std::getline(infile, line))
	{
		Record aRec(line);
		aRec.extractData();

		if (trades.find(aRec.getCode()) == trades.end())
		{
			long long tVolume = aRec.getPrice()*aRec.getQuantity();
			EquityAnalysis soFarTrades(0,
				aRec.getQuantity(),
				tVolume,
				static_cast<float>(aRec.getPrice()),
				aRec.getPrice(),
				aRec.getTradeTime());
			trades[aRec.getCode()] = soFarTrades;
			symbols.push_back(aRec.getCode());
		}
		else
		{
			EquityAnalysis soFarTrades = trades[aRec.getCode()];
			soFarTrades.updateTimeGap(aRec.getTradeTime());
			soFarTrades.calculateWeightedAveragePrice(aRec.getPrice(), aRec.getQuantity());
			soFarTrades.updateTradeVolume(aRec.getQuantity());
			soFarTrades.updateMaxPrice(aRec.getPrice());
			trades[aRec.getCode()] = soFarTrades;

		}
	}
	infile.close();
	ofstream outfile("output.csv");

	std::sort(symbols.begin(), symbols.end());
	for (auto it = symbols.begin(); it != symbols.end(); it++)
	{
		if (trades.find(*it) != trades.end())
		{
			long avgPrice = static_cast<long>(trades[*it].getAveragePrice());
			outfile << *it << ',' << trades[*it].getTimeGap() << ',' << trades[*it].getVolume() << ',' <<
				avgPrice << ',' << trades[*it].getMaxPrice() << endl;
		}
	}
	outfile.close();

}