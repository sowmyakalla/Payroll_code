// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "salariedemployee.h"

#include <assertexcept.h>

#include "../ssn/ssn.h"
using std::cout;

bool SalariedEmployee::invariant() const {
    BOOST_ASSERT(Employee::invariant());
    BOOST_ASSERT_MSG(!(monthlyWage < 0), "Salary should not be negative");
    return true;
}

SalariedEmployee :: SalariedEmployee(const std::string &firstname, const std::string &lastname,
                                  const SSN &ssn, int wage): Employee(firstname,lastname,ssn),monthlyWage(wage)
{
    // preconditions;
    BOOST_ASSERT_MSG(!(wage < 0), "Salary should not be negative");

    //postconditions
    BOOST_ASSERT_MSG(monthlyWage == wage, "Salary should not be negative");

    //invariant
    BOOST_ASSERT(invariant());
    //setMonthlyWage(wage);
    monthlyWage = (wage < 0) ? 0 : wage;
}

int  SalariedEmployee:: getMonthlyWage() const {
    return monthlyWage;
}

int SalariedEmployee::payment() const{
    return getMonthlyWage();
}

void SalariedEmployee::print() const {
    std::cout<<"Salaried Employee: ";
    Employee::print();
    std::cout<<"Monthly Wage: " << getMonthlyWage();
}