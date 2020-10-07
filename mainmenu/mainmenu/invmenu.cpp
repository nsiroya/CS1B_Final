#include "serendipity.h"
#include "bookType.h"

void invmenu(bookType books[])
{
	char invChoice = '0';
	string title2 = "Inventory Database";
	int len2 = title2.length();

	do
	{
		system("cls");

		cout << setfill(' ');
		cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
		cout << setw((SIZE_MENUS / 2) + len2 / 2) << right << title2 << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "1. Look Up a Book" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "2. Add a Book" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "3. Edit a Book's Record" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "4. Delete a Book" << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "5. Return to the Main Menu" << endl;
		cout << endl;
		
		cout << setw(SIZE_MENUS / 3) << "" << "Enter Your Choice: ";
		cin >> invChoice;
		cin.ignore(100, '\n');
		cout << endl;

		if (invChoice == '1')
		{
			lookUpBook(books);
		}
		else if (invChoice == '2')
		{
			if (books[0].getBookCount() < DBSIZE) {
				addBook(books);
			}
			else {
				cout << setw(SIZE_MENUS / 3) << "" << "Error: Not Enough Room. Delete a Book to continue." << endl;
				cout << setw(SIZE_MENUS / 3) << "";
				system("pause");
			}
		}
		else if (invChoice == '3')
		{
			if (books[0].getBookCount() < 1)
			{
				cout << setw(SIZE_MENUS / 3) << "" << "No book in system. Please add a book first." << endl;
				cout << setw(SIZE_MENUS / 3) << "";
				system("pause");
				cout << endl;
			}
			else {
				editBook(books);
			}
		}
		else if (invChoice == '4')
		{
			if (books[0].getBookCount() < 1)
			{
				cout << setw(SIZE_MENUS / 3) << "" << "No book in system. Please add a book first." << endl;
				cout << setw(SIZE_MENUS / 3) << "";
				system("pause");
				cout << endl;
			}
			else {
				deleteBook(books);
			}
		}
		else if (invChoice == '5')
		{
			break;
		}
		else
		{
			invChoice = '0';
			cout << setw(SIZE_MENUS / 3) << "" << "Please enter a number in the range 1 - 5. " << endl;
			cout << setw(SIZE_MENUS / 3) << "";
			system("pause");
		}

	} while (invChoice != '5');
}

int lookUpBook(bookType books[])
{
	int index = 0;
	string sub1 = "";
	string sub2 = "";
	string temp1 = "";
	string temp2 = "";
	string temp3 = "";
	char ans = '\0';

	cout << setw(SIZE_MENUS / 3) << "" << "Book Lookup" << endl;
	cout << setw(SIZE_MENUS / 3) << "" << "Search: ";
	cin.ignore();
	getline(cin, sub1);
	cout << endl;

	for (int i = 0; i < sub1.length(); i++)
	{
		sub2 += tolower(sub1[i]);
	}

	do {
		while (index < books[0].getBookCount())
		{
			temp1 = "";
			temp2 = "";
			temp3 = "";

			for (int j = 0; j < books[index].getTitle().length(); j++)
			{
				temp1 += tolower(books[index].getTitle()[j]);
			}
			for (int j = 0; j < books[index].getAuthor().length(); j++)
			{
				temp2 += tolower(books[index].getAuthor()[j]);
			}
			for (int j = 0; j < books[index].getPub().length(); j++)
			{
				temp3 += tolower(books[index].getPub()[j]);
			}
			
			if (temp1.find(sub2) != -1)
			{
				break;
			}
			else if (temp2.find(sub2) != -1)
			{
				break;
			}
			else if (temp3.find(sub2) != -1)
			{
				break;
			}
			else if (books[index].getISBN().find(sub1) != -1)
			{
				break;
			}
			index++;
		}

		if (index == 20)
		{
			index = -1;
			cout << setw(SIZE_MENUS / 3) << "" << "The book is not in the inventory." << endl;
			cout << setw(SIZE_MENUS / 3) << "";
			system("pause");
			break;
		}

		cout << setw(SIZE_MENUS / 3) << "" << "Result: " << books[index].getTitle() << endl;
		cout << setw(SIZE_MENUS / 3) << "" << "View this book record? (Y/N): ";
		cin >> ans;
		cin.ignore(100, '\n');
		cout << endl;

		if (ans == 'Y' || ans == 'y')
		{
			system("cls");
			books[index].print();
			break;
		}
		else if (ans == 'N' || ans == 'n')
		{
			index++;
		}
		else {
			cout << setw(SIZE_MENUS / 3) << "" << "Please enter Y or N." << endl;
			cout << setw(SIZE_MENUS / 3) << "" << "View this book record? (Y/N): ";
			cin >> ans;
			cin.ignore(100, '\n');
			cout << endl;
		}
	} while (index != -1);

	return index;
}

