#include "doctest.h"
#include "Person.hpp"
#include "Professor.hpp"
#include "TeachingAssistant.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace university;

TEST_CASE("Regular course")
{
    Course cpp("C++", 2, 2, 3);
    Professor prof1(cpp, "John", "Doe", "1234567890");
    Professor prof2(cpp, "Jane", "Doe", "1234567890");
    TeachingAssistant ta1(cpp, "Tom", "Doe", "1234567890");
    TeachingAssistant ta2(cpp, "Tim", "Doe", "1234567890");
    Student s1(cpp, "Sue", "Doe", "1234567890", 3.5);
    Student s2(cpp, "Sam", "Doe", "1234567890", 3.5);
    Student s3(cpp, "Sally", "Doe", "1234567890", 3.5);

    prof1.teach();
    prof2.teach();
    ta1.publishAssignment();
    s1.doHomework();
    s2.doHomework();
    s3.doHomework();
    ta2.giveGrade(s1, 85);
    ta2.giveGrade(s2, 90);
    ta2.giveGrade(s3, 95);
    CHECK(ta2.publishGrades() == "Sue: 85\nSam: 90\nSally: 95\n");
    prof1.publishTest();
    s1.takeTest();
    s2.takeTest();
    s3.takeTest();
    prof2.gradeTest(s1, 85);
    prof2.gradeTest(s2, 90);
    prof2.gradeTest(s3, 95);
    CHECK_NO_THROWS(prof1.finishCourse());
}
TEST_CASE("Invalid operations")
{
    Course cpp("C++", 2, 2, 3);
    Professor prof1(cpp, "John", "Doe", "1234567890");
    Professor prof2(cpp, "Jane", "Doe", "1234567890");
    TeachingAssistant ta1(cpp, "Tom", "Doe", "1234567890");
    TeachingAssistant ta2(cpp, "Tim", "Doe", "1234567890");
    Student s1(cpp, "Sue", "Doe", "1234567890", 3.5);
    Student s2(cpp, "Sam", "Doe", "1234567890", 3.5);
    Student s3(cpp, "Sally", "Doe", "1234567890", 3.5);
    CHECK_THROWS(Professor prof3(cpp, "John", "Doe", "1234567890"));
    CHECK_THROWS(ta2.publishAssignment());
    prof1.teach();
    CHECK_THROWS(s1.doHomework());
    CHECK_THROWS_AS(prof1.publishTest());
    prof2.teach();
    prof1.publishTest();
    s1.takeTest();
    s2.takeTest();
    CHECK_THROWS(prof2.gradeTest(s1, 85));
    s3.takeTest();
    prof1.gradeTest(s1, 85);
    prof1.gradeTest(s2, 90);
    prof1.gradeTest(s3, 50);
    CHECK_THROWS(prof1.finishCourse());
}