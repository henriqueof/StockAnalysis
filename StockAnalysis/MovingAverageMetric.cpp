#include "stdafx.h"
#include "MovingAverageMetric.h"


MovingAverageMetric::MovingAverageMetric(StockData^ _stockData)
{
	stockData = _stockData;
}

void MovingAverageMetric::performSuggestion()
{
	Console::WriteLine("Performing Suggestions Based On Moving Average Metric");

	// Reference http://www.investopedia.com/articles/active-trading/052014/how-use-moving-average-buy-stocks.asp

	for (int i = 0; i < stockData->getStockCompanySize(); i++) // loop over each company
	{
		double Buy = 0;
		double Sell = 0;
		double StopLoss = 0;

		for (int j = 0; j < stockData->getStockCompany(i)->getDailyCompanySize(); j++) // loop over each company's daily values
		{
			double Average15 = DayAverage(i, j, 15);
			double Average200 = DayAverage(i, j, 200);

			double dailyBuy = 0;
			double dailySell = 0;

			if (Average15 > Average200)
			{
				dailyBuy = Average15;
			}

			if (Average15 < Average200)
			{
				dailySell = Average15;
			}

			// ...
			if (Buy == 0)
			{
				Buy = dailyBuy;
			}
			else if (dailyBuy < Buy)
			{
				Buy = dailyBuy;
			}

			if (Sell == 0)
			{
				Sell = dailySell;
			}
			else if (dailySell > Sell)
			{
				Sell = dailySell;
			}
		}

		// Stop loss is calculate by subtracting 20% of the buy price, to reduce potential loss.
		StopLoss = Buy - (Buy / 100 * 20);

		stockData->getStockCompany(i)->setSuggestion(gcnew StockSuggestion(Buy, Sell, StopLoss));

		Console::WriteLine(stockData->getStockCompany(i)->getEpic() + " BUY @ " + Buy.ToString("0.00") + ", SELL @ " + Sell.ToString("0.00") + ", STOP LOSS @ " + StopLoss.ToString("0.00"));
	}

	Console::Write("\n\n");
}

void MovingAverageMetric::performSimulation(double investment, DateTime startDate, DateTime endDate)
{
	Console::WriteLine("Performing Simulation Based On Moving Average Metric");
	Console::WriteLine("Date interval: " + startDate.ToShortDateString() + " to " + endDate.ToShortDateString());

	for (int i = 0; i < stockData->getStockCompanySize(); i++) // loop over each company
	{
		StockCompany ^currentCompany = stockData->getStockCompany(i);

		double Investment = 0;
		double StopLoss = 0;

		double Buy = currentCompany->getSuggestion()->getBuy();
		double Sell = currentCompany->getSuggestion()->getSell();

		// Find out how many shares we can buy using investment
		int shares = (investment / Buy);

		if (shares == 0)
			continue;

		Console::WriteLine("\nSimulation for " + currentCompany->getEpic());

		// Loop through the days...
		DateTime currentDate = startDate;

		while (currentDate.ToUniversalTime() < endDate.ToUniversalTime())
		{
			StockDayDetails ^dayDetails = currentCompany->getDailyDetails(currentDate);

			// Days that there is no value should be ignored
			if (dayDetails == nullptr)
			{
				currentDate = currentDate.AddDays(1);
				continue;
			}

			// The price is equal or bellow the buy price suggestion, we should buy.
			if (dayDetails->getAdjClose() <= Buy && Investment == 0)
			{
				Investment = shares * dayDetails->getAdjClose();
				StopLoss = dayDetails->getAdjClose() - (dayDetails->getAdjClose() * 20 / 100); // Stop loss is when the value of the stock is below the cost minus 20%.

				Console::WriteLine(currentDate.ToShortDateString() + ": BUY " + shares + " @ " + dayDetails->getAdjClose().ToString("0.00") + " INVESTIMENT "+ Investment.ToString("0.00"));
			}

			// The price is equal or bellow our stop loss value, we shoul sell it and face the loss
			if (dayDetails->getAdjClose() <= StopLoss && Investment != 0)
			{
				Double Loss = Investment - (dayDetails->getAdjClose() * shares);
				Console::WriteLine(currentDate.ToShortDateString() + ": SELL " + shares + " @ "+ dayDetails->getAdjClose().ToString("0.00") + " LOSS " + Loss.ToString("0.00"));
				break;
			}

			// The price is equal or above the sell suggestion price, we should sell it and enjoy the earnings.
			if (dayDetails->getAdjClose() >= Sell && Investment != 0)
			{
				Double Increase = (dayDetails->getAdjClose() * shares) - Investment;
				Console::WriteLine(currentDate.ToShortDateString() + ": SELL " + shares + " @ " + dayDetails->getAdjClose() + " INCREASE " + Increase.ToString("0.00"));
				break;
			}

			currentDate = currentDate.AddDays(1);
		}
	}
}

double MovingAverageMetric::DayAverage(int company, int currentDay, int days)
{
	// Calculate day average based on the sum of the last days divided by number os days.
	double Average = 0;

	if(currentDay >= days)
	{
		for (int i = currentDay; i > (currentDay - days); i--)
		{
			Average += stockData->getStockCompany(company)->getDailyDetails(i)->getAdjClose();
		}

		Average /= days;
	}

	return Average;
}