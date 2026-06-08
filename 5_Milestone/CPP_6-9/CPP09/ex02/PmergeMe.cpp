/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:37:51 by jbanchon          #+#    #+#             */
/*   Updated: 2025/11/26 16:26:28 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {

    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgs(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        for (size_t j = 0; j < arg.size(); j++) {
            if (!std::isdigit(arg[j])) {
                std::cerr << "Error: non-numeric argument" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        long val = std::atol(argv[i]);
        if (val > std::numeric_limits<int>::max() || val < 0) {
            std::cerr << "Error: integer overflow or negative" << std::endl;
            exit(EXIT_FAILURE);
        }

        _vector.push_back(static_cast<int>(val));
        _list.push_back(static_cast<int>(val));
    }
}

std::vector<int> PmergeMe::generateJacobsthal(int n) {
    std::vector<int> jacobsthal;

    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    int last_elem = 1;

    while (last_elem < n) {
        int next_val = jacobsthal.back() + (2 * jacobsthal[jacobsthal.size() - 2]);
        jacobsthal.push_back(next_val);
        last_elem = next_val;
    }
    return jacobsthal;
}

std::vector<int> PmergeMe::buildInsertionSequence(std::vector<int>& jacobsthal, int n) {

    std::vector<int> seq;

    if (n < 1)
        return seq;

    size_t size = jacobsthal.size();
    for (size_t i = 3; i < size; ++i) {

        int upper = jacobsthal[i];
        int lower = jacobsthal[i - 1];

        if (upper > n)
            upper = n;

        for (int val = upper; val > lower; --val)
            seq.push_back(val - 1);

        if (upper == n)
            break;
    }
    return seq;
}

std::vector<int>::iterator PmergeMe::binarySearch(std::vector<int>& main_chain, int target, std::vector<int>::iterator limit) {
    return std::lower_bound(main_chain.begin(), limit, target);
}

void PmergeMe::_sortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    int straggler = -1;
    bool has_straggler = false;

    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        arr.pop_back();
        has_straggler = true;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        int first = arr[i];
        int second = arr[i + 1];

        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }
    std::vector<int> main_chain;
    for (size_t i = 0; i < pairs.size(); i++)
        main_chain.push_back(pairs[i].first);

    _sortVector(main_chain);

    std::vector<int> pendulous;
    for (size_t i = 0; i < main_chain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == main_chain[i]) {
                pendulous.push_back(pairs[j].second);
                break;
            }
        }
    }
    main_chain.insert(main_chain.begin(), pendulous[0]);
    std::vector<int> jacobsthal = generateJacobsthal(pendulous.size());
    std::vector<int> sequence = buildInsertionSequence(jacobsthal, pendulous.size());

    for (size_t i = 0; i < sequence.size(); i++) {
        int idx = sequence[i];
        if (idx >= (int)pendulous.size() || idx < 0)
            continue;
        int valueToInsert = pendulous[idx];

        int limitValue = main_chain[0];

        for (size_t k = 0; k < pairs.size(); k++) {
            if (pairs[k].second == valueToInsert) {
                limitValue = pairs[k].first;
                break;
            }
        }
        std::vector<int>::iterator limitIt = std::find(main_chain.begin(), main_chain.end(), limitValue);
        std::vector<int>::iterator pos = binarySearch(main_chain, valueToInsert, limitIt);
        main_chain.insert(pos, valueToInsert);
    }
    if (has_straggler) {
        std::vector<int>::iterator pos = binarySearch(main_chain, straggler, main_chain.end());
        main_chain.insert(pos, straggler);
    }
    arr = main_chain;
}

void PmergeMe::_sortList(std::list<int>& arr) {
    if (arr.size() <= 1)
        return;

    int straggler = -1;
    bool has_straggler = false;

    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        arr.pop_back();
        has_straggler = true;
    }
    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = arr.begin();

    while (it != arr.end()) {
        int first = *it;
        it++;
        if (it == arr.end())
            break;
        int second = *it;
        it++;

        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }

    std::list<int> main_chain;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        main_chain.push_back(it->first);
    }

    _sortList(main_chain);

    std::list<int> pendulous;
    for (std::list<int>::iterator nc_it = main_chain.begin(); nc_it != main_chain.end(); ++nc_it) {
        for (std::list<std::pair<int, int> >::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
            if (p_it->first == *nc_it) {
                pendulous.push_back(p_it->second);
                break;
            }
        }
    }
    main_chain.insert(main_chain.begin(), pendulous.front());

    std::vector<int> jacobsthal = generateJacobsthal(pendulous.size());
    std::vector<int> sequence = buildInsertionSequence(jacobsthal, pendulous.size());

    for (size_t i = 0; i < sequence.size(); i++) {
        int idx = sequence[i];

        if (idx >= (int)pendulous.size() || idx == 0)
            continue;

        std::list<int>::iterator pend_it = pendulous.begin();
        std::advance(pend_it, idx);
        int valueToInsert = *pend_it;

        int limitValue = main_chain.front();
        for (std::list<std::pair<int, int> >::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
            if (p_it->second == valueToInsert) {
                limitValue = p_it->first;
                break;
            }
        }
        std::list<int>::iterator limitIt = std::find(main_chain.begin(), main_chain.end(), limitValue);
        std::list<int>::iterator pos = std::lower_bound(main_chain.begin(), limitIt, valueToInsert);

        main_chain.insert(pos, valueToInsert);
    }
    if (has_straggler) {
        std::list<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }
    arr = main_chain;
}

void PmergeMe::run(int argc, char **argv) {

    parseArgs(argc, argv);

    std::cout << "Before : ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout  << _vector[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    _sortVector(_vector);
    clock_t endVec = clock();

    std::cout << "After : ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    clock_t startList = clock();
    _sortList(_list);
    clock_t endList = clock();

    double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << timeList << " us" << std::endl;
}


