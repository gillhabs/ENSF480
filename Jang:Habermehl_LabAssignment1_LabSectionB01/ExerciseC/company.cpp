/*
* File Name: company.cpp
* Assignment: Lab 1 Exercise C
* Completed by: Gillian Habermehl and Grace Jang
* Submission Date: Sept 18, 2023
*/


#include <string>
#include <vector>
using namespace std;


class Company;
class Address;

class Address {
private:
    int number;
    string street;
    string city;
    string province;
    string postalCode;
    
public:
    // ctor
    Address(int number, string street, string city, string province, string postalCode)
    : number(number), street(street), city(city), province(province), postalCode(postalCode) {}
    
    // copy ctor
    Address(const Address& source);
    
    // assignment operator
    Address& operator=(const Address& rhs);

    // dtor
    ~Address();
    
    // Getters
    int getNumber() const{
        return number;
    }
    
    string getStreet() const{
        return street;
    }
    
    string getCity() const{
        return city;
    }
    
    string getProvince() const{
        return province;
    }
    
    string getPostalCode() const{
        return postalCode;
    }
    
    // Setters
    void setNumber(int num) {
        number = num;
    }
    
    void setStreet(string str) {
        street = str;
    }
    
    void setCity(string c) {
        city = c;
    }
    
    void setProvince(string prov) {
        province = prov;
    }
    
    void setPostalCode(string post) {
        postalCode = post;
    }
};


class Company {
    
private:
    string companyName;
    string companyAddress;
    vector<string> employees;
    string dateEstablished;
    vector<string> employeeState;
    vector<string> customers;
    
public:
    // ctor
    Company(string name, string address, string date)
        : companyName(name), companyAddress(address), dateEstablished(date) {}

    // copy ctor
    Company(const Company& source);
    
    // assignment operator
    Company& operator =(const Company& rhs);

    // dtor
    ~Company();
    
    // Getters
    string getCompanyName() const {
        return companyName;
    }

    string getCompanyAddress() const {
        return companyAddress;
    }

    vector<string> getEmployees() const {
        return employees;
    }
    
    string getDateEstablished() const {
        return dateEstablished;
    }
    
    vector<string> getEmployeeState() const {
        return employeeState;
    }

    vector<string> getCustomers() const {
        return customers;
    }

    // Setters
    void setCompanyName(string name) {
        companyName = name;
    }
    
    void setCompanyAddress(string address) {
        companyAddress = address;
    }
    
    void setEmployees(vector<string>& employeeList) {
        employees = employeeList;
    }
    
    void setDateEstablished(string date) {
        dateEstablished = date;
    }
    
    void setEmployeeState(vector<string> state) {
        employeeState = state;
    }
    
    void setCustomers(vector<string> customerList) {
        customers = customerList;
    }
    
    // Adders for vector<string> types
    void addEmployee(string employee) {
        employees.push_back(employee);
    }

    void addEmployeeState(string state) {
        employeeState.push_back(state);
    }

    void addCustomer(string customer) {
        customers.push_back(customer);
    }
};
