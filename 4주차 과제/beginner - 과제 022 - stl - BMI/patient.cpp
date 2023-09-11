#include "patient.h"

bool sort_compare(std::unique_ptr<Patient>& a, std::unique_ptr<Patient>& b){
    return (a->BMI) > (b->BMI);
}

void sort_patient(std::vector<std::unique_ptr<Patient>>& patients){
    std::sort(patients.begin(), patients.end(), sort_compare);
}

void print_patient(const std::unique_ptr<Patient>& patient){
    std::cout << patient->name << " " << patient->age << " " << patient->weight << " " << patient->height << " " << patient->BMI << std::endl;
}

void print_all_patient(std::vector<std::unique_ptr<Patient>>& patients){
    std::cout << "Information for all patients:" << std::endl;
    for(const auto& patient: patients){
        print_patient(patient);
    }
}

void add_patient(std::vector<std::unique_ptr<Patient>>& patients){
    std::unique_ptr<Patient> patient (new Patient());
    std::string name;
    int age, weight;
    double height, BMI;
    std::cin >> name >> age >> weight >> height;
    BMI = weight/(height*height);
    patient->name = name;
    patient->age = age;
    patient->weight = weight;
    patient->height = height;
    patient->BMI = BMI;
    patients.push_back(std::move(patient));
}

void search_patient(std::vector<std::unique_ptr<Patient>>& patients){
    std::string search_name;
    std::cout << "Enter the name: ";
    std::cin >> search_name;
    auto find_patient = std::find_if(patients.begin(), patients.end(),
                                     [search_name](auto& patient){return patient->name == search_name;});
    if(find_patient != patients.end()){
        std::cout << "Patient found:\n";
        print_patient(*find_patient);   //const가 어디있는거지??
    }
}

void print_threshold_patient(std::vector<std::unique_ptr<Patient>>& patients){
    double threshold;
    std::cout << "Enter the BMI threshold:";
    std::cin >> threshold;
    std::cout << "Patients with BMI more than " << threshold << ":" << std::endl;
    std::for_each(patients.begin(), patients.end(),
                  [threshold](auto& patient){if(patient->BMI > threshold){
                      print_patient(patient);}}); //여기서도 const는 어디있을까
}

void remove_threshold_patient(std::vector<std::unique_ptr<Patient>>& patients){
    double threshold;
    std::cout << "Enter the BMI threshold:";
    std::cin >> threshold;
    patients.erase(std::remove_if(patients.begin(), patients.end(),
                                  [threshold](auto& patient){return patient->BMI < threshold;}), patients.end());
}
