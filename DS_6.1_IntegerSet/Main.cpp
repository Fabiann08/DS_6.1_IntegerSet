//THIS IS IntegerSet.cpp
#include "IntegerSet.h"
#include "PrecondViolatedExcep.h"
#include <iostream>
#include <set>

using namespace std;


int main()
{
    int option, size, size2, array1[1], array2[1];
    IntegerSet set1, set2;
    IntegerSet unionS, intersection, diference, symetricDiff;

    try {
        cout << "Input the first set:\nHow many numbers will the first set have? ";
        cin >> size;
        if (size <= 0 || size > 100) 
        {
            throw PrecondViolatedExcep("Invalid size input");
        }
        cout << "Input " << size << " numbers: \n";
        for (int i = 0; i < size; i++)
        {
            cin >> array1[i];
        }
        set1.add(array1, size);

        cout << "\nInput the second set:\nHow many numbers will the second set have?";
        cin >> size2;
        if (size2 <= 0 || size2 > 100) 
        {
            throw PrecondViolatedExcep("Invalid size input");
        }
        cout << "Input " << size2 << " numbers: \n";
        for (int i = 0; i < size2; i++)
        {
            cin >> array2[i];
        }
        set2.add(array2, size2);
    }
    catch (PrecondViolatedExcep& message)
    {
		cout << "Error: "<< message.what() << endl;
        exit(1);
	}

    do
    {
        cout << "\nMENU - Please select an option:\n"
            << "1. Union of Sets\n"
            << "2. Intersection of Sets\n"
            << "3. Difference between two Sets\n"
            << "4. Symmetric Difference of two Sets\n"
            << "5. Verify if two sets are equal\n"
            << "6. Print set\n"
            << "7. Exit\n\n";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\nHere is the union of the two sets: \n";
            unionS = set1 + set2;
            cout << unionS << endl;
            break;
        case 2:
            cout << "\nHere is the intersection of the two sets: \n";
            intersection = set1 & set2;
            cout << intersection << endl;
            break;
        case 3:
            cout << "\nHere is the difference of set A and B: \n";
            diference = set1 - set2;
            cout << diference << endl;
            break;
        case 4:
            cout << "\nHere is the symmetric difference of the two sets: \n";
            symetricDiff = set1 ^ set2;
            cout << symetricDiff << endl;
            break;
        case 5:
            if (set1 == set2)
            {
                cout << "\nThe sets are equal" << endl;
            }
            else
            {
                cout << "\nThe sets are not equal" << endl;
            }
            break;

        case 6:
            cout << "\nShowing both sets: \n";
            cout << set1 << endl;
            cout << set2 << endl;
            break;

        case 7:
            cout << "\n\nExiting...\n\n";
            return 0;
            break;
        default:
            cout << "\nError... Choose a number between 1 - 7.\n";
            break;
        }
    } while (option < 8);


    return 0;

}