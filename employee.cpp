#include"employee.h" //employee class definition
#include <assertexcept.h>

bool Employee::invariant() const {
    BOOST_ASSERT_MSG(!(first.empty()), "First name should not be null");
    BOOST_ASSERT_MSG(!(last.empty()), "Last name should not be null");
    return true;
}
//constructor
Employee::Employee(const std::string &firstname, const std::string &lastname,
                   const SSN &ssn) : first(firstname), last(lastname), m_ssn(ssn)
{
       // preconditions;
        BOOST_ASSERT_MSG(!firstname.empty(), "First name should not be null");
        BOOST_ASSERT_MSG(!lastname.empty(), "Last name should not be null");
        //BOOST_ASSERT_MSG(std::all_of(firstname.begin(), firstname.end(), isspace), "Name not only white space");

        //postconditions;
        BOOST_ASSERT_MSG(first == firstname, "Fist name should not be NULL");
        BOOST_ASSERT_MSG(last == lastname, "List name should not be NULL");
        BOOST_ASSERT_MSG(m_ssn == ssn, "SSN stored");

        //invariant
        BOOST_ASSERT(invariant());
}

void Employee::print() const {
    std:: cout<< first<<' '<<last;
}
