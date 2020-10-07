#include "serendipity.h"
#include "bookType.h"

void cashier(bookType books[])
{
	string title1 = "Cashier Module";
	int len1 = title1.length();
	char cashierChoice = '0';

	int quantity = 0;
	char buy = '0';
	string bookName[DBSIZE] = {};
	int bookNum[DBSIZE] = { 0 };
	int c1 = 0;
	int c2 = 0;
	int index = -1;

	int idex = 0;

	double subT = 0;
	double tax = 0;
	double total = 0;

	do {
		system("cls");

		cout << setfill(' ');
		cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
		cout << setw((SIZE_MENUS / 2) + len1 / 2) << right << title1 << endl;
		cout << endl;

		do {
			index = lookUpBook(books);

			if (index != -1)
			{
				system("cls");
				cout << setfill(' ');
				cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
				cout << setw((SIZE_MENUS / 2) + len1 / 2) << right << title1 << endl;
				cout << endl;

				for (int i = 0; i < DBSIZE; i++)
				{
					if (books[index].getTitle().compare(bookName[i]) == 0)
					{
						c2 = i;
						break;
					}
					else {
						c2 = c1;
					}
				}

				if (c2 == c1)
					c1++;

				bookName[c2] = books[index].getTitle();

				do
				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << setw(SIZE_MENUS / 3) << "" << "Quantity of Book (There are " << books[index].getQtyOnHand() << " available): ";
					cin >> quantity;
					cout << endl;
					if (cin.fail())
					{
						cout << setw(SIZE_MENUS / 3) << "" << "Please enter a number." << endl;
						cout << setw(SIZE_MENUS / 3) << "";
						system("pause");
						cout << endl;
					}
					if (quantity > books[index].getQtyOnHand())
					{
						cout << setw(SIZE_MENUS / 3) << "" << "Please enter a number less than " << books[index].getQtyOnHand() << "." << endl;
						cout << setw(SIZE_MENUS / 3) << "";
						system("pause");
						cout << endl;
					}
				} while (quantity > books[index].getQtyOnHand() || cin.fail());
				bookNum[c2] = quantity + bookNum[c2];
				books[index].setQtyOnHand(books[index].getQtyOnHand() - quantity);

				cout << setw(SIZE_MENUS / 3) << "" << "Purchase Request: " << quantity << " " << bookName[c2] << endl;

				cout << setw(SIZE_MENUS / 3) << "" << "Would you like to add another book to this purchase? (Y/N): ";
				cin >> buy;
				cin.ignore(100, '\n');
				cout << endl;

				while (buy != 'Y' && buy != 'y' && buy != 'N' && buy != 'n')
				{
					cout << setw(SIZE_MENUS / 3) << "" << "Please enter either Y or N." << endl;
					cout << setw(SIZE_MENUS / 3) << "";
					system("pause");
					system("cls");
					cout << setw(SIZE_MENUS / 3) << "" << "Would you like to add another book to this purchase? (Y/N): ";
					cin >> cashierChoice;
					cin.ignore(100, '\n');
					cout << endl;
				}
			}
		} while (buy != 'n' && buy != 'N');

		cout << setw(SIZE_MENUS / 3) << "" << "Confirm Purchase (Y/N): ";
		cin >> cashierChoice;
		cin.ignore(100, '\n');
		cout << endl;

		while (cashierChoice != 'Y' && cashierChoice != 'y' && cashierChoice != 'N' && cashierChoice != 'n')
		{
			cout << setw(SIZE_MENUS / 3) << "" << "Please enter either Y or N." << endl;
			cout << setw(SIZE_MENUS / 3) << "";
			system("pause");
			system("cls");
			cout << setw(SIZE_MENUS / 3) << "" << "Confirm Purchase (Y/N): ";
			cin >> cashierChoice;
			cin.ignore(100, '\n');
			cout << endl;
		}
		if (cashierChoice == 'n' || cashierChoice == 'N')
			break;

		if (index != -1)
		{
			system("cls");

			time_t now = time(0);
			char* dt = ctime(&now);

			cout << TITLE << endl;
			cout << endl;
			cout << "Date: " << dt << endl;
			cout << endl;

			cout << setw(5) << left << "Qty";
			cout << setw(15) << left << "ISBN";
			cout << setw(40) << left << "Title";
			cout << setw(10) << left << "Price";
			cout << setw(10) << left << "Total" << endl;
			cout << endl;

			cout << setfill('-');
			cout << setw(SIZE_MENUS) << "";
			cout << endl;

			for (int i = 0; i < DBSIZE; i++)
			{
				for (int j = 0; j < books[0].getBookCount(); j++)
				{
					if (books[j].getTitle().compare(bookName[i]) == 0)
					{
						idex = j;
						cout << setfill(' ');
						cout << setw(5) << left << bookNum[i];
						cout << setw(15) << left << books[idex].getISBN().substr(0, 13);;
						cout << setw(40) << left << books[idex].getTitle().substr(0, 38);;
						cout.precision(2);
						cout << setw(5) << right << "$ " << setw(5) << right << fixed << books[idex].getRetail();
						cout << setw(5) << right << "$ " << setw(5) << right << fixed << (bookNum[i] * books[idex].getRetail()) << endl;
						cout << endl;

						subT = subT + (books[idex].getRetail() * bookNum[i]);
					}
				}
			}

			tax = subT * 0.06;
			total = subT + tax;

			cout << endl;
			cout << setw(30) << right << "Subtotal";
			cout << setw(40) << "";
			cout << setw(5) << right << "$ " << setw(5) << right << fixed << subT << endl;

			cout << setw(30) << right << "Tax";
			cout << setw(40) << "";
			cout << setw(5) << right << "$ " << setw(5) << right << fixed << tax << endl;

			cout << setw(30) << right << "Total";
			cout << setw(40) << "";
			cout << setw(5) << right << "$ " << setw(5) << right << fixed << total << endl;
			cout << endl;

			cout << "Thank You for Shopping at Serendipity!" << endl;
			cout << endl;

			system("pause");
		}

		system("cls");
		cout << "Do you wish to complete another transaction? (Y/N): ";
		cin >> cashierChoice;
		cin.ignore(100, '\n');
		cout << endl;

		while (cashierChoice != 'Y' && cashierChoice != 'y' && cashierChoice != 'N' && cashierChoice != 'n')
		{
			cout << "Please enter either Y or N." << endl;
			system("pause");
			system("cls");
			cout << "Do you wish to complete another transaction? (Y/N): ";
			cin >> cashierChoice;
			cin.ignore(100, '\n');
			cout << endl;
		}

	} while (cashierChoice != 'N' && cashierChoice != 'n');



}