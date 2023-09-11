#include "Organization.h"

int main() {
    // Create the organization
    std::shared_ptr<IOrganization> org = std::make_shared<Organization>("PNU-CSE");

    // Create departments
    auto design = std::make_shared<Department>("Design");
    auto dev = std::make_shared<Department>("Development");
    auto qa = std::make_shared<Department>("QA");

    // Create managers
    auto lee = std::make_shared<Manager>("Lee", 8'000'000);
    auto park = std::make_shared<Manager>("Park", 9'000'000);
    auto bae = std::make_shared<Manager>("Bae", 5'000'000);

    // Add departments to the organization
    org->addDept(design);
    org->addDept(dev);
    org->addDept(qa);

    // Set managers for the departments
    org->setDeptManager(design, lee);
    org->setDeptManager(dev, park);
    org->setDeptManager(qa, bae);

    // Create employees
    auto kim = std::make_shared<Employee>("Kim", 4'000'000);
    auto go = std::make_shared<Employee>("Go", 8'000'000);
    auto jeon = std::make_shared<Employee>("Jeon", 5'000'000);
    auto yoon = std::make_shared<Employee>("Yoon", 3'000'000);

    // Add employees to the departments
    org->addEmpToDept(design, kim);
    org->addEmpToDept(dev, go);
    org->addEmpToDept(dev, jeon);
    org->addEmpToDept(qa, yoon);

    // Print the organization
    org->print();

    // Move an employee to a different department
    org->moveEmp(dev, qa, jeon);

    // Print the updated organization
    org->print();
    return 0;
}