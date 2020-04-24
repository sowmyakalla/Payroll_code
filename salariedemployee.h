// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef SALARIED_H
#define SALARIED_H
#include <string>
#include "employee.h"

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(const std::string &, const std::string &, const SSN &, int = 0);

    int getMonthlyWage() const;

    virtual int payment() const;
    virtual void print() const;

private:
    double monthlyWage;

protected:
    bool invariant() const;
};

#endif
