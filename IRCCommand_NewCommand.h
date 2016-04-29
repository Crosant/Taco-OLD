/* 
 * File:   IRCCommand_NewCommand.h
 * Author: Florian
 *
 * Created on 25. Februar 2015, 15:58
 */


#pragma once

#include "main.h"
#include "IRCCommand.h"
#include <string>
class IRCCommand_NewCommand : public IRCCommand {
public:
    IRCCommand_NewCommand(std::string cmd, IRCBot *bot, int i);
    void CommandRecieved(std::string from, std::string in);


};


