#include <iostream>
#include <vector>
#include <memory>

struct STUDENT {
    std::string name;
    int age;
};

std::unique_ptr<STUDENT> createStudent (std::string name, int age) {
    auto student = std::unique_ptr<STUDENT> (new STUDENT());
    student->name = name;
    student->age = age;

    return student;
}

void printStudentInfo(const STUDENT& student){
    std::cout << student.name << " " << student.age << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector<std::unique_ptr<STUDENT>> vec;
    for(int i=0; i<size; i++){
        std::string name;
        int age;
        std::cin >> name >> age;
        auto student = createStudent(name, age);
        vec.push_back(std::move(student));//unique_ptr이라서 그냥 push back을 하면 값이 복사기 되기 때문에
                                        //하면 안되고 move를 이용하여 소유권을 이전해야 한다
                                        //그럼 여기서 student는 어떻게 되지? 그냥 껍데기만 남나
    }
//    for(int i=0; i<size; i++){
//        printStudentInfo(*vec[i]);
//    }
    for(auto &it: vec){
        printStudentInfo(*it);
    }
}