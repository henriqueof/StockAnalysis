#pragma once
#include "StockData.h"
using namespace System;
using namespace System::IO;
ref class FileReader
{
public:
	FileReader();
	void setBaseDir(String^);
	String^ getBaseDir();
	StockData^ getStockData();
	void readAllStockData();

private:
	String^ baseDir;
	StockData stockData;
	void readDailyData(String^);
};

