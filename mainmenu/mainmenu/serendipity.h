#pragma once

#ifndef H_SERENDIPITY
#define H_SERENDIPITY

#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iostream>		//used for cin, cout
#include <iomanip>		//used for setw, setfill (ch 3)
#include "windows.h"	//windows only, used for cls (clear screen), pause (pause until keystroke)
#include "bookType.h"
#include <ctime>

using namespace std;

const int SIZE_MENUS = 80;
const string TITLE = "Serendipity Booksellers";
const int LEN_TITLE = TITLE.length();
const int DBSIZE = 20;

void cashier(bookType[]);

void invmenu(bookType[]);
int lookUpBook(bookType[]);
void addBook(bookType[]);
void editBook(bookType[]);
void deleteBook(bookType[]);

void reports();
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

#endif H_SERENDIPITY