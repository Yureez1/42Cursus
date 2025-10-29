/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:41:17 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/24 16:47:43 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {

    std::cout << "====== CREATING TAB HALF DOG HALF CAT TESTS ======" << std::endl;
    std::cout << std::endl;
    
    const int size = 10;
    AAnimal* farm[size];

    for (int i = 0; i < size; ++i){
        if (i < size/2) {
            farm[i] = new Dog();
        }
        else {
            farm[i] = new Cat();
        }
    }
    
    std::cout << std::endl;
    std::cout << "====== DOG AND CAT SETIDEA TESTS ======" << std::endl;

    Dog *dog = dynamic_cast<Dog*>(farm[0]);
    Dog *dog1 = dynamic_cast<Dog*>(farm[1]);
    Dog *DogPretendToBeCat = dynamic_cast<Dog*>(farm[8]);
    
    Cat *cat = dynamic_cast<Cat*>(farm[6]);
    Cat *cat1 = dynamic_cast<Cat*>(farm[7]);
    Cat *CatPretendtoBeDog = dynamic_cast<Cat*>(farm[4]);
    
    std::cout << std::endl;
    if (DogPretendToBeCat) {
        DogPretendToBeCat->getBrain().setIdea(0, "Meow while barking");
    } else {
        std::cout << "DogPretendToBeCat isn't a Dog !";
    }

    if (!dog || !dog1) {
        std::cout << "farm[0] or farm[1] isn't a Dog" << std::endl;
    } else {
        std::cout << std::endl;
        dog->getBrain().setIdea(0, " Bark");
        std::cout << "dog" << dog->getBrain().getIdea(0) << std::endl;

        dog1->getBrain().setIdea(1, " Play with the toy");
        std::cout << "dog1" << dog1->getBrain().getIdea(1) << std::endl;
    }
    
    std::cout << std::endl;
    
    if (CatPretendtoBeDog) {
        CatPretendtoBeDog->getBrain().setIdea(0, "Bark while meowing");
    } else {
        std::cout << "CatPretendTobeDog isn't a Cat !";
    }

    if (!cat || !cat1) {
        std::cout << "farm[6] or farm[7] isn't a Cat" << std::endl;
    } else {
        std::cout << std::endl;
        cat->getBrain().setIdea(0, " Meow");
        std::cout << "cat" << cat->getBrain().getIdea(0) << std::endl;
        
        cat1->getBrain().setIdea(1, " Play with the toy");
        std::cout << "cat1" << cat1->getBrain().getIdea(1) << std::endl;
    }
    
    std::cout << std::endl;
    
    std::cout << "====== MAKESOUND TAB TESTS ======" << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < size; ++i) {
        farm[i]->makeSound();
    }

    std::cout << std::endl;
    
    std::cout << "====== DESTROY TAB TESTS ======" << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < size; ++i) {
        delete farm[i];
    }
    
    std::cout << std::endl;
    
    std::cout << "====== COPY & OPERATOR TESTS ======" << std::endl;
    std::cout << std::endl;
    
    Dog* dog2 = new Dog();
    Dog* copyDog = new Dog(*dog2);
    Dog* OperatorDog = dog2;

    Cat* cat2 = new Cat();
    Cat* copyCat = new Cat(*cat2);
    Cat* OperatorCat = cat2;
    
    std::cout << std::endl;
    
    dog2->getBrain().setIdea(0, "Bark");
    copyDog->getBrain().setIdea(1, "Sleep");
    OperatorDog->getBrain().setIdea(2, "Eats a bone");

    cat2->getBrain().setIdea(0, "Meow");
    copyCat->getBrain().setIdea(1, "Sleep");
    OperatorCat->getBrain().setIdea(2, "Eats kibble");

    std::cout << "dog2: " << dog2->getBrain().getIdea(0) << std::endl; 
    std::cout << "copyDog: " << copyDog->getBrain().getIdea(1) << std::endl; 
    std::cout << "OperatorDog: " << OperatorDog->getBrain().getIdea(2) << std::endl;
    dog2->makeSound();
    copyDog->makeSound();
    OperatorDog->makeSound();

    std::cout << std::endl;
    
    std::cout << "cat2: " << cat2->getBrain().getIdea(0) << std::endl; 
    std::cout << "copyCat: " << copyCat->getBrain().getIdea(1) << std::endl;
    std::cout << "OperatorCat: " << OperatorCat->getBrain().getIdea(2) << std::endl;
    cat2->makeSound();
    copyCat->makeSound();
    OperatorCat->makeSound();

    std::cout << std::endl;
    std::cout << "====== DELETE TESTS ======" << std::endl;
    std::cout << std::endl;

    delete dog2;
    delete copyDog;
    delete cat2;
    delete copyCat;

    // Should not compile if we add this bc abstract class
    
    // AAnimal j;
    // AAnimal i = new AAnimal();

    return 0;
}
