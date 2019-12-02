#include "stdafx.h"
#include "StockCompany.h"

StockCompany::StockCompany()
{

	//List<StockDayDetails^> dailyList;
		//dailyDetails = %dailyList;
		dailyDetails = gcnew List<StockDayDetails^>();
}

void StockCompany::addDayDetails(StockDayDetails^ newDay)
{
	dailyDetails->Add(newDay);
}

String^ StockCompany::getEpic()
{
	return epic;
}

void StockCompany::setEpic(String^ newEpic)
{
	epic = newEpic;
}


StockDayDetails^ StockCompany::getDailyDetails(int index)
{
	return dailyDetails[index];
}

StockDayDetails^ StockCompany::getDailyDetails(DateTime day)
{
	for each (StockDayDetails ^currentDay in dailyDetails)
	{
		if (currentDay->getDate()->ToUniversalTime() == day.ToUniversalTime())
		{
			return currentDay;
		}
	}
}

void StockCompany::setSuggestion(StockSuggestion ^ suggestion)
{
	this->suggestion = suggestion;
}

int StockCompany::getDailyCompanySize()
{
	return dailyDetails->Count;
}
