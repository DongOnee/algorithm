#include <iostream>
using namespace std;

class Base
{
	public:
		virtual void foo() = 0;
		virtual void bar() = 0;
};

class Der1 : public virtual Base
{
	public:
		virtual void foo()
		{
			bar();
		};
};

class Der2 : public virtual Base
{
	public:
		virtual void bar() {cout << "Der2's bar()" << endl;};
};

class Join : public Der1, public Der2
{
	// public:
	// 	void foo() {
	// 		cout << "foo()" << endl;
	// 	};
	// 	void bar() {
	// 		cout << "bar()" << endl;
	// 	};
};

int main(void)
{
	Join* p1 = new Join();
	Der1* p2 = p1;
	Base* p3 = p1;

	p1->foo();
	p2->foo();
	p3->foo();
}
