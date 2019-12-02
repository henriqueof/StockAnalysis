#pragma once
ref class StockSuggestion
{
public:
	StockSuggestion(double Buy,	double Sell, double StopLoss);

	double getBuy() { return Buy; }
	double getSell() { return Sell; }
	double getStopLoss() { return StopLoss; }

private:
	double Buy;
	double Sell;
	double StopLoss;
};

