#include <iostream>
#include <string>

using namespace std;

class Product {
    public:
        Product() {}
        ~Product() {}

        void makePartA(const string &arg){ partNameA = arg; }
        void makePartB(const string &arg) { partNameB = arg; }
        void makePartC( const string &arg) { partNameC = arg;}

        string getTotalProduct() {
            return partNameA + " " + partNameB + " " + partNameC ;
        }

    private:
        string partNameA;
        string partNameB;
        string partNameC;
};

class Builder {
    public:
        virtual ~Builder() {}

        Product get() {
            return product; 
        }

        virtual void buildPartA() = 0;
        virtual void buildPartB() = 0;
        virtual void buildPartC() = 0;

    protected:
        Product product;
};

class ConcreteBuilderX : public Builder {
    public:
        virtual ~ConcreteBuilderX() {}
        virtual void buildPartA() {
            product.makePartA("A-X");
        }
        virtual void buildPartB() {
            product.makePartB("B-X");
        }
        virtual void buildPartC() {
            product.makePartC("C-X");
        }

};

class ConcreteBuilderY : public Builder {
    public:
        virtual ~ConcreteBuilderY() {}
        virtual void buildPartA() {
            product.makePartA("A-Y");
        }
        virtual void buildPartB() {
            product.makePartB("B-Y");
        }
        virtual void buildPartC() {
            product.makePartC("C-Y");
        }

};

class Director {
    public:
        ~Director()
        {
            if(builder)
                delete builder;
        }

        void set( Builder* builderObj) {
            builder = builderObj;
        }

        Product get() {
            return builder->get();
        }

        void construct() {
            builder->buildPartA();
            builder->buildPartB();
            builder->buildPartC();
        }

    private:
        Builder* builder;
};

int main()
{
    Director builderDIrector;
    builderDIrector.set( new ConcreteBuilderX );
    cout << "debug 1" <<endl;
    builderDIrector.construct();
    Product product1 = builderDIrector.get();
    cout << " \n-------Concrete BulderX--------" << endl;

    cout << "Part A : " << product1.getTotalProduct() << endl;

    builderDIrector.set( new ConcreteBuilderY );
    builderDIrector.construct();
    Product product2 = builderDIrector.get();
    cout << " \n-------Concrete BulderY--------" << endl;
    cout << "Part A : " << product2.getTotalProduct() << endl;

    return 0;
}