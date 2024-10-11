#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

/*
TEST INPUT: 

Lee 18
Lua 21
Mary Beth 19
Stu 33
-1
*/

/*
OUTPUT:

Lee 19
Lua 22
Mary 0
Stu 34
*/

int main() {
  string inputName;
  int age;
  // Set exception mask for cin stream
  cin.exceptions(ios::failbit);

  cin >> inputName;
  while(inputName != "-1") {
    try { // try to output name and age + 1
        cin >> age;
        cout << inputName << " " << (age + 1) << endl;
    } // if it doesn't get expected values,
    catch (ios_base::failure& e) {
        cin.clear(); // clear the input
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the max amount of values until newline
        age = 0;
        cout << inputName << " " << age << endl; // output 0 as age
    }
    

    cin >> inputName;
  }
  
  return 0;
}