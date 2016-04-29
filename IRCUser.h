//
//  IRCUser.h
//  Taco
//
//  Created by Florian Reichmuth on 02.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//
#pragma once
#include <stdio.h>
#include "main.h"
#include <string>
#include <vector>

class IRCUser {
public:
    std::string name;
    std::string host;
    int accessLevel;
    IRCUser(std::string, std::string, int);
    IRCUser(std::string, std::string, int, std::vector<std::string>);
    std::vector<std::string> streams;
};