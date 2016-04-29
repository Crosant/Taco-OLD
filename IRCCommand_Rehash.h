//
//  IRCCommand_Rehash.h
//  Taco
//
//  Created by Florian Reichmuth on 15.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#pragma once

#include "main.h"
#include "IRCCommand.h"
#include <string>
class IRCCommand_Rehash : public IRCCommand {
public:
    IRCCommand_Rehash (std::string cmd, IRCBot *bot, int i);
    void CommandRecieved(std::string from, std::string in);
private:
};