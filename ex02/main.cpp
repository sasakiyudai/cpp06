#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate(void);
void identify_from_pointer(Base * p);
void identify_from_reference(Base & p);

Base *generate(void)
{
	int randomVal = rand() % 3;

	if (randomVal == 0)
		return (new A());
	else if (randomVal == 1)
		return (new B());
	else
		return (new C());
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
}

void identify_from_reference(Base &p)
{
	identify_from_pointer(&p);
}

int main()
{
	srand(time(NULL));

	Base *random = generate();
	identify_from_pointer(random);
	identify_from_reference(*random);
	std::cout << std::endl;
	random = generate();

	identify_from_pointer(random);
	identify_from_reference(*random);
	std::cout << std::endl;
	random = generate();

	identify_from_pointer(random);
	identify_from_reference(*random);
	std::cout << std::endl;
	random = generate();

	identify_from_pointer(random);
	identify_from_reference(*random);
	std::cout << std::endl;
	random = generate();

	identify_from_pointer(random);
	identify_from_reference(*random);
	std::cout << std::endl;
}