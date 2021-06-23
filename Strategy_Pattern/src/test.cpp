/*
* start
*/
#include<iostream>
using namespace std;

// define an interface/abstract class that encapsulates the different fly behaviours
// this is done for behaviours/algorithms that can change in different client implementations
class flybehaviour {
   public:
      // pure virtual function providing interface
      virtual void fly() = 0;

};

// Derive concrete classes from the abstract class
// the flyNoWings class extends the interface/abstract class for the flybehaviour: Can't fly
class flyNoWings: public flybehaviour {
   public:
      void fly() {
         cout<<"I can't fly"<<endl;;
      }
};

// Derive concrete classes from the abstract class
// the flyWithWings class extends the interface/abstract class for the flybehaviour: Can fly
class flyWithWings: public flybehaviour {
   public:
      void fly() {
    	  cout<<"I can fly"<<endl;;
      }
};

// define the bird superclass
// client will inherit from the bird superclass
// we still use inheritance here since some code is common to each subclass
class bird{

public:
	// use a pointer-to-abstract class here
	// flyhow points to an interface
	flybehaviour *flyhow;

	// this method uses interface over implementation
	// this enables polymorphism
	// does not tie the flybehaviour implementation to the superclass
	void performfly()
	{
		flyhow->fly();
	}

	// display() is common across all subclasses
	// no need to rewrite this method in any subclass
	void display()
	{
		cout<<"I am a bird, and..."<<endl;
	}

	// this method can change the flybehaviour dynamically at runtime
	// without this method, we will be forced to rewrite same code in different subclasses
	void setflybehaviour(flybehaviour *ptr)
	{
		flyhow=ptr;
	}

};

// create subclass duck from bird superclass
class duck: public bird{
public:
	duck()
{
		cout<<"This is a duck"<<endl;
		// uses composition over inheritance
		// creates an object of type flyWithWings
		flyhow= new flyWithWings;
}
};

// create subclass penguin from bird superclass
class penguin: public bird{
public:
	penguin()
{
		cout<<"This is a penguin"<<endl;
		// uses composition over inheritance
		// creates an object of type flyNoWings
		flyhow= new flyNoWings;}
};

// create subclass duckling from bird superclass
class duckling: public bird{
public:
	duckling()
{
		cout<<"This is a duckling"<<endl;
		// uses composition over inheritance
		// note that this also uses a flyNoWings object
		flyhow= new flyNoWings;
}
};

int main(void) {
	// create a duck object
	// use a superclass (bird) pointer to point to duck object
	// this enables runtime polymorphism
   bird *duck1= new duck();
   duck1->display();
   duck1->performfly();

   cout<<endl;
	// create a penguin object
	// use a superclass (bird) pointer to point to duck object
	// this enables runtime polymorphism
   bird *penguin1= new penguin();
   penguin1->display();
   penguin1->performfly();
   cout<<endl;

	// create a duckling object
	// use a superclass (bird) pointer to point to duck object
	// this enables runtime polymorphism
   bird *duckling1=new duckling();
   duckling1->display();
   duckling1->performfly();
   cout<<"**Duckling requesting fly status**"<<endl;
   // use a method defined in superclass to change flybehaviour at runtime
   // otherwise have to rewrite the same code with a different method
   duckling1->setflybehaviour(new flyWithWings);
   // ducking fly behaviour changes with minimum effort
   duckling1->performfly();
   return 0;
}
