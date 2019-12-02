#pragma once

#include "BaseMetric.h"
#include "FileReader.h"
#include "StockCompany.h"
#include "StockDayDetails.h"

ref class Controller
{
public:
	Controller();
	void loadInData(String^);
	void performStrategySuggestion();
	void performSimulation(double investment, DateTime startDate, DateTime endDate);

private:
	BaseMetric ^metric;
	FileReader fReader;
};

