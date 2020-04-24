// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <fstream>
#include <employee.h>
#include <hourlyemployee.h>
#include <salariedemployee.h>
#include <assertexcept.h>
#include "../ssn/ssn.h"

using std::cout;
using std::endl;
using std::fixed;
using std::vector;

void virtualPointer(const Employee* const);

int main() {
    try {

        std::vector<Employee *> payroll;
        std::ifstream Display_Names;
        Display_Names.open("payroll.csv");
        if(!Display_Names.is_open()){
            cout<<"could not open file"<< endl;
            return 1;
        }
        std::string firstname;
        std::string lastname;
        std::string ssn;
        std::string type;
        std::string wage;
        std::string wageHourly;
        std::string workedHourly;

        while(Display_Names.good()){
            getline(Display_Names,firstname,' ');
            getline(Display_Names,lastname,' ');
            getline(Display_Names,ssn,' ');
            getline(Display_Names,type, ' ');
            if(type=="salaried")
            {
                getline(Display_Names,wage,'\n');
            }
            else{
                getline(Display_Names,wageHourly,' ');
                getline(Display_Names,workedHourly,'\n');
            }

            int monthlyWage = atof(wage.c_str());
            int wageRate = atof(wageHourly.c_str());
            int hoursWorked = atof(workedHourly.c_str());

            SalariedEmployee *salariedEmployee = new SalariedEmployee(firstname, lastname, SSN(ssn), monthlyWage);
            HourlyEmployee *hourlyEmployee = new HourlyEmployee(firstname, lastname, SSN(ssn), wageRate, hoursWorked);


        vector <Employee *> employees;
        employees.push_back(salariedEmployee);
        employees.push_back(hourlyEmployee);

            if(type=="salaried"){
                salariedEmployee->print();
                cout<< '\n';
                cout<<"Monthly Wages: $"<< salariedEmployee->payment()<<'\n';
            }
            else{  hourlyEmployee->print();
                cout<< '\n';
                cout<<"Monthly Wages: $"<< hourlyEmployee->payment()<<'\n';}
        }
        Display_Names.close();
        return 0;


    }
        catch (AssertException& e) {
            std::cerr << "Assertion Exception caught: " << e.what() << '\n';
            return EXIT_FAILURE;
        }
        catch (std::runtime_error& e) {
            std::cerr << "Standard exception caught: " << e.what() << '\n';
            return EXIT_FAILURE;
        }
        catch (...) {
            std::cerr << "Unknown exception caught\n";
            return EXIT_FAILURE;
        }

}