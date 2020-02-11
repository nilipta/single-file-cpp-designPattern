#include <iostream>
#include <string>

using namespace std;

class Prototype {
    public:
        virtual ~Prototype() {}
        virtual Prototype* clone() = 0;
        virtual string getType() = 0;
};

class ConcretePrototypeA : public Prototype {
    public:
        ~ConcretePrototypeA() {}
        Prototype* clone()
        {
            return new ConcretePrototypeA();
        }

        string getType()
        {
            return ("type -A");
        }
};

class ConcretePrototypeB : public Prototype {
    ~ConcretePrototypeB() {}
    Prototype* clone()
    {
        return new ConcretePrototypeB();
    }

    string getType()
    {
        return ("type -B");
    }
};

class Client
{
    public:
        static void init()
        {
            C[0] = new ConcretePrototypeA();
            C[1] = new ConcretePrototypeB();
        }

        static void clear()
        {
            for(auto i = 0; i < nums ; i++)
            {
                delete C[i];
            }
        }

        static Prototype* make( const int i)
        {
            if(i >= nums)
            {
                return nullptr;
            }
            else {
                return C[i]->clone();
            }
            return nullptr;
        }

    private:
        static Prototype* C[2];
        static int nums;
};

/*

We can't put it in the class definition 
but it can be initialized outside the class
as done in the following example by redeclaring the static variable,
using the scope resolution operator :: to identify which class it belongs to.
*/

Prototype* Client::C[2];
int Client::nums = 2;

int main()
{
    Client::init();

    Prototype* P1 = Client::make(0);
    cout << "Protype = " << P1->getType() << endl;

    Prototype* P2 = Client::make(1);
    cout << "Protype = " << P2->getType() << endl;
    Client::clear(); 


    return 0;
}