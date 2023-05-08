#include <iostream>
#include "GradeBook.h"

using namespace std;

int main ()
{
    GradeBook gradebook1("Study C++","RK STRYNG");
    cout << "The course name is" << gradebook1.getCoursename() << endl;
    cout << "The instructors name is" << gradebook1.getInstructorname() << endl;
    gradebook1.displayMessage();
    gradebook1.setCoursename("How to C++");
    cout << "The course name is" << gradebook1.getCoursename() << endl;
    gradebook1.setInstructorName("Hari Krishna");
    cout << "The instructors name is" << gradebook1.getInstructorname() << endl;
    gradebook1.displayMessage();
}