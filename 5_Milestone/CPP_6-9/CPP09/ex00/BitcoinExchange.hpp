/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:44:01 by jbanchon          #+#    #+#             */
/*   Updated: 2025/11/16 14:56:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_EXCHANGE
#define BTC_EXCHANGE

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>

#define DATABASE_FILE "data.csv"

class BitcoinExchange {

private:
    std::map<std::string, float> _exchangeRates;
    void loadDataBase(const std::string& filename);
    bool isValidDate(const std::string& date) const;
    bool isValidValue(float value) const;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& databaseFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void processInputFile(const std::string& inputFile) const;
    bool checkFileExtension(const std::string &file) const;

};

#endif

