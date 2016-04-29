//
//  IRCCommand_Tea.h
//  Taco
//
//  Created by Florian Reichmuth on 03.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#pragma once

#include "main.h"
#include "IRCCommand.h"
#include <string>
#include <vector>
class IRCCommand_Tea : public IRCCommand {
public:
    IRCCommand_Tea (std::string cmd, IRCBot *bot, std::vector<std::string> teas, int i);
    void CommandRecieved(std::string from, std::string in);
private:
    std::string response;
    std::vector<std::string> teas;
};