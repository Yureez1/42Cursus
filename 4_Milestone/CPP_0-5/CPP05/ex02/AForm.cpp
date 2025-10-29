/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:27:38 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/07 11:38:22 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, unsigned int signGrade, unsigned int execGrade, const std::string& target) : _name(name), _isSigned(false), _required_sign_grade(signGrade),_required_exec_grade(execGrade), _target(target) {
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

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _required_sign_grade(other._required_sign_grade), _required_exec_grade(other._required_exec_grade), _target(other._target) {
    if (_required_sign_grade < 1 || _required_exec_grade < 1)
        throw GradeTooHighException();
    if (_required_sign_grade > 150 || _required_exec_grade > 150)
        throw GradeTooLowException();
    std::cout << "Form Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm Destructor called" << std::endl;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSign() const {
    return _isSigned;
}

unsigned int AForm::getGradeToSign() const {
    return _required_sign_grade;
}

unsigned int AForm::getGradeToExec() const {
    return _required_exec_grade;
}

const std::string& AForm::getTarget() const {
    return _target;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (_isSigned)
        throw AlreadySignedException();
    if (b.getGrade() > _required_sign_grade)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const {
    if (!_isSigned) {
        throw NotSignedException();
    }
    if (executor.getGrade() > _required_exec_grade) {
        throw GradeTooLowException();
    }
    doExecute();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Not signed";
}

const char* AForm::FileOpenException::what() const throw() {
    return "File opened";
}

const char* AForm::AlreadySignedException::what() const throw() {
    return "Already signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << f.getName() << ", signed: " << f.getSign()
    << ", grade to sign: " << f.getGradeToSign()
    << ", grade to execute: " << f.getGradeToExec();
    return out;
}
