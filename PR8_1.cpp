#include <iostream>
using namespace std;

struct Book
{
private:
    string title;
    string author;
    int pages;
public:
    Book()
    {
        title = "Невiдома назва";
        author = "Невiдомий автор";
        pages = 0;
    }
    Book(const string &t, const string &a, int p)
    {
        setTitle(t);
        setAuthor(a);
        setPages(p);
    }
    void setTitle(const string &t)
    {
        if (!t.empty())
            this->title = t;
    }
    void setAuthor(const string &a)
    {
        if (!a.empty())
            this->author = a;
    }
    void setPages(int p)
    {
        if (p > 0)
            this->pages = p;
    }
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    int getPages() const
    {
        return pages;
    }
    void print() const
    {
        cout << "Книга: " << this->title << ", автор: " << this->author << ", сторiнок: " << this->pages << endl;
    }
};

int main()
{
    string t, a;
    int p;
    cout << "Введiть назву книги: ";
    getline(cin, t);
    cout << "Введiть автора: ";
    getline(cin, a);
    cout << "Введiть кiлькiсть сторiнок: ";
    cin >> p;
    Book b(t, a, p);
    b.print();

    return 0;
}