
#include <iostream>

using namespace std;

// base class 1

class Movie {
    public:
    string name1;
    
    // ambiguity problem
    void function1() {
        cout << "I love watching movies." << endl;
    }
    
    // base class 1 constructor
     Movie (string nameOfTheMovie) {
        name1 = nameOfTheMovie;
        
    }
};

// base class 2

class Theatre {
    public:
    string name2;
    
    // ambiguity problem
    void function1() {
        cout << "I love Broadway shows." << endl;
    }
    
    // base class 2 constructor
    Theatre (string nameOfTheShow) {
        name2 = nameOfTheShow;
    }
};

// derived class
class Actor: public Movie, public Theatre {
    public: 
    void function2() {
        cout << "I love watching movies and attending Broadway shows." << endl;
    }
    
    // derived class constructor
    Actor (string name1, string name2) : Movie(name1), Theatre(name2) {}
};


int main()
{
    Actor actorObj ("'One Flew Over the Cuckoo's Nest'", "'Lion king'");
    
    cout << actorObj.name1 << endl;
    
    cout << actorObj.name2 << endl;
    
    // ambiguity problem solved
    actorObj.Movie::function1();
    actorObj.Theatre::function1();
    
    actorObj.function2();
    
    return 0;
}