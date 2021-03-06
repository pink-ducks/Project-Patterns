#include <iostream>
#define WINDOWS

using namespace std;

class Widget {
public:
	virtual void draw() = 0;
};

class LinuxButton : public Widget {
public:
	void draw() { cout << "LinuxButton\n"; }
};

class WindowsButton : public Widget {
public:
	void draw() { cout << "WindowsButton\n"; }
};

// INTERFACE
class Factory {
public:
	virtual Widget *create_button() = 0; // VIRTUAL CREATE BUTTON!!!
};

class LinuxFactory : public Factory {
public:
	Widget *create_button() {		// CREATE BUTTON
		return new LinuxButton;
	}
};

class WindowsFactory : public Factory {
public:
	Widget *create_button() {		// CREATE BUTTON
		return new WindowsButton;
	}
};

// class Client isn't in Abstract Factory Diagram
class Client {
private:
	Factory *factory;

public:
	Client(Factory *f) {
		factory = f;
	}

	void draw() {
		Widget *w = factory->create_button();
		w->draw();
	}
};

int main() {
	Factory *factory;
#ifdef LINUX	// check define (2nd line of program)
	factory = new LinuxFactory;
#else //WINDOWS 
	factory = new WindowsFactory;
#endif

	Client *c = new Client(factory);
	c->draw();
}