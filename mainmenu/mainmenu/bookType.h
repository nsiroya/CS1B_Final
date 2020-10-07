#pragma once

#ifndef H_BOOKTYPE
#define H_BOOKTYPE

#include "serendipity.h"

using namespace std;

class bookType {
private:
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qtyOnHand;
	float wholesale;
	float retail;
	static int bookCount;
public:
	void setTitle(string);
	void setISBN(string);
	void setAuthor(string);
	void setPub(string);
	void setDateAdded(string);
	void setQtyOnHand(int);
	void setWholesale(float);
	void setRetail(float);
	static void incBookCount();
	static void decBookCount();

	string getTitle() const;
	string getISBN() const;
	string getAuthor() const;
	string getPub() const;
	string getDateAdded() const;
	int getQtyOnHand() const;
	float getWholesale() const;
	float getRetail() const;
	int getBookCount() const;

	void print();
	bool equals(bookType);
	bookType();
	bookType(string, string, string, string, string, int, float, float);
};

#endif H_BOOKTYPE