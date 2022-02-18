#include "Library.h"
#include <iostream>

Library::Library()
{
	numBooks = 0;
	firstBook = nullptr;
	lastBook = nullptr;
}

//Copy constructor
Library::Library(Library& other)
{
	//  implement this function
	numBooks = 0;
	firstBook = nullptr;
	lastBook = nullptr;

	LibraryBook* temp = other.getFirstBook();
	while (temp != nullptr) {
		addBook(temp->book);
		temp = temp->next;
	}
}

int Library::getnumBooks() const
{
	return numBooks;
}

LibraryBook* Library::getFirstBook()
{
	return firstBook;
}

LibraryBook* Library::getLastBook()
{
	return lastBook;
}

//return a pointer to the n'th book in the linked list
LibraryBook* Library::getBook(const int pos)
{
	//implement this function
	LibraryBook* current = firstBook;
	
	int cnt = 0;
	while (current != nullptr) {
		if (cnt == pos) {
			return current;
		}
		else {
			cnt++;
			current = current->next;
		}
	}

	cout << "Book at position " << pos << " not available." << endl;
	return nullptr;
}

//add a Book to the end of the linked list
void Library::addBook(Book book)
{
	//implement this function
	LibraryBook* newBook = new LibraryBook;
	newBook->book = book;
	newBook->next = nullptr;
	if (firstBook == nullptr) {
		firstBook = newBook;
		lastBook = newBook;
	}
	else {
		lastBook->next = newBook;
		newBook->prev = lastBook;
		lastBook = newBook;
	}
	numBooks++;
}

//Move a book to the front of the linked list
void Library::moveToFront(LibraryBook* entry)
{
	//implement this function
	if (entry->next != nullptr) {
		entry->prev->next = entry->next;
		entry->next->prev = entry->prev;
	}
	else {
		entry->prev->next = nullptr;
		lastBook = entry->prev;
	}
	firstBook->prev = entry;
	entry->next = firstBook;
	entry->prev = nullptr;
	firstBook = entry;
}

//print all Books
void Library::printAllBooks() const
{
	//implement this function
	LibraryBook* current = firstBook;
	while (current != nullptr) {
		current->book.printBook();
		current = current->next;
	}
}

//print all Books of a single Genre
void Library::printBooksOfOneGenre(string genre)
{
	//implement this function
	LibraryBook* current = firstBook;
	while (current != nullptr) {
		if (current->book.getGenre() == genre) {
			current->book.printBook();
		}
		current = current->next;
	}
}