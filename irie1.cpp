#include <curl/curl.h> //curl.h must be before the rest, as easy.h and perhaps more are dependent on its definitions
#include <curl/easy.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void printPortfolio() //printPortfolio simply print the current portfolio of stocks owned, including quantity, price purchased, and current price
{ 
	string portfolio = "portfolio.txt"; string tempString = ""; const int MAXSIZE = 100; string tempArray[MAXSIZE]; int i = 0; //These variables all allow me to be able to circle through the lists I need to.	
	ifstream input; input.close(); input.open(portfolio.c_str());

		if (input.fail()) {cout << "Failed to open portfolio file\n";}
		else 	{
		while (!input.eof())	{
		
			if (i <= 8) {input >> tempArray[i]; cout << tempArray[i] << " "; i++;} //8 corresponds to the # of columns in the file portfolio.txt..
			else if (i == 9) {cout << "\n"; i = 0;} // 9 = 8+1;  Perhaps I should add another variable called (columnsInPortfolio)
								}
				}
		if (input.eof()) {input.close();}
}

string searchAllSymbols(string userInputSymbol) 
{
	string allKnownTickers = "allTickers.txt"; string tempString = ""; string success = "Successfully found the ticker you want to add.\n"; string failed = "Failed to locate the ticker symbol you requested to add. Please check your spelling, and if that is correct, please send an email to cbkodadek@gmail.com requesting that it be added.\n";
	ifstream input; input.close(); input.open(allKnownTickers.c_str());
		while (!input.eof()) {
			input >> tempString;
			if (tempString == userInputSymbol) {return success;}}
		if (input.eof()) {return failed;}
}

void addStock() 
{
	string tickerSymbol = "";
	cout << "Please input the stock ticker symbol you would like to add.\n";
	cin >> tickerSymbol;
	cout << searchAllSymbols(tickerSymbol);
}

void extractData() 
{
	string urlList = "urlList.txt"; string temp = "";
	ifstream inputURL; inputURL.close(); inputURL.open(urlList.c_str());
	if (inputURL.fail()) {cout << "Could not find the file " << urlList << endl;}
	while (!inputURL.eof()) {
		inputURL >> temp;
		LPCSTR websiteURL = temp.c_str();
	 ShellExecute(NULL, "open", websiteURL, NULL, NULL, SW_SHOWNORMAL);
	 //This is where I want to call the function that analyzes it.
	 //Save webpage to .txt
	 //Algorithms analyzing .txt

	 //Start foreign code


	 //End foreign code
	 cout << "Extracted data from " << temp << endl;
	 ShellExecute(NULL, "close", websiteURL, NULL, NULL, SW_SHOWNORMAL);
	}
	if (inputURL.eof()) {inputURL.close();}
	//Now, I need it to actually search through the page and extract data...
	//I got it to open the page(s) up, however, it has a strict conformity to http://www. format
	

}

int main() {
	int tradingPeriod = 1; //This is when the trading period begins, if it is bound by the market's tradeable hours.
	cout << "What would you like to do? Type '1' to print portfolio, and 0 to exit\n";
	int command = 1000;
	curl --trace-ascii debugdump.txt

	while (command != 0) {
		cin >> command;
		if (command == 1) {printPortfolio();}
		else if (command == 2) {addStock();}
		else if (command == 3) {extractData();}

	}

	return 0;
}
