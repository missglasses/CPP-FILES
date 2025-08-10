#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string studentName, int studentAge);
    
    // getter methods
    string getName();
    int getAge();

    //setter methods
  void setName(string getName);
  void setAge(int getAge);
};
