#include "stdafx.h"
#include "StockDayDetails.h"


StockDayDetails::StockDayDetails()
{
}

//set methods

void StockDayDetails::setDate(DateTime newDate)
{
	date = newDate;
}

void StockDayDetails::setOpen(double newOpen)
{
	open = newOpen;
}

void StockDayDetails::setHigh(double newHigh)
{
	high = newHigh;
}

void StockDayDetails::setLow(double newLow)
{
	low = newLow;
}

void StockDayDetails::setClose(double newClose)
{
	close = newClose;
}

void StockDayDetails::setVolume(double newVolume)
{
	volume = newVolume;
}

void StockDayDetails::setAdjClose(double newAdjClose)
{
	adj_close = newAdjClose;
}

//get methods

DateTime^ StockDayDetails::getDate()
{
	return date;
}

double StockDayDetails::getOpen()
{
	return open;
}

double StockDayDetails::getHigh()
{
	return high;
}

double StockDayDetails::getLow()
{
	return low;
}

double StockDayDetails::getClose()
{
	return close;
}

double StockDayDetails::getVolume()
{
	return volume;
}

double StockDayDetails::getAdjClose()
{
	return adj_close;
}