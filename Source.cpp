#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//template <typename M>
//void input(string text, M &value) {
//    cout << text;
//    cin >> value;
//}

struct Student {
    string name;
    string lastname;
    string fathername;
    string faculty;

    void creat_person() {
        const size_t size = 10;
        string names[size] = {"Andrey", "Danil", "Vlad", "Roman", "Nikita", "Kirill", "Yra", "Jeniya", "Ilya", "Marat"};
        string lastnames[size] = {"Troshin", "Lobanov", "Kolchin", "Soldatov", "Vinogradov", "Jelonkin", "Safronov", "Usmankin", "Basharov", "Polyakov"};
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

void filling_array(Student *s, size_t size) {
    for (int i = 0; i < size; i++) {
        s[i].creat_person();
    }
}

void print_array(Student* s, size_t size) {
    for (int i = 0; i < size; i++) {
        s[i].print_person();
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    size_t MAXSIZE;

    cout << "¬ведите кол-во студентов: ";
    cin >> MAXSIZE;

    Student* students = new Student[MAXSIZE];
    filling_array(students, MAXSIZE);
    print_array(students, MAXSIZE);
    
    delete[] students;
    students = nullptr;

    return 0;
}