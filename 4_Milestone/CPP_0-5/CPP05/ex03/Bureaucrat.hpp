/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:27:30 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/03 10:59:32 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

    private:
    const std::string _name;
    unsigned int _grade;
    
    public:
    Bureaucrat(const std::string& name, unsigned int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    
    std::string getName() const;
    unsigned int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    
    void signForm(AForm& form) const;
    void executeForm(AForm& form) const;
    
    class GradeTooHighException : public std::exception {
        
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
        
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif