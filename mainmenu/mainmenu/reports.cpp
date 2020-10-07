#include "serendipity.h"
#include "bookType.h"

void reports()
{
	char reportsChoice = '0';
	string title3 = "Reports";
	int len3 = title3.length();

	do
	{
		system("cls");

		cout << setfill(' ');
		cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
		cout << setw((SIZE_MENUS / 2) + len3 / 2) << right << title3 << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "1. Inventory Listing" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "2. Inventory Wholesale Value" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "3. Inventory Retail Value" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "4. Listing by Quantity" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "5. Listing by Cost" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "6. Listing by Age" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "7. Return to Main Menu" << endl;
		cout << endl;
		
		cout << setw(SIZE_MENUS / 3) << "" << "Enter Your Choice: ";
		cin >> reportsChoice;
		cin.ignore(100, '\n');
		cout << endl;

		if (reportsChoice == '1')
		{
			repListing();
		}
		else if (reportsChoice == '2')
		{
			repWholesale();
		}
		else if (reportsChoice == '3')
		{
			repRetail();
		}
		else if (reportsChoice == '4')
		{
			repQty();
		}
		else if (reportsChoice == '5')
		{
			repCost();
		}
		else if (reportsChoice == '6')
		{
			repAge();
		}
		else if (reportsChoice == '7')
		{
			break;
		}
		else
		{
			reportsChoice = '0';
			cout << setw(SIZE_MENUS / 3) << "" << "Please enter a number in the range 1 - 7. " << endl;
			cout << setw(SIZE_MENUS / 3) << "";
			system("pause");
		}

	} while (reportsChoice != '7');
}

void repListing()
{
	cout << setw(SIZE_MENUS / 3) << "" << "You selected Inventory Listing." << endl;
	cout << setw(SIZE_MENUS / 3) << "";
	system("pause");
}

void repWholesale()
{
	cout << setw(SIZE_MENUS / 3) << "" << "You selected Inventory Wholesale Value." << endl;
	cout << setw(SIZE_MENUS / 3) << "";
	system("pause");
}

void repRetail()
{
	cout << setw(SIZE_MENUS / 3) << "" << "You selected Inventory Retail Value." << endl;
	cout << setw(SIZE_MENUS / 3) << "";
	system("pause");
}

void repQty()
{
	cout << setw(SIZE_MENUS / 3) << "" << "You selected Listing By Quantity." << endl;
	cout << setw(SIZE_MENUS / 3) << "";
	system("pause");
}

void repCost()
{
	cout << setw(SIZE_MENUS / 3) << "" << "You selected Listing By Cost." << endl;
	cout << setw(SIZE_MENUS / 3) << "";
	system("pause");
}

void repAge()
{
	cout << setw(SIZE_MENUS / 3) << "" << "You selected Listing By Age." << endl;
	cout << setw(SIZE_MENUS / 3) << "";
	system("pause");
}