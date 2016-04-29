//
//  TwitchListener.h
//  Taco
//
//  Created by Florian Reichmuth on 16.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#pragma once
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "IRCBot.h"
#include "main.h"

class TwitchListener {
    
public:
    TwitchListener(IRCBot*, std::vector<std::string>);
    
    void run();
    
private:
    IRCBot *bot;
    std::vector<std::pair<std::string, std::pair<bool, std::pair<std::string, std::string>>>> streams;
    bool isOnline(std::string stream);
    std::string getGame(std::string);
    std::string getTitle(std::string);

};