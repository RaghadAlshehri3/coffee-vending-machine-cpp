/*******  This CPP Program is written by RAGHAD  *******/
#include <iostream>
using namespace std;

// constant declarations
const int NUM_OF_DRINKS = 50;
const int LATTE_PRICE = 5;
const int CAPPUCCINO_PRICE = 5;
const int BLACK_COFFEE_PRICE = 2;
const int HOT_CHOCOLATE_PRICE = 3;
const int ADMIN_PASSWORD = 1234;

int main()
{
	int drinkCount[4] = {NUM_OF_DRINKS, NUM_OF_DRINKS, NUM_OF_DRINKS, NUM_OF_DRINKS};
	int drinkSales[4] = {0, 0, 0, 0};
	int drinkPrice[4] = {LATTE_PRICE, CAPPUCCINO_PRICE, BLACK_COFFEE_PRICE, HOT_CHOCOLATE_PRICE};
	int CashRegister = 0;
	
	int selection;
	int payment = 0;
	int password;
	bool shutdown = false;
	bool insufficient;
	int extraPayment;
	
	while (!shutdown)
	{
		cout << "Please select your drink: \n" 
		     << "For Latte press 1 \n"
		     << "For Cappuccino press 2 \n"
		     << "For Black Coffee press 3 \n"
		     << "For Hot Chocolate press 4 \n"
		     << "To exit and get your change press 5 \n"
		     << "For Admins: To print a report press 6 \n"
		     << "For Admins: To shutdown the vending machine press 0 \n"
		     << "______________________________________________________________________________" << endl;
		     
		// get user selection
		cout << "Enter your selection: " ;
		cin >> selection;
		
		switch (selection) 
		{
			case 1:
			case 2:
			case 3:
			case 4:
				//check if the selected drink is available...
				if(drinkCount [selection -1] > 0)
				{
					cout << "please insert " << drinkPrice[selection -1]  << " Riyals: ";
					cin >> payment;
				
				
				// funds ...
				if (payment < drinkPrice[selection -1])
				{
					insufficient = true;
					cout << "please insert " << drinkPrice[selection -1] - payment << " Riyals: ";
					cin >> extraPayment;
					payment += extraPayment;
				}
				
				// update cash register and sell the product...
				if (payment >= drinkPrice[selection -1])
				{
					CashRegister += drinkPrice[selection -1];
					drinkCount[selection -1]--;
					drinkSales[selection -1]+= drinkPrice [selection -1];
					cout << "Please take your drink. Thank you! " << endl;
					cout << "The cash balance: " << payment - drinkPrice [selection -1] << " Riyals " << endl;
				}
				
			    }
			    
			 else
			 cout << "this drink is sould out! " << endl;
				
			break;
			
			case 5:
				// Return change...
				cout << "Thanks for your purchase whith us." << endl;
				cout << "please take your change of: " << payment - drinkPrice [selection -1] << " Riyals " << endl;
				payment = 0;
				
			break;
			
			case 6:
				// print report (requires admin password)...
				cout << "Enter Admin password: ";
				cin >> password;
				if (password == ADMIN_PASSWORD)
				{
					cout << "\n" <<endl;
					cout << "______________________________________________ Vending Machine Report __________________________________________" << endl;
					cout << "The number of Latte sould is: " << NUM_OF_DRINKS - drinkCount[0] << " for a total of: " << drinkSales[0] << " Riyals " << endl;
					cout << "The number of Cappuccino sould is: " << NUM_OF_DRINKS - drinkCount[1] << " for a total of: " << drinkSales[1] << " Riyals " << endl;
					cout << "The number of Black Coffee sould is: " << NUM_OF_DRINKS - drinkCount[2] << " for a total of: " << drinkSales[2] << " Riyals " << endl;
					cout << "The number of Hot Chocolate sould is: " << NUM_OF_DRINKS - drinkCount[3] << " for a total of: " << drinkSales[3] << " Riyals " << endl;
					cout << "Customer Cash balance: " <<   payment - drinkCount [selection -1] << " Riyals " << endl;
					cout << "The amount today's sales is " << CashRegister << " Riyals " << endl;
					cout << "______________________________________________ End of Report __________________________________________" << endl;
				}
				
			    else 
			    cout << "Incorrect password. Access denied." << endl;
				
			break;
			
			case 0:
			    // shutdown the system (requires admin password)...
			    cout << "Enter Admin password: ";
				cin >> password;
				if (password == ADMIN_PASSWORD)
				{
					shutdown = true;
					cout << "______________________________________________ Vending Machine Report __________________________________________" << endl;
					cout << "The number of Latte sould is: " << NUM_OF_DRINKS - drinkCount[0] << " for a total of: " << drinkSales[0] << " Riyals " << endl;
					cout << "The number of Cappuccino sould is: " << NUM_OF_DRINKS - drinkCount[1] << " for a total of: " << drinkSales[1] << " Riyals " << endl;
					cout << "The number of Black Coffee sould is: " << NUM_OF_DRINKS - drinkCount[2] << " for a total of: " << drinkSales[2] << " Riyals " << endl;
					cout << "The number of Hot Chocolate sould is: " << NUM_OF_DRINKS - drinkCount[3] << " for a total of: " << drinkSales[3] << " Riyals " << endl;
					cout << "Customer Cash balance: " <<   payment - drinkCount [selection -1] << " Riyals " << endl;
					cout << "The amount today's sales is " << CashRegister << " Riyals " << endl;
					cout << "______________________________________________ End of Report __________________________________________" << endl;
					
					cout << "VENDING MACHINE IS SHUTTING DOWN ......  " << endl;
				}
				
				else 
				cout <<"Incorrect password. Access denied. " << endl;
				
			break;
			
			
			default:
				cout << "Invalid selection. Please try again... " << endl;
		}
	}
	
	return 0;
}
