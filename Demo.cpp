

#include "Person.hpp"
#include "Professor.hpp"
#include "TeachingAssistant.hpp"
#include "Student.hpp"
#include "Course.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace university;

int main()
{
    Course cpp("C++", 2, 2, 3);
    Professor prof1(cpp, "John", "Doe", "1234567890");
    Professor prof2(cpp, "Jane", "Doe", "1234567890");
    TeachingAssistant ta1(cpp, "Tom", "Doe", "1234567890");
    TeachingAssistant ta2(cpp, "Tim", "Doe", "1234567890");
    Student s1(cpp, "Sue", "Doe", "1234567890", 3.5);
    Student s2(cpp, "Sam", "Doe", "1234567890", 3.5);
    Student s3(cpp, "Sally", "Doe", "1234567890", 3.5);

    try
    {
        Professor prof3(cpp, "John", "Doe", "1234567890");
    }
    catch (exception &e)
    {
        cout << e.what() << endl; // Only 2 professors allowed in cpp course.
    }
    prof1.teach();
    prof2.teach();

    ta1.publishAssignment();
    try
    {
        ta2.publishAssignment();
    }
    catch (exception &e)
    {
        cout << e.what() << endl; // Only 1 TA allowed to publish assignment at a time.
    }
    s1.doHomework();
    try
    {
        s1.doHomework();
    }
    catch (exception &e)
    {
        cout << e.what() << endl; // Student has already done homework.
    }
    s2.doHomework();
    s3.doHomework();
    ta2.giveGrade(s1, 85);
    ta2.giveGrade(s2, 90);
    ta2.giveGrade(s3, 95);
    ta2.publishGrades(); // should print for example: "Sue: 85, Sam: 90, Sally: 95".

    prof1.publishTest();
    s1.takeTest();
    s2.takeTest();
    s3.takeTest();
    prof1.gradeTest(s1, 85);
    s1.appealGrade();
    prof1.updateGrade(s1, 90);
    prof1.gradeTest(s2, 90);
    prof1.gradeTest(s3, 50);
    prof1.publishGrades(); // should print for example: "Sue: 85, Sam: 90, Sally: 50".
    try
    {
        prof1.finishCourse();
    }
    catch (exception &e)
    {
        cout << e.what() << endl; // Not all students have passed the test.
    }
    prof2.publishTest();
    s1.takeTest();
    s2.takeTest();
    s3.takeTest();
    prof2.gradeTest(s1, 85);
    prof2.gradeTest(s2, 90);
    prof2.gradeTest(s3, 95);
    prof2.publishGrades(); // should print for example: "Sue: 85, Sam: 90, Sally: 95".
    prof1.finishCourse();
    return 0;
}