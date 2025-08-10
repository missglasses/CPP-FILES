#include <iostream>
#include "Student.hpp"

using namespace std;

int main() {
    Student student("Peter", 20);
    
    cout << "Original Name: " << student.getName() << endl;
    cout << "Original Age: " << student.getAge() << endl;
    
 //setters for modifying data
    student.setName("John");
    student.setAge(21);
    
    cout << "Updated Name: " << student.getName() << endl;
    cout << "Updated Age: " << student.getAge() << endl;
    
    return 0;
}
