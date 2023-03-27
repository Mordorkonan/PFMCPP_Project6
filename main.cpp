/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float floatU1 { 0 }, floatU2 { 0 };
    float updateValue(const float& valueToUpdateTo)      //12
    {
        std::cout << "U's floatU1 value: " << this->floatU1 << std::endl;
        this->floatU1 = valueToUpdateTo;
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
};

struct Updater
{
    static float updateValue(U& that, const float& valueToUpdateTo)        //10
    {
        std::cout << "U's floatU1 value: " << that.floatU1 << std::endl;
        that.floatU1 = valueToUpdateTo;
        std::cout << "U's floatU1 updated value: " << that.floatU1 << std::endl;
        while( std::abs(that.floatU2 - that.floatU1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            that.floatU2 += (that.floatU1 < that.floatU2) ? -1.0f : 1.0f;
            std::cout << "U's floatU2 temporary value is " << that.floatU2 << std::endl;
        }
        std::cout << "U's floatU2 updated value: " << that.floatU2 << std::endl;
        return that.floatU2 * that.floatU1;
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
    T t1(5, "a");                                             //6
    T t2(3, "b");                                             //6
    
    Comparator f;                                            //7
    auto* smaller = f.compare(t1, t2);                              //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "smaller is nullptr because both arguments are equal.\n";
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] U1's multiplied values: " << Updater::updateValue(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] U2's multiplied values: " << u2.updateValue(updatedValue) << std::endl;

    std::cout << "13. ALWAYS TO CHECK IF THE POINTER IS NOT NULLPTR BEFORE USING IT!!!\n";    //13
}
