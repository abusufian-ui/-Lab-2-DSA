#include<iostream>

using namespace std;

class Shape
{
public:
	virtual void const area() = 0;
};

class Circle : public Shape
{
private:
	double radius;
	const float PI = 3.1416;

public:
	Circle(double r) : radius(r) {}
	void const area() override {
		cout << "Total Area = " << radius * PI << endl;
	}
};

class Rectangle : public Shape
{
private:
	double length;
    double width;
	
public:
	Rectangle(double l,double w) : length(l), width(w) {}
	void const area() override {
		cout << "Total Area = " << length * width << endl;
	}
};

int main()
{
	Circle C1(45);
	C1.area();
	Rectangle R1(34,45);
	R1.area();

	return 0;
}