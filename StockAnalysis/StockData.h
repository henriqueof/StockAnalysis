#pragma once
#include "StockCompany.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
ref class StockData
{
public:
	StockData();
	void addStock(StockCompany^);
	int getStockCompanySize();
	StockCompany^ getStockCompany(int index);
private:
	List<StockCompany^>^ stockData;
};

