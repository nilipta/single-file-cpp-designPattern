#include <iostream>
#include <string>

using namespace std;

class ProductA {
    public:
        virtual ~ProductA(){}
        virtual string getName() = 0;
};

/*
 * ConcreteProductAX and ConcreteProductAY
 * define objects to be created by concrete factory
 */
class ProductAX : public ProductA {
    public:
        string getName()
        {
            return "Product A-X";   
        }
};

class ProductAY : public ProductA {
    public:
        string getName()
        {
            return "Product A-Y";   
        }
};

class ProductB {
    public:
        ~ProductB(){}
        virtual string getName() = 0;
};

/*
 * ConcreteProductBX and ConcreteProductBY
 * define objects to be created by concrete factory
 */
class ProductBX : public ProductB {
    public:
        string getName()
        {
            return "Product B-X";   
        }
};


class ProductBY : public ProductB {
    public:
        string getName()
        {
            return "Product B-Y";   
        }
};

/*
 * Abstract Factory
 * provides an abstract interface for creating a family of products
 */

class Factory {
    public:
        virtual ~Factory() {}
        virtual ProductA* createProductA() = 0;
        virtual ProductB* createProductB() = 0;
};

/*
 * Concrete Factory X and Y
 * each concrete factory create a family of products and client uses
 * one of these factories so it never has to instantiate a product object
 */
class FactoryX : public Factory
{
    public:
        ~FactoryX(){}
        ProductA* createProductA()
        {
            return new ProductAX();
        }
        ProductB* createProductB()
        {
            return new ProductBX();
        }
};


class FactoryY : public Factory
{
    public:
        ~FactoryY(){}
        ProductA* createProductA()
        {
            return new ProductAY();
        }
        ProductB* createProductB()
        {
            return new ProductBY();
        }

};

int main()
{
    FactoryX* objX = new FactoryX();
    FactoryY* objY = new FactoryY();

    ProductA* pA1 = objX->createProductA();
    ProductB* pA2 = objX->createProductB();

    cout << " ------- Creating Y ------- " << endl;

    cout << "X of product A = " << pA1->getName() << endl;
    cout << "X of product B = " << pA2->getName() << endl;

    cout << " ------- Creating Y ------- " << endl;

    ProductA* pB1 = objY->createProductA();
    ProductB* pB2 = objY->createProductB();

    cout << "y of product A = " << pB1->getName() << endl;
    cout << "y of product B = " << pB2->getName() << endl;
    
    delete objX;
    delete objY;
    delete pA1;
    delete pA2;
    delete pB1;
    delete pB2;

    return 0;
}


/*
OUTPUT

/a.out 
 ------- Creating Y ------- 
X of product A = Product A-X
X of product B = Product B-X
 ------- Creating Y ------- 
y of product A = Product A-Y
y of product B = Product B-Y

*/