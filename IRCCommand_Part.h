/* 
 * File:   IRCCommand_Part.h
 * Author: Florian
 *
 * Created on 25. Februar 2015, 21:50
 */

#pragma once

#include "main.h"
#include "IRCCommand.h"
#include <string>
class IRCCommand_Part : public IRCCommand {
public:
    IRCCommand_Part (std::string cmd, IRCBot *bot, int i);
    void CommandRecieved(std::string from, std::string in);


};