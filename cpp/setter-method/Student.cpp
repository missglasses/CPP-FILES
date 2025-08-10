#include "Student.hpp"

Student::Student(string studentName, int studentAge) : name(studentName), age(studentAge) {}

// getter methods
string Student::getName() {
    return name;
}

int Student::getAge() {
    return age;
}

// setter methods
void Student::setName(string newName){
  name = newName;
}

void Student::setAge(int newAge) {
    age = newAge;
}
