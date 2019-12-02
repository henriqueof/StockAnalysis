#pragma once
#include "StockDayDetails.h"
#include "StockSuggestion.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

ref class StockCompany
{
public:
	StockCompany();
	void addDayDetails(StockDayDetails^);

	void setEpic(String^);
	String^ getEpic();

	int getDailyCompanySize();
	StockDayDetails^ getDailyDetails(int index);
	StockDayDetails^ getDailyDetails(DateTime day);


	void setSuggestion(StockSuggestion ^suggestion);
	StockSuggestion ^getSuggestion() { return suggestion; }

private:
	List<StockDayDetails^>^ dailyDetails;
	StockSuggestion ^suggestion;

	String^ epic;
};

