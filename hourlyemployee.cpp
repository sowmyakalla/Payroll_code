// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <hourlyemployee.h>
#include <assertexcept.h>
using std::cout;

bool HourlyEmployee::invariant() const {
    BOOST_ASSERT(Employee::invariant());
    BOOST_ASSERT_MSG(!(wageRate<0), "Wage Rate should not be negative");
    BOOST_ASSERT_MSG(!(hoursWorked<0), "Number of hours worked should not be negative");
    return true;
}

HourlyEmployee::HourlyEmployee(const std::string &firstname, const std::string &lastname,
                               const SSN &ssn, int wageHourly, int workedHourly):
        Employee(firstname,lastname,ssn),wageRate(wageHourly),hoursWorked(workedHourly)

{
    // preconditions;
    BOOST_ASSERT_MSG(!(wageHourly<0), "Wage Rate should not be negative");
    BOOST_ASSERT_MSG(!(workedHourly<0), "Number of hours worked should not be negative");

    //postconditions
    BOOST_ASSERT_MSG(wageRate == wageHourly, "Wage Rate should not be negative");
    BOOST_ASSERT_MSG(hoursWorked == workedHourly, "Number of hours worked should not be negative");

    //invariant
    BOOST_ASSERT(invariant());

    wageRate = (wageHourly < 0 ? 0 : wageHourly);
    hoursWorked = (((workedHourly >= 0 ) && (workedHourly <= 168)) ? workedHourly : 0);
}

int HourlyEmployee::getWage() const {
    return wageRate;
}

int HourlyEmployee::getHours() const {
    return hoursWorked;
}

int HourlyEmployee::payment() const {
    return getWage() * getHours();
}

void HourlyEmployee::print() const {
    std::cout<< "Hourly employee: ";
    Employee::print();
    std::cout<< " hourly wage: "<< getWage()<<"; hours worked: "<<getHours();
}