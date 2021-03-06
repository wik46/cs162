/*
 * Filename: inheritance1.cpp
 * Author: Wikus
 * Date: October 7, 2020
 * Description: This program is used to study how the inherance works. 
 *
 * */

#include <iostream>

class Person{
public: // Everything is public to make the example simplies.
	// Member variables.
	std::string m_name;
	int m_age;
	
	// Methods.
	friend std::ostream& operator<<(std::ostream& stream, const Person& object){
		stream << object.m_name << ", " << object.m_age << std::endl;
		return stream;
	}
	// The default constructor.
	Person(const std::string& name = "", int age = 0)
		: m_name{name}, m_age{age}
	{}
	// The big three.
	// 1. The destructor.
	~Person(){
		std::cout << "The Person destructor was called." << std::endl;
	}	
	// 2. The copy constructor. (shallow or deep copy.)
	// 3. Assignment operator overloading.
	
	void print(){
		std::cout << "Method of the parent." << std::endl;
	}
};

class RugbyPlayer: public Person
{
public:
	std::string m_team_name;
	RugbyPlayer(){}	
	
	RugbyPlayer(const char* team_name): m_team_name{team_name}
	{
		std::cout << "Rugby player was constructed by default constructor." << std::endl;
	}
	// Still need to add member variables and member
	
	void print(){
		std::cout << "Method of the child." << std::endl;
	}

};

// Note that a rugby team 'has' rugby players in its team. Therefore it rugby players are members of the team.
class RugbyTeam
{
	// The Big Three.


};
int main(){
	//RugbyPlayer r("Blue Bulls");
	Person p;
	RugbyPlayer r;
	// Notice that both the parent and the child have a print function
	// with different functionality. The variable of type Person will envoke its own print()
	// function and the variable of type RugbyPlayer will envoke its own parent.
	//p.print();
	r.print();
	
	// You can create an array of Parents and store children in them.
	Person p_ar[3];
	p_ar[0] = r;
	
	//p_ar[0].print();	
	std::cout << p_ar[0] << std::endl;
	std::cout << r << std::endl;
	return 0;
}

