#pragma once
#include <string>

class EquityAnalysis
{
public:
	EquityAnalysis();
	EquityAnalysis(long long tGap, long vol, long long tVolume, float avPrice, long mPrice, long long lastTTime);
	void updateTimeGap(long long tradeTime);
	void calculateWeightedAveragePrice(long curPrice, long curQuantity);
	void updateTradeVolume(long curQuantity);
	void updateMaxPrice(long curPrice);
	long long getTimeGap()
	{
		return timeGap;
	}
	long getVolume()
	{
		return volume;
	}
	float getAveragePrice()
	{
		return avgPrice;
	}
	long getMaxPrice()
	{
		return maxPrice;
	}
private:
	long long timeGap;
	long volume;
	long long totalTradeValue;
	float avgPrice;
	long maxPrice;
	long long lastTradeTime;
};