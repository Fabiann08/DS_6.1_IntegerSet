//THIS IS IntegerSet.h
#include <iostream>
#include <string>
#include <vector>
#include "ArrayList.cpp"
using namespace std;

class IntegerSet 
{
private:
    ArrayList<bool> boolList;
public:
    IntegerSet();                        //default constructor
    IntegerSet(int element);             //Overloader for parameter constructor
    IntegerSet(int array[], int size);   //Parameter constructor
    IntegerSet(const IntegerSet &other); //copy constructor
    ~IntegerSet();                       //destructor
    bool isEmpty() const;
    int getLength() const;
    bool contains(int position) const;
    ArrayList<bool> getBoolSet() const;
    void add(int position[], int size);
    void remove(int position);
    void clear();
    IntegerSet unionOfSets(const IntegerSet &other) const;
    IntegerSet intersectionOfSets(const IntegerSet &other) const;
    IntegerSet differenceOfSets(const IntegerSet &other) const;
    IntegerSet symmetricDifferenceOfSets(const IntegerSet &other) const;
    bool isEqualTo(const IntegerSet& other) const;
    IntegerSet operator+(const IntegerSet &other) const;
    IntegerSet operator^(const IntegerSet& other) const;
    IntegerSet operator-(const IntegerSet &other) const;
    IntegerSet operator&(const IntegerSet& other) const;
    bool operator==(const IntegerSet& other);
    friend ostream & operator<<(ostream & output, const IntegerSet & other);
    friend istream & operator>>(istream & input, IntegerSet & other);
};