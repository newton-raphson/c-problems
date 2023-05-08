#include <string>
#include <iostream>
#include "GradeBook.h"

GradeBook::GradeBook(std::string courseName, std::string instructorName)
    :courseName(courseName),instructorName(instructorName)
    {

    }
void GradeBook::setCoursename(std::string name)
{
    courseName=name;
}
void GradeBook::setInstructorName(std::string name)
{
    instructorName=name;
}
std::string GradeBook::getCoursename() const
{
    return courseName;
}
std::string GradeBook::getInstructorname() const
{
    return instructorName;
}
void GradeBook::displayMessage() const
{
    std::cout << "Welcome to the grade book for\n" << getCoursename()
<< "!\n"<<"This course is presented by \n"<<getInstructorname() << std::endl;
}