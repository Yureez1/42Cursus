/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:55:26 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/24 16:59:59 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria {

protected:
    std::string _type;
    
public:

    AMateria();
    AMateria(std::string const& type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    ~AMateria()
    
    std::string const& getType() const;
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};


#endif