void addBook(bookType books[])
{
	string title = "Add Book";
	int len = title.length();
	char choice = '\0';
	int bookCount = books[0].getBookCount();

	do {
		string t = "";
		string isbn = "";
		string author = "";
		string pub = "";
		string date = "";
		int qty = 0;
		double whole = 0;
		double retail = 0;

		system("cls");
		cout << setfill(' ');
		cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
		cout << setw((SIZE_MENUS / 2) + len / 2) << right << title << endl;
		cout << endl;

		cout << setw(SIZE_MENUS / 3) << "" << "Database Size: " << DBSIZE << "		Current Book Count: " << bookCount << endl;
		cout << endl;

		cout.precision(2);
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<1> Enter Book Title" << setw(SIZE_MENUS / 5) << right << "> " << books[bookCount].getTitle().substr(0, 30) << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<2> Enter ISBN" << setw(SIZE_MENUS / 5) << right << "> " << books[bookCount].getISBN().substr(0, 13) << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<3> Enter Author" << setw(SIZE_MENUS / 5) << right << "> " << books[bookCount].getAuthor().substr(0, 30) << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<4> Enter Publisher" << setw(SIZE_MENUS / 5) << right << "> " << books[bookCount].getPub().substr(0, 30) << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<5> Enter Date Added (MM/DD/YYYY)" << setw(SIZE_MENUS / 5) << right << "> " << books[bookCount].getDateAdded().substr(0, 10) << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<6> Enter Quantity On Hand" << setw(SIZE_MENUS / 5) << right << "> " << books[bookCount].getQtyOnHand() << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<7> Enter Wholesale Cost" << setw(SIZE_MENUS / 5) << right << "> " << "$" << fixed << books[bookCount].getWholesale() << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<8> Enter Retail Price" << setw(SIZE_MENUS / 5) << right << "> " << "$" << fixed << books[bookCount].getRetail() << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<9> Save Book to Database" << endl;
		cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<0> Return to Inventory Menu" << endl;
		cout << endl;
		cout << setw(SIZE_MENUS / 6) << "" << "Choice (0-9): ";
		cin >> choice;
		cin.ignore(100, '\n');
		cout << endl;

		if (choice == '1')
		{
			cout << setw(SIZE_MENUS / 6) << "" << "Book Title: ";
			getline(cin, t);
			books[bookCount].setTitle(t);
		}
		else if (choice == '2')
		{
			cout << setw(SIZE_MENUS / 6) << "" << "ISBN: ";
			cin >> isbn;
			books[bookCount].setISBN(isbn);
		}
		else if (choice == '3')
		{
			cout << setw(SIZE_MENUS / 6) << "" << "Author: ";
			getline(cin, author);
			books[bookCount].setAuthor(author);
		}
		else if (choice == '4')
		{
			cout << setw(SIZE_MENUS / 6) << "" << "Publisher: ";
			getline(cin, pub);
			books[bookCount].setPub(pub);
		}
		else if (choice == '5')
		{
			cout << setw(SIZE_MENUS / 6) << "" << "Date Added: ";
			cin >> date;
			books[bookCount].setDateAdded(date);
		}
		else if (choice == '6')
		{
			cout << setw(SIZE_MENUS / 6) << "" << "Quantity on Hand: ";
			cin >> qty;
			cout << endl;
			while (cin.fail()) {
				cout << setw(SIZE_MENUS / 6) << "" << "Please enter a number." << endl;
				cout << setw(SIZE_MENUS / 6) << "";
				system("pause");
				cout << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << setw(SIZE_MENUS / 6) << "" << "Quantity on Hand: ";
				cin >> qty;
				cout << endl;
			}
			books[bookCount].setQtyOnHand(qty);
		}
		else if (choice == '7')
		{
			cout << setw(SIZE_MENUS / 6) << "" << "Wholesale Price: ";
			cin >> whole;
			cout << endl;
			while (cin.fail()) {
				cout << setw(SIZE_MENUS / 6) << "" << "Please enter a number." << endl;
				cout << setw(SIZE_MENUS / 6) << "";
				system("pause");
				cout << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << setw(SIZE_MENUS / 6) << "" << "Wholesale Price: " ;
				cin >> whole;
				cout << endl;
			}
			books[bookCount].setWholesale(whole);
		}
		else if (choice == '8')
		{
			cout << setw(SIZE_MENUS / 6) << "" << "Retail Price: ";
			cin >> retail;
			cout << endl;
			while (cin.fail()) {
				cout << setw(SIZE_MENUS / 6) << "" << "Please enter a number." << endl;
				cout << setw(SIZE_MENUS / 6) << "";
				system("pause");
				cout << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << setw(SIZE_MENUS / 6) << "" << "Retail Price: ";
				cin >> retail;
				cout << endl;
			}
			books[bookCount].setRetail(retail);
		}
		else if (choice == '9')
		{
			books[0].incBookCount();
			bookCount = books[0].getBookCount();
			if (bookCount > 19)
			{
				break;
			}
		}
		else if (choice == '0')
		{
			books[bookCount].setTitle("EMPTY");
			books[bookCount].setISBN("EMPTY");
			books[bookCount].setAuthor("EMPTY");
			books[bookCount].setPub("EMPTY");
			books[bookCount].setDateAdded("EMPTY");
			books[bookCount].setQtyOnHand(0);
			books[bookCount].setWholesale(0);
			books[bookCount].setRetail(0);
			break;
		}
		else
		{
			choice = '\0';
			cout << setw(SIZE_MENUS / 6) << "" << "Please enter a number in the range 0 - 9. " << endl;
			cout << setw(SIZE_MENUS / 6) << "";
			system("pause");
		}
	} while (choice != '0' || bookCount < DBSIZE);
}

