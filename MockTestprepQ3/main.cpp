// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdio>

using namespace std;

class Fraction {  //NB THIS CLASS IS PROVIDED so not including separate header files
private:
	int num;				// numerator;
	int denom;             // denominator;

public:
	Fraction(int n, int d) : num(n), denom(d) { };

	void print() { cout << num << "/" << denom << endl; };

	friend bool operator>(const Fraction &t1, const Fraction &t2) //friendship demos non member function
	{                                                            //Since we use friendship for non member function
		if (t1.num*t2.denom > t1.denom*t2.num)                  //we need 2 parameters since  there is no implicit object
			return true;
		else
			return false;
	}
	Fraction add(Fraction t, int n)
	{
		t.num = t.num + t.denom*n;
		return t;
	}
	Fraction add(int n, Fraction t)
	{
		t.num = t.num + t.denom*n;
		return t;
	}
};



int main(){

	Fraction f1 = Fraction(1, 2);
	Fraction f2 = Fraction(1, 4);

	Fraction f3 = Fraction(1, 1);

	if (f1 > f2)
	{
		cout << "Fraction f1 is greater than Fraction f2" << endl;
	}
	else
	{
		cout << "Fraction f2 is greater than or equal to Fraction f1" << endl;
	}

	f1.add(f2, 2);
	f1.print();

	f3.add(f1, 3);
	f3.print();

	system("PAUSE");
	return 0;
}

