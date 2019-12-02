#include "stdafx.h"
#include "AverageMetric.h"
#include "StockData.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;
using namespace System;

//define short name for multiple type
typedef multimap< double, string , less< double > > mmap;

//this function is purely to convert from a Microsoft String^ to a std::string. Do not worry what is happening.
void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

AverageMetric::AverageMetric(StockData^ stockData)
{
	this->stockData = stockData;
}

void AverageMetric::performSuggestion()
{
	Console::WriteLine("Performing Example Metric");

	mmap metricScores; //map to store our results in the format of <CompanyName, MetricResult>

	for (int i = 0; i < stockData->getStockCompanySize(); i++) // loop over each company
	{
		double cAvgOpen = 0.0;
		double cAvgClose = 0.0;
		double different = 0.0;
		for (int j = 0; j < stockData->getStockCompany(i)->getDailyCompanySize(); j++) // loop over each company's daily values
		{
			//accumulate the values
			cAvgOpen += stockData->getStockCompany(i)->getDailyDetails(j)->getOpen();
			cAvgClose += stockData->getStockCompany(i)->getDailyDetails(j)->getClose();
		}
		//divide them by the numer of entries to get the average
		cAvgOpen = cAvgOpen / stockData->getStockCompany(i)->getDailyCompanySize();
		cAvgClose = cAvgClose / stockData->getStockCompany(i)->getDailyCompanySize();
		different = cAvgOpen - cAvgClose;

		//convert the String^ to a std:string for the multimap
		string epic = "";
		String ^ crlEpic = stockData->getStockCompany(i)->getEpic();
		MarshalString(crlEpic, epic);

		//add the result to the multimap
		metricScores.insert(mmap::value_type(different, epic));
	}

	//the multimap is stored acsending order. I.e those with the largest difference are located towards the end of the hashmap.
	//Therefore, those at the end of the  multimap might be of interest. 
	for (mmap::const_iterator iter = metricScores.begin(); iter != metricScores.end(); iter++)
	{
		cout << iter->first << '\t' << iter->second << endl;
	}
}

void AverageMetric::performSimulation(double investment, DateTime startDate, DateTime endDate)
{
	// TODO
	throw gcnew System::NotImplementedException();
}