void editBook(bookType books[])
{
	char choice = '\0';
	char ans = '\0';
	string title = "Edit Book";
	int len = title.length();
	int index;
	int bookCount = books[0].getBookCount();

	string t = "";
	string isbn = "";
	string author = "";
	string pub = "";
	string date = "";
	int qty = 0;
	double whole = 0;
	double retail = 0;

	system("cls");
	cout << setfill(' ');
	cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
	cout << setw((SIZE_MENUS / 2) + len / 2) << right << title << endl;
	cout << endl;

	cout << setw(SIZE_MENUS / 3) << "" << "Database Size: " << DBSIZE << "		Current Book Count: " << bookCount << endl;
	cout << endl;

	index = lookUpBook(books);

	if (index != -1)
	{
		cout << setfill(' ');
		cout << setw(SIZE_MENUS / 4) << "" << "Is this the book you would like to edit? (Y/N): ";
		cin >> ans;
		cin.ignore(100, '\n');
		cout << endl;
		while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
		{
			cout << setw(SIZE_MENUS / 4) << "" << "Please enter Y or N." << endl;
			cout << setw(SIZE_MENUS / 4) << "" << "Is this the book you would like to edit? (Y/N): ";
			cin >> ans;
			cin.ignore(100, '\n');
			cout << endl;
		}
			
		if (ans == 'Y' || ans == 'y')
		{
			do {
				system("cls");
				cout << setfill(' ');
				cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
				cout << setw((SIZE_MENUS / 2) + len / 2) << right << title << endl;
				cout << endl;

				cout << setw(SIZE_MENUS / 3) << "" << "Database Size: " << DBSIZE << "		Current Book Count: " << bookCount << endl;
				cout << endl;

				cout.precision(2);
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<1> Enter Book Title" << setw(SIZE_MENUS / 5) << right << "> " << books[index].getTitle().substr(0, 30) << endl;
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<2> Enter ISBN" << setw(SIZE_MENUS / 5) << right << "> " << books[index].getISBN().substr(0, 13) << endl;
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<3> Enter Author" << setw(SIZE_MENUS / 5) << right << "> " << books[index].getAuthor().substr(0, 30) << endl;
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<4> Enter Publisher" << setw(SIZE_MENUS / 5) << right << "> " << books[index].getPub().substr(0, 30) << endl;
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<5> Enter Date Added (MM/DD/YYYY)" << setw(SIZE_MENUS / 5) << right << "> " << books[index].getDateAdded().substr(0, 10) << endl;
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<6> Enter Quantity On Hand" << setw(SIZE_MENUS / 5) << right << "> " << books[index].getQtyOnHand() << endl;
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<7> Enter Wholesale Cost" << setw(SIZE_MENUS / 5) << right << "> " << "$" << fixed << books[index].getWholesale() << endl;
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<8> Enter Retail Price" << setw(SIZE_MENUS / 5) << right << "> " << "$" << fixed << books[index].getRetail() << endl;
				cout << setw(SIZE_MENUS / 6) << "" << setw(SIZE_MENUS / 2) << left << "<9> Return to Inventory Menu" << endl;
				cout << endl;
				cout << setw(SIZE_MENUS / 6) << "" << "Choice (1-9): ";
				cin >> choice;
				cin.ignore(100, '\n');
				cout << endl;

				if (choice == '1')
				{
					cout << setw(SIZE_MENUS / 6) << "" << "Book Title: ";
					getline(cin, t);
					books[index].setTitle(t);
				}
				else if (choice == '2')
				{
					cout << setw(SIZE_MENUS / 6) << "" << "ISBN: ";
					cin >> isbn;
					books[index].setISBN(isbn);
				}
				else if (choice == '3')
				{
					cout << setw(SIZE_MENUS / 6) << "" << "Author: ";
					getline(cin, author);
					books[index].setAuthor(author);
				}
				else if (choice == '4')
				{
					cout << setw(SIZE_MENUS / 6) << "" << "Publisher: ";
					getline(cin, pub);
					books[index].setPub(pub);
				}
				else if (choice == '5')
				{
					cout << setw(SIZE_MENUS / 6) << "" << "Date Added: ";
					cin >> date;
					books[index].setDateAdded(date);
				}
				else if (choice == '6')
				{
					cout << setw(SIZE_MENUS / 6) << "" << "Quantity on Hand: ";
					cin >> qty;
					cout << endl;
					while (cin.fail()) {
						cout << setw(SIZE_MENUS / 6) << "" << "Please enter a number." << endl;
						cout << setw(SIZE_MENUS / 6) << "";
						system("pause");
						cout << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cout << setw(SIZE_MENUS / 6) << "" << "Quantity on Hand: ";
						cin >> qty;
						cout << endl;
					}
					books[index].setQtyOnHand(qty);
				}
				else if (choice == '7')
				{
					cout << setw(SIZE_MENUS / 6) << "" << "Wholesale Price: ";
					cin >> whole;
					cout << endl;
					while (cin.fail()) {
						cout << setw(SIZE_MENUS / 6) << "" << "Please enter a number." << endl;
						cout << setw(SIZE_MENUS / 6) << "";
						system("pause");
						cout << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cout << setw(SIZE_MENUS / 6) << "" << "Wholesale Price: ";
						cin >> whole;
						cout << endl;
					}
					books[index].setWholesale(whole);
				}
				else if (choice == '8')
				{
					cout << setw(SIZE_MENUS / 6) << "" << "Retail Price: ";
					cin >> retail;
					cout << endl;
					while (cin.fail()) {
						cout << setw(SIZE_MENUS / 6) << "" << "Please enter a number." << endl;
						cout << setw(SIZE_MENUS / 6) << "";
						system("pause");
						cout << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cout << setw(SIZE_MENUS / 6) << "" << "Retail Price: ";
						cin >> retail;
						cout << endl;
					}
					books[index].setRetail(retail);
				}
				else if (choice == '9')
				{
					break;
				}
				else
				{
					choice = '\0';
					cout << setw(SIZE_MENUS / 6) << "" <<  "Please enter a number in the range 1 - 9. " << endl;
					cout << setw(SIZE_MENUS / 6) << "";
					system("pause");
				}
			} while (choice != '9');
		}
	}
}

