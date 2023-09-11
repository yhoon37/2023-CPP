#include "Student.h"
#include <vector>
#include <algorithm>

int main() {
    std::vector<Student> students {{"Kim", GRADE(1)}, {"Kim", GRADE(2)}, {"Lee", GRADE(2)}, {"Choi", GRADE(3)}, {"Choi", GRADE(4)}, {"Park", GRADE(2)}, {"Hwang", GRADE(4)}};
    std::sort(std::begin(students), std::end(students), Student::Compare());

    for (auto& s: students)
        std::cout << s << std::endl;
}