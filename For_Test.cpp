#include <iostream>

class A
{
public:

	virtual const char* getName() const { return "A"; }
};

class B : public A
{
public:

	 const char* getName() const { return "B"; }
};

class C : public B
{
public:
	 const char* getName() const { return "C"; }
};

class D : public C
{
public:
	 const char* getName() const { return "D-const"; }
};
//==============================================================//
class Zero
{
	double sum;
public:
	Zero(double sum) { (*this).sum = sum; }
	double GetSum() { return sum; }
};

class Second;

class First
{
	const int p_a;
public:
	First(int private_a) : p_a{ private_a * 2 } 
	{

	}

	const double& foo(Second other_class);
};

class Second : private First
{
	double& p_b;
	double p_c;
public:
	Second(double private_b) : p_b(private_b), First(private_b)
	{
		//p_c = pow(sqrt(p_b),3);
		p_c = 7;
	}
	friend const double& First::foo(Second other_class);
};



int main()
{
	Second second(2);
	First first(5);
	Zero zero(first.foo(second));
	std::cout << zero.GetSum();
	

	return 0;
}

const double& First::foo(Second other_class)
{
	return p_a + other_class.p_b + other_class.p_c;
}
