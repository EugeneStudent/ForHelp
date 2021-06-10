/*#include <iostream>

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
}*/

#include <iostream>
#include <string>
using namespace std;

//#define WAY //пример использования условной компиляции 
#ifndef WAY
class Image
{

public:
	Image()
	{
		counter++;
	}
	static int counter;
	class Pixel
	{
		int r, g, b;
	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}

		string GetInfoPixel()
		{
			return "R= " + to_string(r) + " G= " + to_string(g) + " B= " + to_string(b);
		}
	};
	static const int a = 3;
	int arr[a];
	static int GetID()
	{
		return counter;
	}
private:
	Pixel arr_pixels[5]
	{
		Pixel(43,67,14),
		Pixel(65,87,114),
		Pixel(243,186,17),
		Pixel(203,147,117),
		Pixel(46,88,115)
	};
};
int Image::counter = 0; //статическую переменню класса должны инициализировать сразу
						//за пределами определения класса

const int Max = 5;

void centimize(double* ptrd)
{
	cout << ptrd++ << endl;
	for (int i = 0; i < Max - 1; i++)
		*ptrd++ *= 2.54;
}

void main()
{
	double arr[Max] = { 10.0, 43.1, 95.9, 58.7, 87.3 };
	cout << arr << endl;
	centimize(arr);
	for (int i = 0; i < Max; i++)
		cout << *(arr + i) << "\n";
	//	Image::Pixel pixel(199, 65, 255); //мы можем создать объект класса, который определен
	//	//вложенным в другом классе
	//	cout << pixel.GetInfoPixel() << endl;
	//
	//	cout << Image::counter << endl;//мы можем обращаться к статическим членам класса без объекта

}
#else
class Base // Базовый класс
{
	int x = 100;
public:
	void show() // Обычная функция
	{
		cout << "Base\n";
	}
	int GetX()
	{
		return x;
	}
};
//////////////////////////////////////////////
class Derv1 : public Base // Производный класс 1
{
public:
	void show()
	{
		cout << "Derv1\n";
	}
};
//////////////////////////////////////////////
class Derv2 : public Base // Производный класс 2
{
public:
	void show()
	{
		cout << "Derv2\n";
	}
};
//////////////////////////////////////////////
int main()
{
	Derv1 dv1; // Объект производного класса 1
	Derv2 dv2; // Объект производного класса 2
	Base* ptr; // Указатель на базовый класс
	//Base::GetX();
	ptr = &dv1; // Адрес dv1 занести в указатель
	ptr->show(); // Выполнить show()
	ptr = &dv2; // Адрес dv2 занести в указатель
	ptr->show(); // Выполнить show()
	return 0;
}
#endif





