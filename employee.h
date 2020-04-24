// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "../ssn/ssn.h"

class Employee {
public:
    Employee(const std::string &,const std::string &, const SSN &);

    virtual void print() const;

private:
    std::string first;
    std::string last;
    SSN m_ssn;
protected:
    bool invariant() const;
}; // class Employee

#endif // EMPLOYEE_H
