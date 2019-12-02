#pragma once
#include "BaseMetric.h"

ref class AverageMetric : public BaseMetric
{
public:
	AverageMetric(StockData ^);

	virtual void performSuggestion();
	virtual void performSimulation(double investment, DateTime startDate, DateTime endDate);

private:
	StockData^ stockData;
};

