#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p) : title(t), author(a), pages(p) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPages() const { return pages; }

    void display() const {
        cout << "Book: " << title << " by " << author << ", Pages: " << pages << endl;
    }
};

class Newspaper {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n, string d, string e) : name(n), date(d), edition(e) {}

    string getName() const { return name; }
    string getDate() const { return date; }
    string getEdition() const { return edition; }

    void display() const {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }
};

class Library {
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addNewspaper(const Newspaper& newspaper) {
        newspapers.push_back(newspaper);
    }

    void sortBooksByPages() {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getPages() < b.getPages();
            });
    }

    void sortNewspapersByEdition() {
        sort(newspapers.begin(), newspapers.end(), [](const Newspaper& a, const Newspaper& b) {
            return a.getEdition() < b.getEdition();
            });
    }

    Book* searchBookByTitle(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(const string& name) {
        for (auto& newspaper : newspapers) {
            if (newspaper.getName() == name) {
                return &newspaper;
            }
        }
        return nullptr;
    }

    void displayCollection() const {
        cout << "Books:\n";
        for (const auto& book : books) {
            book.display();
        }
        cout << "\nNewspapers:\n";
        for (const auto& newspaper : newspapers) {
            newspaper.display();
        }
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}