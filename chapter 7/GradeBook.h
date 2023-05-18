#include <string>
#include <array>

class GradeBook{
    //define interfaces here
    public:
        static const size_t students=10;

        GradeBook(const std::string & ,const std::array<int,students> &);
        void setCoursename(const std::string &);
        std::string getCoursename() const;
        void displayMessage() const;
        int getMinimum() const;
        int getMaximum() const;
        double getAverage() const;
        void outputBarChart() const;
        void outputGrades() const;
    private:
        std::string courseName;
        std::array< int, students > grades;
};