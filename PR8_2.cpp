#include <iostream>
using namespace std;

struct Book
{
private:
    string title;
    string author;
    int pages;
    static int count;
public:
    Book()
    {
        title = "Невiдома";
        author = "Невiдомий";
        pages = 0;
        count++;
    }
    Book(const string &t, const string &a, int p)
    {
        title = "Невiдома";
        author = "Невiдомий";
        pages = 0;
        setTitle(t);
        setAuthor(a);
        setPages(p);
        count++;
    }
    ~Book()
    {
        count--;
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
    static void printCount()
    {
        cout << "Кiлькiсть об'єктiв Book: " << count << endl;
    }
};
int Book::count = 0;

int main()
{
    Book::printCount();

    {
        Book b1("Гаррi_Поттер", "Роулiнг", 500);
        Book b2("Володар_кiлець", "Толкiн", 200);
        Book::printCount();
        b1.print();
        b2.print();
    }

    Book::printCount();

    return 0;
}