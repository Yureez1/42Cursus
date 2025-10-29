/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:43:24 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/25 14:29:09 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     delete i;
//     delete j;
//     delete meta;
//     return 0;
// }

int main() {
    std::cout << "=====CONSTRUCTORS TESTS=====" << std::endl;
    std::cout << std::endl;
    
    const Animal* Generic = new Animal();
    const Animal* Dogi = new Dog();
    const Animal* Cati = new Cat();
    const WrongAnimal* Wrong1 = new WrongAnimal();
    const WrongCat* WrongCat1 = new WrongCat();
    std::cout << std::endl;
    
    std::cout << "=====BASIC TESTS=====" << std::endl;
    std::cout << std::endl;  
    // Get type of Animal via Getter
    
    std::cout << "Type of Animal: " << Generic->getType() << std::endl; 
    std::cout << "Type of Animal: " << Dogi->getType() << std::endl;
    std::cout << "Type of Animal: " << Cati->getType() << std::endl;
    std::cout << "Type of Animal: " << Wrong1->getType() << std::endl;
    std::cout << "Type of Animal: " << WrongCat1->getType() << std::endl;
    std::cout << std::endl;

    // makeSound deverie de la classe Animal
    std::cout << "Sound of Generic : " << std::endl;
    Generic->makeSound();
    std::cout << std::endl;

    std::cout << "Sound of Dog : " << std::endl;
    Dogi->makeSound();
    std::cout << std::endl;
    
    std::cout << "Sound of Cat : " << std::endl;
    Cati->makeSound();
    std::cout << std::endl;

    std::cout << "Sound of WrongAnimal : " << std::endl;
    Wrong1->makeSound();
    std::cout << std::endl;

    // makeSound deverie de la classe WrongAnimal
    std::cout << "Sound of WrongCat : " << std::endl;
    WrongCat1->makeSound();
    std::cout << std::endl;
    
    std::cout << "=====TESTS CTOR COPY OPERATOR ANIMAL=====" << std::endl;
    std::cout << std::endl;
    // Animal CTOR/COPY/OPERATOR
    
    const Animal* AnimalOperator;
    const Animal* AnimalCtor = new Animal("AnimalCtor");
    const Animal* AnimalCopy(AnimalCtor);
    std::cout << std::endl;

    std::cout << "Sound of Animal Ctor: " << std::endl;
    AnimalCtor->makeSound();
    std::cout << std::endl;
    
    std::cout << "Sound of Animal Copy" << std::endl;
    AnimalCopy->makeSound();
    std::cout << std::endl;
    
    AnimalOperator = Generic;
    std::cout << "Sound of Animal Operator: " << std::endl;
    AnimalOperator->makeSound();
    std::cout << std::endl;
    
    std::cout << "=====TESTS CTOR COPY OPERATOR DOG=====" << std::endl;
    std::cout << std::endl;
    // DOG CTOR/COPY/OPERATOR
    
    const Animal* DogOperator;
    const Animal* DogCtor = new Dog("DogCtor");
    const Animal* DogCopy(DogCtor);
    std::cout << std::endl;
    
    std::cout << "Sound of Dog Ctor: " << std::endl;
    DogCtor->makeSound();
    std::cout << std::endl;
    
    std::cout << "Sound of Dog Copy" << std::endl;
    DogCopy->makeSound();
    std::cout << std::endl;
    
    DogOperator = Dogi;
    std::cout << "Sound of Dog Operator: " << std::endl;
    DogOperator->makeSound();
    std::cout << std::endl;

    std::cout << "=====TESTS CTOR COPY OPERATOR CAT=====" << std::endl;
    std::cout << std::endl;
    // CAT CTOR/COPY/OPERATOR

    const Animal* CatOperator;
    const Animal* CatCtor = new Cat("CatCtor");
    const Animal* CatCopy(CatCtor);
    std::cout << std::endl;
    
    std::cout << "Sound of Cat Ctor: " << std::endl;
    CatCtor->makeSound();
    std::cout << std::endl;
    
    std::cout << "Sound of Cat Copy" << std::endl;
    CatCopy->makeSound();
    std::cout << std::endl;
    
    CatOperator = Cati;
    std::cout << "Sound of Cat Operator: " << std::endl;
    CatOperator->makeSound();
    std::cout << std::endl;

    std::cout << "=====TESTS CTOR COPY OPERATOR WRONGANIMAL=====" << std::endl;
    std::cout << std::endl;
    // WRONGANIMAL CTOR/COPY/OPERATOR

    const WrongAnimal* WrongOperator;
    const WrongAnimal* WrongCtor = new WrongAnimal("WrongCtor");
    const WrongAnimal* WrongCopy(WrongCtor);
    std::cout << std::endl;
    
    std::cout << "Sound of WrongCtor: " << std::endl;
    WrongCtor->makeSound();
    std::cout << std::endl;
    
    std::cout << "Sound of WrongCopy" << std::endl;
    WrongCopy->makeSound();
    std::cout << std::endl;
    
    WrongOperator = Wrong1;
    std::cout << "Sound of WrongOperator: " << std::endl;
    WrongOperator->makeSound();
    std::cout << std::endl;

    std::cout << "=====TESTS CTOR COPY OPERATOR WRONGCAT=====" << std::endl;
    std::cout << std::endl;
    // WRONGCAT CTOR/COPY/OPERATOR

    const WrongCat* WrongCatOperator;
    const WrongCat* WrongCatCtor = new WrongCat("WrongCatCtor");
    const WrongCat* WrongCatCopy(WrongCatCtor);
    std::cout << std::endl;
    
    std::cout << "Sound of WrongCatCtor: " << std::endl;
    WrongCatCtor->makeSound();
    std::cout << std::endl;
    
    std::cout << "Sound of WrongCatCopy" << std::endl;
    WrongCatCopy->makeSound();
    std::cout << std::endl;
    
    WrongCatOperator = WrongCat1;
    std::cout << "Sound of WrongCatOperator: " << std::endl;
    WrongCatOperator->makeSound();
    std::cout << std::endl;
    
    std::cout << "=====TESTS DESTRUCTORS=====" << std::endl;
    delete WrongCtor;
    delete WrongCatCtor;
    delete CatCtor;
    delete DogCtor;
    delete AnimalCtor;
    delete Wrong1;
    delete WrongCat1;
    delete Cati;
    delete Dogi;
    delete Generic;

    WrongAnimal* Lecat = new WrongCat();
    Lecat->makeSound();
    delete Lecat;
    return 0;
}