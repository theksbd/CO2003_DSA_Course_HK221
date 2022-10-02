#include <iostream>
#include <string.h>

using namespace std;

class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and nullptr pointer
         */
        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
    }

    Book(const char *title, const char *authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        this->title = new char[strlen(book.title) + 1];
        strcpy(this->title, book.title);
        this->authors = new char[strlen(book.authors) + 1];
        strcpy(this->authors, book.authors);
        this->publishingYear = book.publishingYear;
    }

    void setTitle(const char *title)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    void setAuthors(const char *authors)
    {
        /*
         * STUDENT ANSWER
         */
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->publishingYear = publishingYear;
    }

    char *getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->title;
    }

    char *getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete[] this->title;
        delete[] this->authors;
    }

    void printBook()
    {
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }

    friend bool checkAuthor(Book book, const char *author)
    {
        /*
         * STUDENT ANSWER
         * TODO: returns true if the author is on the book's authors list, otherwise it returns false
         */
        if (book.authors != nullptr)
        {
            char *token = strtok(book.authors, ",");
            while (token != nullptr)
            {
                if (strcmp(token, author) == 0)
                    return true;
                token = strtok(nullptr, ",");
            }
        }
        return false;
    }

    friend class Printer;
};

class Printer
{
public:
    static void printBook(const Book book)
    {
        /*
         * STUDENT ANSWER
         */
        cout << book.title << endl;
        char *token = strtok(book.authors, ",");
        while (token != nullptr)
        {
            cout << (token[0] == ' ' ? token + 1 : token) << endl;
            token = strtok(nullptr, ",");
        }
        cout << book.publishingYear;
    }
};

int main()
{

    Book book1("Giai tich 1", "Le Nguyen Dinh Huy, Nguyen Thi Xuan Anh", 2000);
    Printer::printBook(book1);
    return 0;
}