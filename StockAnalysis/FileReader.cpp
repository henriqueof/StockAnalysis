#include "stdafx.h"
#include "FileReader.h"
#include "StockCompany.h"
#include "StockDayDetails.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace std;
FileReader::FileReader()
{
	//stockData = gcnew StockData();
}

void FileReader::setBaseDir(String^ newDir)
{
	baseDir = newDir;
}

String^ FileReader::getBaseDir()
{
	return baseDir;
}

void FileReader::readAllStockData()
{
	//iterate over all files in the base directory
	array<String^>^ files = Directory::GetFiles(baseDir);

	for (int i = 0; i < files->Length; i++)
	{
		readDailyData(files[i]);
		Console::Clear();
		array<String^>^ path = files[i]->Split('\\');
		Console::WriteLine("Finished " + path[path->Length - 1 ]);
	}
}

void FileReader::readDailyData(String^ fileName)
{
	// first create a new StockData object for this file
	StockCompany newStock;
	array<String^>^ path = fileName->Split('\\');
	newStock.setEpic(fileName->Substring(fileName->LastIndexOf('\\') + 1, fileName->LastIndexOf('.') - fileName->LastIndexOf('\\') - 1));
	StreamReader^ din = File::OpenText(fileName);
	String^ str;
	str = din->ReadLine(); //read first line to skip header

	while ((str = din->ReadLine()) != nullptr)
	{
		array<String^>^ variables = str->Split(',');
		//create a new StockDailyDetails object
		StockDayDetails stockDay;
		if (variables->Length >= 7){
			stockDay.setDate(DateTime::Parse(variables[0]));
			stockDay.setOpen(Double::Parse(variables[1]->Replace('.', ',')));
			stockDay.setHigh(Double::Parse(variables[2]->Replace('.', ',')));
			stockDay.setLow(Double::Parse(variables[3]->Replace('.', ',')));
			stockDay.setClose(Double::Parse(variables[4]->Replace('.', ',')));
			stockDay.setVolume(Double::Parse(variables[5]->Replace('.', ',')));
			stockDay.setAdjClose(Double::Parse(variables[6]->Replace('.', ',')));

			//add the object to the Stock object
			newStock.addDayDetails(%stockDay); //note % is the new &
		}
	}
	//now add the stock object to the StockData
	stockData.addStock(%newStock);
}

StockData^ FileReader::getStockData()
{
	return %stockData;
}