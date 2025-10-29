/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:03:33 by julien            #+#    #+#             */
/*   Updated: 2025/10/16 08:59:26 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { std::cout << "ScalarConverter Default Constructor called" << std::endl; }

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
    std::cout << "ScalarConverter Copy Constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){ std::cout << "ScalarConverter Destructor called" << std::endl; }

/* parsing helpers*/

static bool validDecimalCore(std::string const& str, bool require_f_suffix, bool allow_sign) {
    if (str.empty())
        return false;

    size_t i = 0;
    if (allow_sign && (str[i] == '+' || str[i] == '-'))
        i++;
    if (i >= str.size())
        return false;

    bool hasDot = false;
    bool leftDigits = false;
    bool rightDigits = false;

    while (i < str.size() && std::isdigit(static_cast<unsigned char>(str[i]))) {
        leftDigits = true;
        i++;
    }
    if (i >= str.size() || str[i] != '.')
        return false;
    hasDot = true;
    i++;
    while (i < str.size() && std::isdigit(static_cast<unsigned char>(str[i]))) {
        rightDigits = true;
        i++;
    }

    if (!(hasDot && leftDigits && rightDigits))
        return false;

    if (require_f_suffix) {
        if (i != str.size() - 1)
            return false;
        if (str[i] != 'f')
            return false;
        i++;
    }
    return i == str.size();
}

bool ScalarConverter::hasAnySpace(std::string const& str) {
	for (size_t i = 0; i < str.size(); ++i)
		if (std::isspace(static_cast<unsigned char>(str[i])))
			return true;
	return false;
}

bool ScalarConverter::isOnlySpace(std::string const& str) {
    if (str.empty()) {
        return true;
    }
    for(size_t i = 0; i < str.size(); i++) {
        if (!std::isspace(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isChar(std::string const& str) {
    return (str.size() == 1 && std::isprint(static_cast<unsigned char>(str[0])) && !std::isdigit(static_cast<unsigned char>(str[0])));
}

bool ScalarConverter::isInt(std::string const& str) {
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.size(); i++)
        if (std::isspace(static_cast<unsigned char>(str[i])))
            return false;

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;

    if (i >= str.size())
        return false;

    for (; i < str.size(); i++)
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;

    errno = 0;
    char *end = 0;
    long value = std::strtol(str.c_str(), &end, 10);
    if (errno != 0 || end == str.c_str() || *end != '\0')
        return false;
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool ScalarConverter::isFloat(std::string const& str) {
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;
    if (hasAnySpace(str))
        return false;
    return validDecimalCore(str, true, true);
}
bool ScalarConverter::isDouble(std::string const& str) {
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;
    if (hasAnySpace(str))
        return false;
    return validDecimalCore(str, false, true);
}

bool ScalarConverter::isPseudoFloat(std::string const& str) {
    return (str == "nanf" || str == "+inff" || str == "-inff");
}

bool ScalarConverter::isPseudoDouble(std::string const& str) {
    return (str == "nan" || str == "+inf" || str == "-inf");
}

bool ScalarConverter::isInvalid(std::string const& str) {
    if (isOnlySpace(str))
        return true;
    if (hasAnySpace(str))
        return true;
    return false;
}

ScalarConverter::e_type ScalarConverter::detectType(std::string const& str) {
    if (isInvalid(str))
        return TYPE_INVALID;
    if (isPseudoFloat(str))
        return TYPE_PSEUDO_FLOAT;
    if (isPseudoDouble(str))
        return TYPE_PSEUDO_DOUBLE;
    if (isChar(str))
        return TYPE_CHAR;
    if (isInt(str))
        return TYPE_INT;
    if (isFloat(str))
        return TYPE_FLOAT;
    if (isDouble(str))
        return TYPE_DOUBLE;
    return TYPE_INVALID;
}

/*Printing depending of type*/

static void printCharFromLong(double value) {
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 255) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    int intValue = static_cast<int>(value);
    if (intValue < 32 || intValue == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
}

static void printIntFromDouble(double value) {
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout <<"int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value) {
    if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
        return ;
    }
    if (std::isinf(value)) {
        if (value > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
        return ;
    }
    float f = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
}

static void printDouble(double value) {
    if (std::isnan(value)) {
        std::cout << "double: nan" << std::endl;
        return ;
    }
    if (std::isinf(value)) {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
        return ;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << value << std::endl;
}

/*Converting depending of type*/
void ScalarConverter::convert(std::string const& literal) {
    e_type type = detectType(literal);

    if (type == TYPE_PSEUDO_FLOAT) {
        std::cout << "char: impossible" << std::endl;
        std::cout <<"int: impossible" << std::endl;

        std::cout << "float: " << literal << std::endl;

        if (literal == "nanf")
            std::cout << "double: nan" << std::endl;
        else if (literal == "+inff")
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
        return ;
    }
    if (type == TYPE_PSEUDO_DOUBLE) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal == "nan")
            std::cout << "float: nanf" << std::endl;
        else if (literal == "+inf")
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "double: " << literal << std::endl;
        return ;
    }

    switch (type) {
        case TYPE_CHAR: {
            char c = literal[0];
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
            return ;
        }

        case TYPE_INT: {
            errno = 0;
            char *end = 0;
            long value = std::strtol(literal.c_str(), &end, 10);
            (void)end;
            int intValue = static_cast<int>(value);

            if (intValue < 0 || intValue > 255)
                std::cout << "char: impossible" << std::endl;
            else if (intValue < 32 || intValue == 127)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;

            std::cout << "int: " << intValue << std::endl;

            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(intValue) << std::endl;
            return ;
        }

        case TYPE_FLOAT: {
            float f = std::strtof(literal.c_str(), 0);
            printCharFromLong(f);
            printIntFromDouble(f);
            printFloat(f);
            printDouble(f);
            return ;
        }

        case TYPE_DOUBLE: {
            double d = std::strtod(literal.c_str(), 0);
            printCharFromLong(d);
            printIntFromDouble(d);
            printFloat(d);
            printDouble(d);
            return ;
        }

        case TYPE_INVALID:
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
    }
}
