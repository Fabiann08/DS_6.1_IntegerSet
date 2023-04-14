//THIS IS IntegerSet.cpp
#include "IntegerSet.h"
#include <vector>
#include <algorithm>
#include <set>

IntegerSet::IntegerSet()
{

    for (int i = 1; i <= 100; i++)
    {
        this->boolList.insert(i, false);
    }
}

IntegerSet::IntegerSet(int element)
{
    if (element >= 1 && element <= 100) 
        boolList.setEntry(element, true);
}

IntegerSet::IntegerSet(int array[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        boolList.setEntry(array[i], true);
    }
}

IntegerSet::IntegerSet(const IntegerSet& other)
{
    this->boolList = other.getBoolSet();
}

IntegerSet::~IntegerSet()
{
}

bool IntegerSet::isEmpty() const
{
    return boolList.isEmpty();
}

int IntegerSet::getLength() const
{
    return boolList.getLength();
}

bool IntegerSet::contains(int position) const
{
    return boolList.getEntry(position);
}

void IntegerSet::add(int positions[], int size)
{
    for (int i = 0; i < size; i++)
    {
        this->boolList.setEntry(positions[i], true);
    }
}

ArrayList<bool> IntegerSet::getBoolSet() const
{
    return boolList;
}


void IntegerSet::remove(int position)
{
    boolList.setEntry(position, false);
}

void IntegerSet::clear()
{
    boolList.clear();
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& other) const
{
    //create union of sets
    IntegerSet temp;
    for (int i = 1; i < 100; i++)
    {
        if (boolList.getEntry(i) || other.boolList.getEntry(i))
            if (boolList.getEntry(i))
                temp.boolList.insert(i, true);

        if (other.boolList.getEntry(i))
            temp.boolList.insert(i, true);
    }
    return temp;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& other) const
{
    //create intersection of sets
    IntegerSet temp;
    for (int i = 1; i < 100; i++)
    {
        if (boolList.getEntry(i) || other.boolList.getEntry(i))
            if (boolList.getEntry(i))
                temp.boolList.insert(i, true);

        if (other.boolList.getEntry(i))
            temp.boolList.insert(i, true);
    }
    return temp;

}

IntegerSet IntegerSet::differenceOfSets(const IntegerSet& other) const
{
    //difference
    IntegerSet result;
    for (int i = 1; i <= 100; i++) {
        if (boolList.getEntry(i) && !other.boolList.getEntry(i)) {
            result.boolList.setEntry(i, true);
        }
    }
    return result;
}


IntegerSet IntegerSet::symmetricDifferenceOfSets(const IntegerSet& other) const
{
    //Symmetric difference with ^
    IntegerSet result;
    for (int i = 1; i <= 100; i++) {
        if (boolList.getEntry(i) != other.boolList.getEntry(i)) 
        {
            result.boolList.setEntry(i, true);
        }
    }
    return result;
}

bool IntegerSet::isEqualTo(const IntegerSet& other) const
{
    // Check if the sizes of the two sets are equal
    if (this->boolList.getLength() != other.boolList.getLength()) 
    {
        return false;
    }

    // Iterate over the elements of both sets and compare them
    for (size_t i = 0; i < this->boolList.getLength(); i++) 
    {
        if (this->boolList[i] != other.boolList[i]) 
        {
            return false;
        }
    }

    // If all elements are equal, return true
    return true;
}

IntegerSet IntegerSet::operator+(const IntegerSet& other) const
{
    IntegerSet result;
    for (int i = 1; i <= 100; i++) {
        if (boolList.getEntry(i) || other.boolList.getEntry(i)) {
            result.boolList.setEntry(i, true);
        }
    }
    return result;
}

IntegerSet IntegerSet::operator^(const IntegerSet& other) const
{
    IntegerSet result;
    for (int i = 1; i <= 100; i++) {
        bool inThisSet = boolList.getEntry(i);
        bool inOtherSet = other.boolList.getEntry(i);
        if ((inThisSet && !inOtherSet) || (!inThisSet && inOtherSet)) {
            result.boolList.setEntry(i, true);
        }
    }
    return result;
}


IntegerSet IntegerSet::operator-(const IntegerSet& other) const
{
    IntegerSet result;
    for (int i = 1; i <= 100; i++) {
        if (boolList.getEntry(i) && !other.boolList.getEntry(i)) {
            result.boolList.setEntry(i, true);
        }
    }
    return result;
}

// Compute the intersection of two sets
IntegerSet IntegerSet::operator&(const IntegerSet& other) const
{
    IntegerSet result;
    for (int i = 1; i <= 100; i++) {
        if (boolList.getEntry(i) && other.boolList.getEntry(i)) {
            result.boolList.setEntry(i, true);
        }
    }
    return result;
}


bool IntegerSet::operator==(const IntegerSet& other)
{
    
    if (this->boolList.getLength() != other.boolList.getLength()) {
        return false;
    }
    for (int i = 1; i <= this->boolList.getLength(); i++) 
    {
        if (this->boolList.getEntry(i) != other.boolList.getEntry(i)) {
            return false;
        }
    }
    return true;
}



ostream& operator<<(ostream& out, const IntegerSet& other)
{
    out << "The set contents: { ";
    for (int i = 1; i <= 100; i++) {
        if (other.contains(i)) {
            out << i << " ";
        }
    }
    out << "}";
    return out;


}

istream& operator>>(istream& in, IntegerSet& other)
{
    int num;
    while (in >> num) {
        if (num >= 1 && num <= 100)
        {
            other.boolList.setEntry(num, true);
        }
    }
    return in;
}