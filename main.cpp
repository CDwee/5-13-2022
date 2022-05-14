// Started at 5:13 5-13-2022

// Section 11
// Scope example
#include <iostream>

using namespace std;

void local_example();
void global_example();
void static_local_example();

int num {300};    // Global variable - declared outside any class or function

void global_example() {
    cout << "\nGlobal num is: " << num << " in global_example - start" << endl;
    num *= 2;
    cout << "Global num is: " << num << " in global_example - end" << endl;
}

void local_example(int x) {
    int num {1000};     // local to local_example
    cout << "\nLocal num is: " << num << " in local_example - start" << endl;
    num = x;
    cout << "Local num is: " << num << " in local_example - end" << endl;
    // num1 in main is not within scope - so it can't be used here.
}

void static_local_example() {
    static int num {5000};
    cout << "\nLocal static num is: " << num << " in static_local_example - start" << endl;
    num += 1000;
    cout << "Local static num is: " << num << " in static_local_example - end" << endl;
}

int main() {
    
    int num {100};  // Local to main
    int num1 {500}; // Local to main
    
    cout << "Local num is: " << num << " in main" << endl;
    
    {   // creates a new level of scope
        int num {200};  // local to this inner block
        cout << "Local num is: " << num << " in inner block in main" << endl;
        cout << "Inner block in main can see out - num1 is: " << num1 << endl;
    }
    
    cout << "Local num is: " << num << " in main" << endl;
    
    local_example(10);
    local_example(20);
    
    global_example();
    global_example();

    static_local_example();
    static_local_example();
    static_local_example();
    
    cout << endl;
    return 0;
}

// Section 11
// How Function Calls Work
// The call stack
#include <iostream>

using namespace std;

void func2(int &x, int y, int z) {
    x+= y + z;
}

int func1(int a, int b) {
    int result {};
    result = a + b;
    func2(result, a, b);
    return result;
}

int main() {
    int x {10};
    int y {20};
    int z{};
    z = func1(x, y);
    cout << z << endl;
    return 0;
}

/* What typically happens when main calls func1 (or any function calls another) ?
    There are other ways to acheive the same results :)
    
    main:
        push space for the return value
        push space for the parameters
        push the return address
        transfer control to func1 (jmp)
    func1:
        push the address of the previous activation record
        push any register values that will need to be restored before returning to the caller
        perform the code in func1
        restore the register values
        restore the previous activation record (move the stack pointer)
        store any function result
        transfer control to the return address (jmp)
    main:
        pop the parameters
        pop the return value
*/

// Ended at 7:14 5-13-2022
