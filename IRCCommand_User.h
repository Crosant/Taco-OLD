/* 
 * File:   IRCCommand_User.h
 * Author: florian
 *
 * Created on 26. Mai 2015, 22:33
 */

#pragma once 

#include "main.h"
#include "IRCCommand.h"
#include <string>
class IRCCommand_User : public IRCCommand {
public:
    IRCCommand_User (std::string cmd, IRCBot *bot, int i);
    void CommandRecieved(std::string from, std::string in);
private:
};