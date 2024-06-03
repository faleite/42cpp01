#include <iostream>

class MyClass
{
	public:
		int data;
		void setData(int value) { data = value; }
		void getData() const {
			std::cout << "Data: " << data << std::endl;
		}
};

int	main(){
	MyClass obj;

	int	MyClass::*ptrToData = &MyClass::data;

	void (MyClass::*ptrToSetData)(int) = &MyClass::setData;
	void (MyClass::*ptrToGetData)() const = &MyClass::getData;

	(obj.*ptrToSetData)(42);
	(obj.*ptrToGetData)();
	std::cout << obj.*ptrToData << std::endl; 

	return (0);
}