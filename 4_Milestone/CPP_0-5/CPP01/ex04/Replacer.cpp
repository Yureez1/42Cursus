/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:32:58 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/28 14:30:17 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2) : _filename(filename), _s1(s1), _s2(s2), _input(), _output() {}

bool Replacer::readInput() {
    
    std::ifstream in(_filename.c_str());
    if (!in)
        return false;
    std::ostringstream oss;
    oss << in.rdbuf();
    _input = oss.str();
    return true;
}

void Replacer::transform() {
    
    if (_s1 == _s2) {
        _output = _input;
        return ;
    }
    
    _output.clear();
    if (_s1.empty()) {
        _output = _input;
        return ;
    }
    
    std::string::size_type pos = 0;
    while (true) {
        std::string::size_type found = _input.find(_s1, pos);
        
        if (found == std::string::npos) {
            _output.append(_input, pos, std::string::npos);
            break;
        }
        
        _output.append(_input, pos, found - pos);
        _output.append(_s2);
        pos = found + _s1.size();
    }
}

bool Replacer::writeOuput() const {
    
    std::string outName = _filename + ".replace";
    std::ofstream out(outName.c_str());
    if (!out) {
        return false;
    }
    out << _output;
    return out.good();
}
