/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <#place holder#> placeholders with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
    the possible return values of the compare() function should give you a hint.
    Also: if smaller == nullptr, make the cout statement explain the reasons that `f.compare()` might return nullptr.  
    hint: There are multiple reasons
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
#include <string>
struct T
{
    T(short v, const char* ch) : value(v), name(ch) {}    //1

    int value;
    const char* name;
};

struct Comparator                              //4
{
    T* compare(T* a, T* b) //5
    {
        if (a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float floatU1 { 0 }, floatU2 { 0 };
    float updateValue(float* valueToUpdateTo)      //12
    {
        if (valueToUpdateTo != nullptr)
        {
            std::cout << "U's floatU1 value: " << this->floatU1 << std::endl;
            this->floatU1 = *valueToUpdateTo;
            std::cout << "U's floatU1 updated value: " << this->floatU1 << std::endl;
            while( std::abs(this->floatU2 - this->floatU1) > 0.001f )
            {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
                this->floatU2 += (this->floatU1 < this->floatU2) ? -1.0f : 1.0f;
                std::cout << "U's floatU2 temporary value is " << this->floatU2 << std::endl;
            }
            std::cout << "U's floatU2 updated value: " << this->floatU2 << std::endl;
            return this->floatU2 * this->floatU1;
        }
        std::cout << "Warning. Passed argument is nullptr!\n";
        return 0.0f;
    }
};

struct Updater
{
    static float updateValue(U* that, float* valueToUpdateTo)        //10
    {
        if (that != nullptr && valueToUpdate != nullptr)
        {
            std::cout << "U's floatU1 value: " << that->floatU1 << std::endl;
            that->floatU1 = *valueToUpdateTo;
            std::cout << "U's floatU1 updated value: " << that->floatU1 << std::endl;
            while( std::abs(that->floatU2 - that->floatU1) > 0.001f )
            {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            that->floatU2 += (that->floatU1 < that->floatU2) ? -1.0f : 1.0f;
            std::cout << "U's floatU2 temporary value is " << that->floatU2 << std::endl;
            }
            std::cout << "U's floatU2 updated value: " << that->floatU2 << std::endl;
            return that->floatU2 * that->floatU1;
        }
        std::cout << "Warning. One of passed arguments is nullptr!\n";
        return 0.0f;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T T1(5, "a");                                             //6
    T T2(3, "b");                                             //6
    
    Comparator f;                                            //7
    auto* smaller = f.compare(&T1, &T2);                              //8
    std::cout << "the smaller one is << " << ((smaller != nullptr) ? smaller->name : "None of them") << std::endl; //9
    
    U U1;
    float updatedValue = 5.f;
    std::cout << "[static func] U1's multiplied values: " << Updater::updateValue(&U1, &updatedValue) << std::endl;                  //11
    
    U U2;
    std::cout << "[member func] U2's multiplied values: " << U2.updateValue(&updatedValue) << std::endl;

    std::cout << "13. ALWAYS TO CHECK IF THE POINTER IS NOT NULLPTR BEFORE USING IT!!!\n";    //13
}
