// FileReader.cpp : main project file.

#include "stdafx.h"
#include "Controller.h"
using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args)
{
	//NOTE: If you create an interface, you just need to create an instance of the control class

	Controller control; //create an instance of the controller class
	
	//call the load in data function passing the path where the stock datafiles are locates
	control.loadInData("CIS2343");

	Console::WriteLine("");

	//TODO: these are the two high level functions that you need to implement.
	//To help you understand, and to assist you in starting the assignemnt, I have included ONE very basic Metric. See the implementation for details..
	control.performStrategySuggestion();

	Console::Write("Enter initial investiment value: ");
	double investmentValue = Double::Parse(Console::ReadLine());

	Console::Write("Enter start date (YYYY-MM-DD): ");
	String ^startDate = Console::ReadLine();

	Console::Write("Enter end date (YYYY-MM-DD): ");
	String ^endDate = Console::ReadLine();

	Console::WriteLine("\n");

	// Performs trade simulation using the suggested values and the date interval.
	control.performSimulation(investmentValue, DateTime::Parse(startDate), DateTime::Parse(endDate));

	Console::WriteLine("");
	
	system("pause");

	return 0;
}
