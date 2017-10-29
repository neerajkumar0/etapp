#include <EquityAnalysis.h>

EquityAnalysis::EquityAnalysis(long long tGap, long vol, long long tVolume, float avPrice, long mPrice, long long lastTTime):
timeGap(tGap),
volume(vol),
totalTradeValue(tVolume),
avgPrice(avPrice),
maxPrice(mPrice),
lastTradeTime(lastTTime)
{

}

EquityAnalysis::EquityAnalysis():
	timeGap(0),
	volume(0),
	totalTradeValue(0),
	avgPrice(0),
	maxPrice(0),
	lastTradeTime(0)
{

}

void EquityAnalysis::updateTimeGap(long long tradeTime)
{
	long long curTimeGap = tradeTime - lastTradeTime;
	if (curTimeGap > timeGap)
		timeGap = curTimeGap;
	lastTradeTime = tradeTime;
}

void EquityAnalysis::calculateWeightedAveragePrice(long curPrice, long curQuantity)
{
	avgPrice = static_cast<float> ((totalTradeValue + (curPrice*curQuantity)) / (volume + curQuantity));
	totalTradeValue += curPrice*curQuantity;
}

void EquityAnalysis::updateTradeVolume(long curQuantity)
{
	volume += curQuantity;
}

void EquityAnalysis::updateMaxPrice(long curPrice)
{
	if (curPrice > maxPrice)
		maxPrice = curPrice;
}

