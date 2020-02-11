#include <iostream>
#include <string>

using namespace std;

class Product {
    public:
        virtual ~Product() {}
        virtual string getName() = 0;
};

class ProductA : public Product
{
    public:
        ~ProductA() {}
        string getName() 
        {
            return ("product - A ");
        }
};

class ProductB : public Product
{
    public:
        ~ProductB() {}
        string getName() 
        {
            return ("product - B ");
        }
};

class Creator {
    public:
        ~Creator() {}
        virtual Product* CreateProductA() = 0;
        virtual Product* CreateProductB() = 0;
        virtual void removeProduct(Product* product) = 0;
};

class ConcreteCreator : public Creator {
    public:
        ~ConcreteCreator() {}
        Product* CreateProductA()
        {
            return new ProductA();
        }

        Product* CreateProductB()
        {
            return new ProductB();
        }
        
        void removeProduct(Product* product)
        {
            if(product)
            {
                delete product;
            }
        }
};

int main()
{
    Creator* obj = new ConcreteCreator();

    Product* P1 = obj->CreateProductA();
    cout << "Product : " << P1->getName() << endl;
    obj->removeProduct(P1);
    
    Product* P2 = obj->CreateProductB();
    cout << "Product : " << P2->getName() << endl;
    obj->removeProduct(P2);

    delete obj;

    return 0;
}


/*
[pi@raspberrypi] 003FactoryMethod$  ./a.out 
Product : product - A 
Product : product - B 
*/
