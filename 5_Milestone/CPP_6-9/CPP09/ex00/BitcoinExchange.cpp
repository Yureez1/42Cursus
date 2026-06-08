/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:44:04 by jbanchon          #+#    #+#             */
/*   Updated: 2025/11/16 14:54:11 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Mandatory

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    loadDataBase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Parsing

bool BitcoinExchange::checkFileExtension(const std::string& file) const {
    const std::string extension = ".csv";

    if (file.size() >= extension.size() && file.rfind(extension) == file.size() - extension.size())
        return true;
    return false;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    try {
        int year = std::atoi(date.substr(0, 4).c_str());
        int month = std::atoi(date.substr(5, 2).c_str());
        int day = std::atoi(date.substr(8, 2).c_str());

        if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
            return false;

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;

        if (month == 2) {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (day > 29 || (!isLeap && day > 28))
                return false;
        }
    }
    catch (...) {
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(float value) const {
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::loadDataBase(const std::string& filename) {
    if (!checkFileExtension(filename)) {
        std::cerr << "Error: Invalid file extension for database file." << std::endl;
        return ;
    }

    std::ifstream dbFile(filename.c_str());
    if (!dbFile.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return ;
    }

    std::string line;
    std::getline(dbFile, line);

    while (std::getline(dbFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string rateStr = line.substr(commaPos + 1);

            float rate = std::atof(rateStr.c_str());

            _exchangeRates[date] = rate;
        }
    }
    dbFile.close();
    if (_exchangeRates.empty())
        std::cerr << "Error: Database file is empty or invalid." << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& inputFilename) const {
    if (_exchangeRates.empty()) {
        std::cerr << "Error: Exchange rates database is empty." << std::endl;
        return ;
    }

    std::ifstream inputFile(inputFilename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return ;
    }

    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        size_t separatorPos = line.find(" | ");

        if (separatorPos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, separatorPos);
        std::string valueStr = line.substr(separatorPos + 3);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value = std::atof(valueStr.c_str());

        if (!isValidValue(value)) {
            continue;
        }

        std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);

        if (it == _exchangeRates.end())
            --it;

        else if (it->first != date && it != _exchangeRates.begin())
            --it;

        if (it == _exchangeRates.begin() && it->first != date) {
            std::cerr << "Error: no exchange rate available before " << date << std::endl;
            continue;
        }

        float rate = it->second;
        float result = value * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    inputFile.close();
}
