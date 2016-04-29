//
//  IRCCommand_Rehash.cpp
//  Taco
//
//  Created by Florian Reichmuth on 15.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#include "IRCCommand_Rehash.h"

IRCCommand_Rehash::IRCCommand_Rehash(std::string cmd, IRCBot *bot, int lvl) :IRCCommand(cmd, bot, lvl){
}


void IRCCommand_Rehash::CommandRecieved(std::string from, std::string in){
    this->bot->rehash();
}