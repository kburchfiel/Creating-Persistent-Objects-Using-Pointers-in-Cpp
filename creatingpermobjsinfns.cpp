//AMDG
//This simple program shows how pointers can be used to create objects of a class in a function that (A) persist after the function concludes, and (B) can be referenced and modified individually within the program even though they don't have specific names.
//I have no doubt that these concepts are elementary to the majority of C++ programmers, but perhaps this example can be beneficial to individuals like me who are new to the programming langauge.
//The following lecture notes let me determine how to reference objects directly through my pointer of vectors: https://www.usna.edu/Users/cs/choi/ic210/lec/l40/lec.html
//Kenneth Burchfiel, 6/6/2020

#include <iostream>
#include <vector>
using namespace std;

class Airplane
{

public:
    int modelnum;
    string manufacturer;

    Airplane(int i, string s)
        : modelnum(i), manufacturer(s)
    {
    }
};

void createpersistentobjects(vector<Airplane *> &v) //This function lets us create objects of class Airplane (defined above) that will persist after the function concludes, and that we can access individually.
//The function's argument is a reference to a vector of pointers to Airplane objects.
{
    int z = 707;
    for (int x = 0; x < 10; x++)
    {
        Airplane *aptr = new Airplane(z, "Boeing"); //For each cycle of the for loop, we create a new pointer (aptr) that points to an Airplane object created in the free store.
        v.push_back(aptr);                          //This pointer is now added to the Airplane pointers vector that we reference in our argument.
        z += 10;
    }
}
//Even though this function is void and therefore doesn't return anything, it does modify our Airplane pointers vector due to the use of & in the argument field to specify the creation of a reference.

void newobjwoutptr(int i2, string s2) //Trying to create a new class object without using pointers
{
    Airplane a1(i2, s2);
    cout << "Created Airplane object a1 with model number " << i2 << " and manufacturer name " << s2 << ".\n";
    //This Airplane gets created, but it's then destroyed after the function concludes. Therefore, this approach is inadequate and won't be used in our program.
}

int main()
{
    vector<Airplane *> airplaneobjptrs; //A vector that we'll fill with pointers to specific airplane objects

    createpersistentobjects(airplaneobjptrs);

    //We have not only created 10 new Airplane objects through our createpersistentobjects function, but can also access them individually. Even though the objects weren't given specific names (e.g. Airplane a1, Airplane a2), they each have a specific pointer assigned to them, which can be dereferenced to display the object.
    cout << "Airplane objects that were accessed through a vector of pointers:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Pointer location: " << airplaneobjptrs[i] << " Model number: " << (*airplaneobjptrs[i]).modelnum << " Manufacturer: " << (*airplaneobjptrs[i]).manufacturer << "\n"; //This cout statement displays the values assigned to the airplane object connected to the deferenced pointer. The parentheses are necessary for the program to compile (as I learned from https://www.usna.edu/Users/cs/choi/ic210/lec/l40/lec.html)
    }

    //It's also possible to modify values of members of objects using our vector of pointers. For instance:

    cout << "Switching model numbers to Airbus:\n";
    int Airbusval = 300;
    for (int i = 0; i < 10; i++)
    {
        (*airplaneobjptrs[i]).modelnum = Airbusval;
        Airbusval += 10;
        (*airplaneobjptrs[i]).manufacturer = "Airbus";
    }

    //Another for loop showing how the values of airplaneobjptrs have changed (while the pointer locations have stayed the same):
    for (int i = 0; i < 10; i++)
    {
        cout << "Pointer location: " << airplaneobjptrs[i] << " New model number: " << (*airplaneobjptrs[i]).modelnum << " New manufacturer: " << (*airplaneobjptrs[i]).manufacturer << "\n"; //This cout statement displays the values assigned to the airplane object connected to the deferenced pointer. The parentheses are necessary for the program to compile (as I learned from https://www.usna.edu/Users/cs/choi/ic210/lec/l40/lec.html)
    }


for (int i = 0; i < airplaneobjptrs.size(); i++)
    {
        delete airplaneobjptrs[i]; //Freeing up memory by deleting each pointer stored in the vector of pointers
    };


    //The following two lines will keep the external console window open.
    char c;
    cin >> c;
}

/* Text produced by this code on the console: (Pointer location values will vary across users/instances of the program, but the two lists of pointers below should match each time the program is run)
Airplane objects that were accessed through a vector of pointers:
Pointer location: 0x1d1af0 Model number: 707 Manufacturer: Boeing
Pointer location: 0x1d1f20 Model number: 717 Manufacturer: Boeing
Pointer location: 0x1d1fc0 Model number: 727 Manufacturer: Boeing
Pointer location: 0x2532500 Model number: 737 Manufacturer: Boeing
Pointer location: 0x2532560 Model number: 747 Manufacturer: Boeing
Pointer location: 0x2532630 Model number: 757 Manufacturer: Boeing
Pointer location: 0x2532690 Model number: 767 Manufacturer: Boeing
Pointer location: 0x25326f0 Model number: 777 Manufacturer: Boeing
Pointer location: 0x2532750 Model number: 787 Manufacturer: Boeing
Pointer location: 0x25325c0 Model number: 797 Manufacturer: Boeing
Switching model numbers to Airbus:
Pointer location: 0x1d1af0 New model number: 300 New manufacturer: Airbus
Pointer location: 0x1d1f20 New model number: 310 New manufacturer: Airbus
Pointer location: 0x1d1fc0 New model number: 320 New manufacturer: Airbus
Pointer location: 0x2532500 New model number: 330 New manufacturer: Airbus
Pointer location: 0x2532560 New model number: 340 New manufacturer: Airbus
Pointer location: 0x2532630 New model number: 350 New manufacturer: Airbus
Pointer location: 0x2532690 New model number: 360 New manufacturer: Airbus
Pointer location: 0x25326f0 New model number: 370 New manufacturer: Airbus
Pointer location: 0x2532750 New model number: 380 New manufacturer: Airbus
Pointer location: 0x25325c0 New model number: 390 New manufacturer: Airbus

*/