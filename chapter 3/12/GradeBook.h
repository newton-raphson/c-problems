#include <string>

class GradeBook{
    //define interfaces here
    public:
        GradeBook(std::string,std::string);
        void setCoursename(std::string);
        void setInstructorName(std::string);
        std::string getCoursename() const;
        std::string getInstructorname() const;
        void displayMessage() const;
    private:
        std::string courseName;
        std::string instructorName;
};