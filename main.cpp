#include <iostream>

class Singleton {
public:
	static bool flag;
	static Singleton* ptr;
	static Singleton* constructorCaller() {
		if (!ptr) {
			ptr = new Singleton();
			flag = true;
		}
		return ptr;
	}
	~Singleton() {
		if (ptr != nullptr && flag) {
			std::cout << "Destructor" << std::endl;
			flag = false;
			delete ptr;
			ptr = nullptr;
		}
	}
	void set_data(std::string d) {
		data = d;
	}
	std::string get_data() {
		return data;
	}
private:
	Singleton() {
		std::cout << "Constructor" << std::endl;
	}
	std::string data;
};

Singleton* Singleton::ptr = nullptr;
bool Singleton::flag = false;

int main() {
	
	Singleton* s1 = Singleton::constructorCaller();
	Singleton* s2 = Singleton::constructorCaller();
	Singleton* s3 = Singleton::constructorCaller();
	s1->set_data("Singleton data");
	std::cout << s1->get_data() << std::endl;
	delete s1, s2, s3;
	return 0;
}