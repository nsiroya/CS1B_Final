#include "serendipity.h"
#include "bookType.h"

int bookType::bookCount = 0;

bookType::bookType() {
	bookTitle = "EMPTY";
	isbn = "EMPTY";
	author = "EMPTY";
	publisher = "EMPTY";
	dateAdded = "EMPTY";
	qtyOnHand = 0;
	wholesale = 0;
	retail = 0;
}

bookType::bookType(string t, string i, string a, string p, string d, int q, float w, float r) {
	bookTitle = t;
	isbn = i;
	author = a;
	publisher = p;
	dateAdded = d;
	qtyOnHand = q;
	wholesale = w;
	retail = r;
}

void bookType::setTitle(string t) {
	bookTitle = t;
}

void bookType::setISBN(string i) {
	isbn = i;
}

void bookType::setAuthor(string a) {
	author = a;
}

void bookType::setPub(string p) {
	publisher = p;
}

void bookType::setDateAdded(string d) {
	dateAdded = d;
}

void bookType::setQtyOnHand(int q) {
	qtyOnHand = q;
}

void bookType::setWholesale(float w) {
	wholesale = w;
}

void bookType::setRetail(float r) {
	retail = r;
}

void bookType::incBookCount() {
	bookCount++;
}

void bookType::decBookCount() {
	bookCount--;
}

string bookType::getTitle() const {
	return bookTitle;
}

string bookType::getISBN() const {
	return isbn;
}

string bookType::getAuthor() const {
	return author;
}

string bookType::getPub() const {
	return publisher;
}

string bookType::getDateAdded() const {
	return dateAdded;
}

int bookType::getQtyOnHand() const {
	return qtyOnHand;
}

float bookType::getWholesale() const {
	return wholesale;
}

float bookType::getRetail() const {
	return retail;
}

int bookType::getBookCount() const {
	return bookCount;
}

void bookType::print() {
	string titleS = "Book Information";
	int lenS = titleS.length();

	system("cls");

	cout.precision(2);
	cout << setfill(' ');
	cout << setw((SIZE_MENUS / 2) + LEN_TITLE / 2) << right << TITLE << endl;
	cout << setw((SIZE_MENUS / 2) + lenS / 2) << right << titleS << endl;
	cout << endl;
	cout << setw(SIZE_MENUS / 4) << "" << "ISBN: " << getISBN().substr(0, 13) << endl;
	cout << setw(SIZE_MENUS / 4) << "" << "Title: " << getTitle().substr(0, 40) << endl;
	cout << setw(SIZE_MENUS / 4) << "" << "Author: " << getAuthor().substr(0, 40) << endl;
	cout << setw(SIZE_MENUS / 4) << "" << "Publisher: " << getPub().substr(0, 40) << endl;
	cout << setw(SIZE_MENUS / 4) << "" << "Date Added: " << getDateAdded().substr(0, 10) << endl;
	cout << setw(SIZE_MENUS / 4) << "" << "Quantity-On-Hand: " << getQtyOnHand() << endl;
	cout << setw(SIZE_MENUS / 4) << "" << "Wholesale Cost: $" << fixed << getWholesale() << endl;
	cout << setw(SIZE_MENUS / 4) << "" << "Retail Price: $" << fixed << getRetail() << endl;
	cout << setw(SIZE_MENUS / 4) << "";
	cout << endl;

	cout << setw(SIZE_MENUS / 4) << "";
	system("pause");
}

bool bookType::equals(bookType book) {
	bool result = false;
	if (getTitle().compare(book.getTitle()) == 0)
		if (getISBN().compare(book.getISBN()) == 0)
			if (getAuthor().compare(book.getAuthor()) == 0)
				if (getPub().compare(book.getPub()) == 0)
					if (getDateAdded().compare(book.getDateAdded()) == 0)
						if (getQtyOnHand() == book.getQtyOnHand())
							if (getWholesale() == book.getWholesale())
								if (getRetail() == book.getRetail())
									result = true;
	return true;
}