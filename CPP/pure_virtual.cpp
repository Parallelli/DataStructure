#include <iostream>
using namespace std;

//class with pure virtual function is an abstract base class, abstract base
//class cannot be used to instantiate objects, i.e. Polygon poly;(invalid)
//It can be used to create pointer to it, i.e. Polygon *ppoly1;
class Polygon
{
    protected:
        int width, height;
    public:
        void set_values(int a, int b)
        {
            width = a;
            height = b;
        }
        virtual int area() = 0; //pure virtual function
        void printarea()
        {
            cout << this->area() << endl;
        }
};

class Rectangle: public Polygon
{
    public:
        int area()
        {
            return width * height;
        }
};

class Triangle: public Polygon
{
    public:
        int area()
        {
            return width * height / 2;
        }
};

int main()
{
    //example of polymorphism in C++
    Rectangle rect;
    Triangle trgl;
    Polygon *ppoly1 = &rect;
    Polygon *ppoly2 = &trgl;
    ppoly1 -> set_values(4,5);
    ppoly2 -> set_values(4,5);
    cout << rect.area() << endl;//20
    cout << trgl.area() << endl;//10
    cout << "-----seperator------------" << endl;
    //power of virtual function
    //we we use the object of base class Polygon rather than Rectangle or
    //Triangle to call function area(), it can still know which area() to
    //call
    //cout << ppoly1->area() << endl;
   // cout << ppoly2->area() << endl;
     ppoly1->printarea();
     ppoly2->printarea();
    
   // Polygon poly; //invalid instantiation for abstract base class Polygon

    return 0;
}
