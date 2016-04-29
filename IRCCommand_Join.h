/* 
 * File:   IRCCommand_Join.h
 * Author: Florian
 *
 * Created on 25. Februar 2015, 21:50
 */

#pragma once

#include "main.h"
#include "IRCCommand.h"
#include <string>
class IRCCommand_Join : public IRCCommand {
public:
    IRCCommand_Join (std::string cmd, IRCBot *bot, int i);
    void CommandRecieved(std::string from, std::string in);
};