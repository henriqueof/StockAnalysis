#pragma once
#include "StockData.h"

interface class BaseMetric
{
	virtual void performSuggestion() = 0;
	virtual void performSimulation(double investment, DateTime startDate, DateTime endDate) = 0;
};
