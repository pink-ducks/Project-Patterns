#include "pch.h"
#include<iostream>
#include<string>

using namespace std;

class IColor // IMPLEMENTATION INTERFACE
{
public:
	virtual string Color() = 0;
};

class RedColor : public IColor // IMPLEMENTATION
{
public:
	string Color()
	{
		return "of Red Color";
	}
};

class BlueColor : public IColor // IMPLEMENTATION
{
public:
	string Color()
	{
		return "of Blue Color";
	}
};

class ICarModel // LOGIC INTERFACE
{
public:
	virtual string WhatIsMyType() = 0;
};

class Model_A : public ICarModel // LOGIC A
{
	IColor* _myColor; // implementation
public:
	Model_A(IColor *obj) :_myColor(obj) {}
	string WhatIsMyType()
	{
		return "I am a Model_A " + _myColor->Color();
	}
};

class Model_B : public ICarModel // LOGIC B
{
	IColor* _myColor; // implementation
public:
	Model_B(IColor *obj) :_myColor(obj) {}
	string WhatIsMyType() 
	{
		return "I am a Model_B " + _myColor->Color();;
	}
};

int main()
{
	IColor* red = new RedColor();
	IColor* blue = new BlueColor();

	ICarModel* modelA = new Model_B(red);
	ICarModel* modelB = new Model_A(blue);

	cout << "\n" << modelA->WhatIsMyType();
	cout << "\n" << modelB->WhatIsMyType() << "\n\n";

	delete red;
	delete blue;
	return 1;
}
// I am a Model_B of Red Color
// I am a Model_A of Blue Color