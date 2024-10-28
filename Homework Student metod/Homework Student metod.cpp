#include <iostream>
#include <Windows.h>
using namespace std;

class Student
{
	char* name;
	int age;
public:
	Student();                             
	Student(const char*, int);             
	Student(const Student&);               
	Student& operator=(const Student&);   
	void Output();
	~Student();                          
};

Student::Student()
{
	name = nullptr;
	age = 0;
}

Student::Student(const char* Name, int Age)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	age = Age;
}

Student::Student(const Student& other)
{
	if (other.name != nullptr)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
	}
	else
	{
		name = nullptr;
	}
	age = other.age;
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		delete[] name;

		if (other.name != nullptr)
		{
			name = new char[strlen(other.name) + 1];
			strcpy_s(name, strlen(other.name) + 1, other.name);
		}
		else
		{
			name = nullptr;
		}
		age = other.age;
	}
	return *this;
}

void Student::Output()
{
	cout << "Name: " << name << endl
		<< "Age: " << age << endl << endl;
}

Student::~Student()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	cout << "Destruct\n";
}

int main()
{
	Student obj1("Oleg", 21);
	obj1.Output();

	Student mas[2]{ {"Alena",20 }, {"Maksim", 22} };
	for (int i = 0; i < 2; i++)
	{
		mas[i].Output();
	}

	Student obj2 = obj1;
	obj2.Output();

	Student obj3;
	obj3 = mas[0];
	obj3.Output();

	system("pause");
}
