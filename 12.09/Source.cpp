#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book(const char* n);
	Book(const char* n, int p);
	void Print();
	~Book();
};
Book::Book(const char* n)
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Book::Book(const char* n, int p) :Book(n)
{
	pages = p;
}
void Book::Print()
{
	cout << "Книга: " << name << endl;
	cout << "Страницы: " << pages << endl;
}
Book::~Book()
{
	delete[] name;
}
class Student
{
	char* name;
	const double step;
	Book book;
public:
	Student();
	Student(const char* n, double st, const char* bookName, int bookPages);
	~Student();
	void Print();

};
Student::Student() :step(0), book(nullptr, 0)
{
	name = nullptr;
}
Student::Student(const char* n, double st, const char* bookName, int bookPages) : step(st), book(bookName, bookPages)
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Student::~Student()
{
	delete[]name;
}
void Student::Print()
{
	cout << "Студент: " << name << endl << "Шаг: " << step << endl;
	book.Print();
}
int main()
{
	setlocale(0, "ru");
	Book VRI("Граф Монте-Кристо", 1216);
	Student U("Graf", 666, "Граф Монте-Кристо", 1216);
	U.Print();
}