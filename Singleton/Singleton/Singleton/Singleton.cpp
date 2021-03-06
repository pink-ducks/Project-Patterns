#include <iostream>

class Singleton {
private:	
	int data;
	// Private constructor so that no objects can be created.
	Singleton() 
	{
		data = 0;
	}

public:
	static Singleton & getInstance() {
		static Singleton instance;
		return instance;
	}

	int getData() const 
	{
		return this->data;
	}

	void setData(int data) {
		this->data = data;
	}
};

int main() {
	Singleton & s = Singleton::getInstance();
	Singleton & s2 = Singleton::getInstance();
	//Singleton test1; <-- can't be created because constructor is private
	std::cout << s.getData() << std::endl; // 0
	s.setData(100);
	std::cout << s.getData() << std::endl; // 100
	std::cout << s2.getData() << std::endl; // 100 ( we didn't set s2 data!)
	return 0; 
}

// This will give the output:
// 0
// 100
// 100