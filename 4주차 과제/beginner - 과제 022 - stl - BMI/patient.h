#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

 struct Patient {
    std::string name;
    int age;
    double weight;
    double height;
    double BMI;
};

void sort_patient(std::vector<std::unique_ptr<Patient>>& patients);

void print_patient(const std::unique_ptr<Patient>& patient);

void print_all_patient(std::vector<std::unique_ptr<Patient>>& patients);

void add_patient(std::vector<std::unique_ptr<Patient>>& patients);

void search_patient(std::vector<std::unique_ptr<Patient>>& patients);

void print_threshold_patient(std::vector<std::unique_ptr<Patient>>& patients);

void remove_threshold_patient(std::vector<std::unique_ptr<Patient>>& patients);


