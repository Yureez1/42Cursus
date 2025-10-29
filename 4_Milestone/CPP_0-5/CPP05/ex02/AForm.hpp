/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:27:35 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/07 11:41:21 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {

private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _required_sign_grade;
    const unsigned int _required_exec_grade;
    std::string _target;

protected:
    virtual void doExecute() const = 0;

    public:
    AForm(const std::string& name, unsigned int signGrade, unsigned int execGrade, const std::string& target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getSign() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExec() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& b);
    void execute(Bureaucrat const& executor) const;

    class GradeTooHighException : public std::exception {

    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {

    public:
        virtual const char* what() const throw();
    };

    class NotSignedException : public std::exception {

    public:
        virtual const char* what() const throw();
    };

    class FileOpenException : public std::exception {

    public:
        virtual const char* what() const throw();
    };

    class AlreadySignedException : public std::exception {

    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
