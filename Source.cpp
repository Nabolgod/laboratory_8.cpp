#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct Student {
    string name;
    string lastname;
    string fathername;
    string faculty;

    void creat_person() {
        const size_t size = 10;
        string names[size] = { "Andrey", "Danil", "Vlad", "Roman", "Nikita", "Kirill", "Yra", "Jeniya", "Ilya", "Marat" };
        string lastnames[size] = { "Troshin", "Lobanov", "Kolchin", "Soldatov", "Vinogradov", "Jelonkin", "Safronov", "Usmankin", "Basharov", "Polyakov" };
        string fathernames[size] = { "Alekseevich", "Dmitrievich", "Ilych", "Petrovich", "Maksimovich", "Matveevich", "Michalych", "Renatovich", "Romanovich", "Valerevich" };
        string facultys[size] = { "MI", "FMF", "EEF", "ATI", "FFCSaT", "IENaF", "PPF", "FIA", "HFF", "EF" };

        name = names[rand() % 10];
        lastname = lastnames[rand() % 10];
        fathername = fathernames[rand() % 10];
        faculty = facultys[rand() % 10];
    }

    void print_person() {
        cout << "FIO: " << lastname << " " << name << " " << fathername << endl;
        cout << "Faculty: " << faculty << "\n\n";
    }
};

void filling_array(Student* s, size_t size) {
    for (int i = 0; i < size; i++) {
        s[i].creat_person();
    }
}

void print_array(Student* s, size_t size) {
    for (int i = 0; i < size; i++) {
        s[i].print_person();
    }
}

void find_top_faculties(Student* students, size_t size) {
    const size_t faculty_count = 10; 
    int counts[faculty_count] = { 0 }; 
    string faculties[faculty_count] = { "MI","FMF","EEF","ATI","FFCSaT","IENaF","PPF","FIA","HFF","EF" };

    for (size_t i = 0; i < size; ++i) {
        for (int j = 0; j < faculty_count; ++j) {
            if (students[i].faculty == faculties[j]) {
                counts[j]++;
                break;
            }
        }
    }

    int first_max_index = -1, second_max_index = -1;

    for (int i = 0; i < faculty_count; ++i) {
        if (first_max_index == -1 || counts[i] >= counts[first_max_index]) {
            second_max_index = first_max_index;
            first_max_index = i;
        }
    }

    if (counts[first_max_index] == counts[second_max_index]) {
        cout << "Самого популярного факультета нет" << endl;
    }
    else {
        cout << "Самый популярный факультет: " << faculties[first_max_index] << ", количество: " << counts[first_max_index] << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    int MAXSIZE;
    cout << "Введите кол-во студентов: ";
    cin >> MAXSIZE;
    if (MAXSIZE <= 0) {
        cout << "Студентов нет";
        return 1;
    }
    else {
        Student* students = new Student[MAXSIZE];
        filling_array(students, MAXSIZE);
        print_array(students, MAXSIZE);

        if (MAXSIZE == 1) {
            cout << "Самый популярный факультет: " << students[0].faculty << ", количество: 1" << endl;
        }
        else
            find_top_faculties(students, MAXSIZE);

        delete[] students;
        students = nullptr;
    }
    
    return 0;
}
