#include "stdafx.h"
#include "Controller.h"
#include "MovingAverageMetric.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace std;

Controller::Controller()
{
	FileReader fReader; //create the file reader object
}

void Controller::loadInData(String^ director)
{
	//set the base directory
	fReader.setBaseDir(director);

	//read all stock data
	fReader.readAllStockData();

	metric = gcnew MovingAverageMetric(fReader.getStockData());
}

void Controller::performStrategySuggestion()
{
	// Shows suggestions for every stock using Moving Average metrics.
	metric->performSuggestion();
}

void Controller::performSimulation(double investment, DateTime startDate, DateTime endDate)
{
	// See if we have a valid date interval
	if (startDate >= endDate)
	{
		Console::WriteLine("Invalid date interval");
		return;
	}

	// Limit the date interval to the data we have to simulate.
	if (startDate < DateTime::Parse("2010-02-01") || endDate > DateTime::Parse("2015-08-25"))
	{
		Console::WriteLine("Date should be between 2010-02-01 and 2015-08-25");
		return;
	}

	metric->performSimulation(investment, startDate, endDate);
}