// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef HOURLY_H
#define HOURLY_H

#include "employee.h"
#include "../ssn/ssn.h"

class HourlyEmployee : public Employee {
public:
    HourlyEmployee(const std::string &, const std::string &,const SSN &,
                   int = 0, int = 0);

    int getWage() const;

    int getHours() const;

    virtual int payment() const;
    virtual void print() const;

private:
    int wageRate;
    int hoursWorked;

protected:
    bool invariant() const;
}; // class HourlyEmployee

#endif