void deleteBook(bookType books[])
{
	char choice = '\0';
	char ans = '\0';
	string title = "Delete Book";
	int len = title.length();
	int index;
	int bookCount = books[0].getBookCount();

	do {
		system("cls");
		cout << setfill(' ');
		cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
		cout << setw((SIZE_MENUS / 2) + len / 2) << right << title << endl;
		cout << endl;

		cout << setw(SIZE_MENUS / 3) << "" << "Database Size: " << DBSIZE << "		Current Book Count: " << bookCount << endl;
		cout << endl;

		index = lookUpBook(books);

		if (index != -1)
		{
			cout << setfill(' ');
			cout << setw(SIZE_MENUS / 4) << "" << "Is this the book you would like to delete? (Y/N): ";
			cin >> ans;
			cin.ignore(100, '\n');
			cout << endl;
			while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
			{
				cout << setw(SIZE_MENUS / 4) << "" << "Please enter Y or N." << endl;
				cout << setw(SIZE_MENUS / 4) << "" << "Is this the book you would like to delete? (Y/N): ";
				cin >> ans;
				cin.ignore(100, '\n');
				cout << endl;
			}

			if (ans == 'Y' || ans == 'y')
			{
				for (int i = index; i < bookCount-1; i++)
				{
					books[i].setISBN(books[i + 1].getISBN());
					books[i].setTitle(books[i + 1].getTitle());
					books[i].setAuthor(books[i + 1].getAuthor());
					books[i].setPub(books[i + 1].getPub());
					books[i].setDateAdded(books[i + 1].getDateAdded());
					books[i].setQtyOnHand(books[i + 1].getQtyOnHand());
					books[i].setWholesale(books[i + 1].getWholesale());
					books[i].setRetail(books[i + 1].getRetail());
				}
				books[0].decBookCount();
				bookCount = books[0].getBookCount();
				
				cout << setw(SIZE_MENUS / 4) << "" << "Book Deleted." << endl;
				cout << setw(SIZE_MENUS / 4) << "";
				system("pause");
				cout << endl;
				
				cout << setw(SIZE_MENUS / 4) << "" << "Would you like to delete another book? (Y/N): ";
				cin >> ans;
				cin.ignore(100, '\n');
				cout << endl;

				if (ans == 'Y' || ans == 'y')
				{
					cout << endl;
				}
				if (ans == 'N' || ans == 'n')
				{
					break;
				}
				else {
					cout << setw(SIZE_MENUS / 3) << "" << "Please enter Y or N." << endl;
					cout << setw(SIZE_MENUS / 3) << "" << "Would you like to delete another book? (Y/N): ";
					cin >> ans;
					cin.ignore(100, '\n');
					cout << endl;
				}
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	} while (choice != 'n' && choice != 'N');
}