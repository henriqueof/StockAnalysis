#include "stdafx.h"
#include "StockData.h"


StockData::StockData()
{
	stockData = gcnew List<StockCompany^>();
}

void StockData::addStock(StockCompany^ toAdd)
{
	stockData->Add(toAdd);
}

StockCompany^ StockData::getStockCompany(int index)
{
	return stockData[index];
}

int StockData::getStockCompanySize()
{
	return stockData->Count;
}