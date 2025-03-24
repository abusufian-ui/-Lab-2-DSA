#include<iostream>

using namespace std;

class Employee
{
public:
	virtual void const calSalary() = 0;

};

class fullTime : public Employee
{
private:
	double noHours;
	const double priceHour = 350;

public:
	Circle(double h) : noHours(h) {}
	void const calSalary() override {
		cout << "Total Salary = " << noHours * priceHour << endl;
	}
};

class partTime : public Employee
{
private:
	double noHours;
	const double priceHour = 350;

public:
	Rectangle(double h) : noHours(h) {}
	void const calSalary() override {
		cout << "Total Salary = " << noHours * priceHour << endl;
	}
};

int main()
{
	fullTime F1(45);
	F1.area();
	partTime P1(34);
	P1.area();

	return 0;
}
