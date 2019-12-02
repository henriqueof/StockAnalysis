#pragma once
#include "BaseMetric.h"

ref class MovingAverageMetric : public BaseMetric
{
public:
	MovingAverageMetric(StockData ^);

	virtual void performSuggestion();
	virtual void performSimulation(double investment, DateTime startDate, DateTime endDate);

private:
	double DayAverage(int company, int currentDay, int days);

	StockData^ stockData;
};
