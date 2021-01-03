#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Prerequisties;

struct Period
{
    int start_hour;
    int start_minute;
    int finish_hour;
    int finish_minute;
};

struct Schedule
{
    vector<Period> period;
    vector<string> days;
};

struct Course
{
    int id;
    string name;
    int units;
    Schedule schedule;
    Prerequisties prerequisties;
};

typedef vector<Course> CourseTable;

struct Grade
{
    int id;
    double mark;
};

typedef vector<Grade> GradeTable;

CourseTable read_course_file(char *argv[]);
GradeTable read_grade_file(char *argv[]);
Grade assign_grade_table(vector<string> &all_grade_info);
Course assign_course_table(vector<string> &all_course_info);
void assign_course_schedule(string &schedule_string, Course &course);
CourseTable check_id_mark(CourseTable &course_table, GradeTable &grade_table, vector<int> &passed_courses);
CourseTable check_prerequisties(CourseTable &id_checked_courses, vector<int> &passed_courses);
CourseTable takable_courses(CourseTable &course_table, GradeTable &grade_table);
bool compare(Course a, Course b);
void write_course_file(CourseTable &all_checked_courses);


int main(int argc, char *argv[])
{
    CourseTable course_table;
    CourseTable all_checked_courses;
    GradeTable grade_table;
    course_table = read_course_file(argv);
    grade_table = read_grade_file(argv);
    all_checked_courses = takable_courses(course_table, grade_table);

    write_course_file(all_checked_courses);

    return 0;
}



CourseTable read_course_file(char *argv[])
{
    string line;
    string word;
    vector<string> all_course_info;
    Course course;
    CourseTable course_table;

    ifstream CourseFile(argv[1]);
    if(CourseFile.fail())
    {
        cout << "CourseFile Does not Open" << endl;
        exit(1);
    }
    getline(CourseFile, line);
    while (getline(CourseFile, line))
    {

        stringstream s(line);
        while (getline(s, word, ','))
        {
          all_course_info.push_back(word);
        }

        course = assign_course_table(all_course_info);
        course_table.push_back(course);
        all_course_info.clear();
    }
    return course_table;
};

Course assign_course_table(vector<string> &all_course_info)
{

    string request_course_string;
    string schedule_string;
    Course course;

    course.id = stoi(all_course_info[0]);
    course.name = all_course_info[1];
    course.units = stoi(all_course_info[2]);
    stringstream s(all_course_info[4]);
    while (getline(s, request_course_string, '-'))
    {
        course.prerequisties.push_back(stoi(request_course_string));
    }

    stringstream ss(all_course_info[3]);
    while (getline(ss, schedule_string, '/'))
    {
        assign_course_schedule(schedule_string, course);
    }

    return course;
}

void assign_course_schedule(string &schedule_string, Course &course)
{
    vector<string> start_time;
    vector<string> finish_time;
    vector<string> each_time_or_day;
    string times_and_days;
    string time1;
    string time2;
    Period period;

    stringstream sss(schedule_string);
    while (getline(sss, times_and_days, '-'))
    {
        each_time_or_day.push_back(times_and_days);
    }
    course.schedule.days.push_back(each_time_or_day[0]);

    stringstream w(each_time_or_day[1]);
    while (getline(w, time1, ':'))
    {
        start_time.push_back(time1);
    }

    stringstream a(each_time_or_day[2]);
    while (getline(a, time2, ':'))
    {
        finish_time.push_back(time2);
    }

    for (int i = 0; i < start_time.size(); i = i + 2)
    {

        period.start_hour = stoi(start_time[i]);
        period.start_minute = stoi(start_time[i + 1]);
        period.finish_hour = stoi(finish_time[i]);
        period.finish_minute = stoi(finish_time[i + 1]);

        course.schedule.period.push_back(period);
    }
    time1.clear();
    time2.clear();
}

GradeTable read_grade_file(char *argv[])
{
    string line;
    string word;
    vector<string> all_grade_info;
    Grade grade;
    GradeTable grade_table;

    ifstream GradeFile(argv[2]);
    if(GradeFile.fail())
    {
        cout << "GradeFile Does not Open" << endl;
        exit(1);
    }
    getline(GradeFile, line);
    while (getline(GradeFile, line))
    {

        stringstream s(line);
        while (getline(s, word, ','))
        {
            all_grade_info.push_back(word);
        }

        grade = assign_grade_table(all_grade_info);
        all_grade_info.clear();
        grade_table.push_back(grade);
    }

    return grade_table;

}

Grade assign_grade_table(vector<string> &all_grade_info)
{
    Grade grade;

    grade.id = stoi(all_grade_info[0]);
    grade.mark = stod(all_grade_info[1]);
    return grade;
}

CourseTable check_id_mark(CourseTable &course_table, GradeTable &grade_table, vector<int> &passed_courses)
{

    CourseTable id_checked_courses;

    vector<int> passed_id;
    int check = 0;
    for(int i=0 ; i < course_table.size() ; i++)
    {
        check = 0;
        for(int j=0 ; j < grade_table.size() ; j++)
        {
            if((course_table[i].id == grade_table[j].id) && (grade_table[j].mark >= 10))
            {
               check = 1;
                passed_courses.push_back(course_table[i].id);
            }
        }
        if(check == 0)
        {
            id_checked_courses.push_back(course_table[i]);
        }

    }
    return id_checked_courses;
}

CourseTable check_prerequisties(CourseTable &id_checked_courses, vector<int> &passed_courses)
{
    CourseTable prerequisties_checked_courses;
    int number_prerequisties = 0;
    for (int i = 0 ; i < id_checked_courses.size() ; i++)
    {
        number_prerequisties = 0;
        for(int j = 0 ; j < id_checked_courses[i].prerequisties.size() ; j++)
        {
            if(find(passed_courses.begin(), passed_courses.end(), id_checked_courses[i].prerequisties[j]) != passed_courses.end())
                number_prerequisties = number_prerequisties + 1;
        }
        if(id_checked_courses[i].prerequisties[0] == 0)
        {
            prerequisties_checked_courses.push_back(id_checked_courses[i]);
        }
        else if (id_checked_courses[i].prerequisties.size() ==  number_prerequisties)
        {
            prerequisties_checked_courses.push_back(id_checked_courses[i]);
        }
    }
    return prerequisties_checked_courses;

}

CourseTable takable_courses(CourseTable &course_table, GradeTable &grade_table)
{
    vector<int> passed_courses;
    CourseTable id_checked_courses;
    CourseTable all_checked_courses;

    id_checked_courses = check_id_mark(course_table, grade_table, passed_courses);
    all_checked_courses = check_prerequisties(id_checked_courses, passed_courses);
    return all_checked_courses;
}

bool compare(Course a, Course b)
{
    int size = 0;
    if(a.name.size() < b.name.size())
        size = a.name.size();
    else
        size = b.name.size();
    for(int i=0 ; i < size ; i++)
    {
        if (a.name[i] == b.name[i])
            continue;
        else
            return (a.name[i] < b.name[i]);
    }
    return (a.name.size() < b.name.size());
}

void write_course_file(CourseTable &all_checked_courses)
{
    sort(all_checked_courses.begin(), all_checked_courses.end(), compare);

    ofstream OutputFile("output_file.txt");
    if(OutputFile.fail())
    {
        cout << "OutputFile Does not Open" << endl;
        return;
    }
    for(int i =0 ; i < all_checked_courses.size() ; i++)
    {
        OutputFile << all_checked_courses[i].id << endl;
    }

}
