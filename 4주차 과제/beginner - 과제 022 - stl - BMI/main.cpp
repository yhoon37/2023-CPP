#include "patient.h"
#include <iomanip>

int main() {
    std::vector<std::unique_ptr<Patient>> PatientInfo;
    int size;
    std::cin >> size;
    for(int i=0; i<size; i++){
        add_patient(PatientInfo);
    }

    std::cout << std::fixed << std::setprecision(2);
    sort_patient(PatientInfo);

    print_all_patient(PatientInfo);

    search_patient(PatientInfo);

    print_threshold_patient(PatientInfo);

    remove_threshold_patient(PatientInfo);

    print_all_patient(PatientInfo);

    return 0;
}
