//
//  IRCUser.cpp
//  Taco
//
//  Created by Florian Reichmuth on 02.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#include "IRCUser.h"
IRCUser::IRCUser(std::string n, std::string h, int a){
    this->name = n;
    this->host = h;
    this->accessLevel = a;
}

IRCUser::IRCUser(std::string n, std::string h, int a, std::vector<std::string> s){
    this->name = n;
    this->host = h;
    this->accessLevel = a;
    this->streams = s;
}