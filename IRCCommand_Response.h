//
//  IRCCommand_Response.h
//  Taco
//
//  Created by Florian Reichmuth on 03.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#pragma once 

#include "main.h"
#include "IRCCommand.h"
#include <string>
class IRCCommand_Response : public IRCCommand {
public:
    IRCCommand_Response (std::string cmd, std::string response, IRCBot *bot, int i);
    void CommandRecieved(std::string from, std::string in);
private:
    std::string response;
};