//
//  IRCCommand_Coffee.h
//  Taco
//
//  Created by Florian Reichmuth on 14.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#pragma once

#include "main.h"
#include "IRCCommand.h"
#include <string>
#include <vector>
class IRCCommand_Coffee : public IRCCommand {
public:
    IRCCommand_Coffee (std::string cmd, IRCBot *bot, int i);
    void CommandRecieved(std::string from, std::string in);
private:
    std::string response;
    std::vector<std::string> teas;
};