//---------------------------------------------------------------------------------------
//File name: Serendipity 																-
//Project name:	Serendipity																-
//---------------------------------------------------------------------------------------
//Creator's name and email: Noopur Siroya nsiroya0@ivc.edu								-
//Course-Section: CS 1B Ticket #14700													-
//Creation Date: 6/20/2019																-
//Date of Last Modification: 7/17/2019													-
//---------------------------------------------------------------------------------------
//Purpose: Starting the creation of the Serendipity navigation portion					-
//---------------------------------------------------------------------------------------
//Algorithm:																			-
//Step 1: Create main menu using a do-while loop										-
//Step 2: In the do-while loop, put if-else statements depending on user input			-
//Step 3: If user inputs 1, take user to cashier, and print out cashier module			-
//Step 4: Print out cashier slip after user inputs information							-
//Step 5: If user inputs 2, print out invmenu, and allow user to input numbers			-
//Step 6: User can Look Up Book, Add Book, Edit Book, and Delete Book					-
//Step 7: If user inputs 3, print out reports, and allow user to input numbers			-
//Step 8: If user inputs 4, end program and exit out									-
//---------------------------------------------------------------------------------------
//-									DATA DICTIONARY										-
//-	CONSTANTS																			-
//-																						-
//-	NAME					DATA TYPE				INITIAL VALUE						-
//-	SIZE_MENUS				int						80									-
//-	TITLE					string					"Serendipity Booksellers"			-
//-	LEN_TITLE				int						TITLE.length()						-
//-	DBSIZE					int						20									-
//-																						-
//-	VARIABLES																			-
//-																						-
//-	NAME					DATA TYPE				INITIAL VALUE						-
//-	titleS					string					"Book Information"					-
//-	lenS					int						titleS.length()						-
//-																						-
//-	menuChoice				char					'0'									-
//-	title0					string					"Main Menu"							-
//-	len0					int						title0.length()						-
//-	isbn					string[DBSIZE]			'/0'								-
//-	bookTitle				string[DBSIZE]			'/0'								-
//-	author					string[DBSIZE]			'/0'								-
//-	publisher				string[DBSIZE]			'/0'								-
//-	dateAdded				string[DBSIZE]			'/0'								-
//-	qtyOnHand				int[DBSIZE]				0									-
//-	wholesale				double[DBSIZE]			0									-
//-	retail					double[DBSIZE]			0									-
//-	bookCount				int						0									-
//-																						-
//-	cashierChoice			char					'0'									-
//-	title1					string					"Cashier Module"					-
//-	len1					int						title1.length()						-
//-	date					char					'\0'								-
//-	quantity				int						0									-
//-	isbn					char					'\0'								-
//-	title					string					'\0'								-
//-	price					double					0									-
//-	size13					string					isbn.substr(0, 13)					-
//-	size38					string					isbn.substr(0, 38)					-
//-	subT					double					price * quantity					-
//-	tax						double					subT *  0.06						-
//-	total					double					subT + tax							-
//-																						-
//-	invChoice				char					'0'									-
//-	title2					string					"Inventory Database"				-
//-	len2					int						title2.length()						-
//-																						-
//-	reportsChoice			char					'0'									-
//-	title3					string					"Reports"							-
//-	len3					int						title3.length()						-
//-																						-
//---------------------------------------------------------------------------------------

#include "serendipity.h"
#include "bookType.h"

int main()
{
	
	char menuChoice = '0';
	string title0 = "Main Menu";
	int len0 = title0.length();
	bookType books[DBSIZE];

	do
	{
		system("cls");

		cout << setfill(' ');
		cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
		cout << setw((SIZE_MENUS / 2) + len0 / 2) << right << title0 << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "1. Cashier Module" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "2. Inventory Database Module" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "3. Report Module" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "4. Exit" << endl;
		cout << endl;

		cout << setw(SIZE_MENUS / 3) << "" << "Enter Your Choice: ";
		cin >> menuChoice;
		cin.ignore(100, '\n');
		cout << endl;

		if (menuChoice == '1')
		{
			cashier(books);
		}
		else if (menuChoice == '2')
		{
			invmenu(books);
		}
		else if (menuChoice == '3')
		{
			reports();
		}
		else if (menuChoice == '4')
		{
			break;
		}
		else
		{
			menuChoice = '0';
			cout << setw(SIZE_MENUS / 3) << "" << "Please enter a number in the range 1 - 4. " << endl;
			cout << setw(SIZE_MENUS / 3) << "";
			system("pause");
		}

	} while (menuChoice != '4');
	
}
