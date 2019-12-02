#include "stdafx.h"
#include "StockSuggestion.h"

StockSuggestion::StockSuggestion(double Buy, double Sell, double StopLoss)
{
	this->Buy = Buy;
	this->Sell = Sell;
	this->StopLoss = StopLoss;
}
