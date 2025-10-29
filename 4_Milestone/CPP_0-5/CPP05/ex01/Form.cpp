/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:27:23 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/07 11:39:59 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, unsigned int signGrade, unsigned int execGrade) : _name(name), _isSigned(false), _required_sign_grade(signGrade), _required_exec_grade(execGrade) {
    if (_required_sign_grade < 1 || _required_exec_grade < 1)
        throw GradeTooHighException();
    if (_required_sign_grade > 150 || _required_exec_grade > 150)
        throw GradeTooLowException();
    std::cout << "Form default constructor called" << std::endl
    << "Name: " << _name << std::endl
    << "Signed: " << _isSigned << std::endl
    << "Sign Grade: " << _required_sign_grade << std::endl
    << "Exec Grade: " << _required_exec_grade << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _required_sign_grade(other._required_sign_grade), _required_exec_grade(other._required_exec_grade) {
    if (_required_sign_grade < 1 || _required_exec_grade < 1)
        throw GradeTooHighException();
    if (_required_sign_grade > 150 || _required_exec_grade > 150)
        throw GradeTooLowException();
    std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form Destructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat& b) {
    if (_isSigned)
        throw AlreadySignedException();
    if (b.getGrade() > _required_sign_grade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::string Form::getName() const {
    return _name;
}

bool Form::getSign() const {
    return _isSigned;
}

unsigned int Form::getGradeToExec() const {
    return _required_exec_grade;
}

unsigned int Form::getGradeToSign() const {
    return _required_sign_grade;
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade too low";
}

const char* Form::AlreadySignedException::what() const throw(){
    return "Form: Already signed";
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << f.getName() << ", signed: " << f.getSign()
    << ", grade to sign: " << f.getGradeToSign()
    << ", grade to execute: " << f.getGradeToExec();
    return out;
}
