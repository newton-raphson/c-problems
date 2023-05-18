#include <iostream>
#include <iomanip>
#include "GradeBook.h" // GradeBook class definition using namespace std;

using namespace std;

GradeBook::GradeBook(const string &courseName, const array<int,students> &grades)
    :courseName(courseName),grades(grades)
{

}
void GradeBook::setCoursename(const string &name)
{
    courseName=name;
}

string GradeBook::getCoursename() const
{
    return courseName;
}

void GradeBook::displayMessage() const
{
    std::cout << "Welcome to the grade book for\n" << getCoursename() << std::endl;
}
int GradeBook::getMinimum() const
{
    int min= 100;
    for (int a:grades )
    {
        if (a<min)
        {
            min=a;
        }
        return min;
    }
}
int GradeBook::getMaximum() const
{
    int max = 0;
    for(int a:grades)
    {
        if(a>max)
        {
            max=a;
        }
        return max;
    }
}

double GradeBook::getAverage() const
{
    int sum = 0;
    for(int a:grades)
    {
        sum+=a;
    }
    return static_cast<double>(sum)/grades.size();
}
void GradeBook::outputBarChart() const
{
    array<int,grades.>
    for
}