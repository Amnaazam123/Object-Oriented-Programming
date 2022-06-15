/*
output:
Loading weapon features.                //while creating b object
Loading weapon features.                //while creating g object
Loading weapon features.                //while exectuting this->weapon::features();
Loading bomb features.                   //polymorphism
Loading weapon features.                //while exectuting this->weapon::features();
Loading gun features.                   //polymorphism
*/

#include <iostream>
using namespace std;
class Weapon
{
public:
	Weapon() 
	{
		cout << "Loading weapon features.\n";
	}
	virtual void features()
	{
		cout << "Loading weapon features.\n";
	}
};
class Bomb : public Weapon
{
public:
	void features()                        //no need to define this function virtual because there is inheritance 
	{
		this->Weapon::features();
		cout << "Loading bomb features.\n";
	}
};
class Gun : public Weapon
{
public:
	void features()                        //no need to define this function virtual because there is inheritance 
	{
		this->Weapon::features();
		cout << "Loading gun features.\n";
	}
};
class Loader
{
public:
	void loadFeatures(Weapon* weapon)
	{
		weapon->features();
	}
};
int main()
{
	Loader* l = new Loader();
	Bomb b;
	Gun g;
	l->loadFeatures(&b);
	l->loadFeatures(&g);
	return 0;
}


