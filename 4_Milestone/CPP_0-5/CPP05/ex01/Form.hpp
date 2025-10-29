/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:27:25 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/07 11:39:00 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form {

private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _required_sign_grade;
    const unsigned int _required_exec_grade;

public:
    Form(const std::string& name, unsigned int signGrade, unsigned int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    void beSigned(const Bureaucrat& b);

    std::string getName() const;
    bool getSign() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExec() const;


    class GradeTooHighException : public std::exception {

    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {

    public:
        virtual const char* what() const throw();
    };

    class AlreadySignedException : public std::exception {

    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
