/* 
 * File:   IRCCommand_Topic.h
 * Author: florian
 *
 * Created on 26. Mai 2015, 16:37
 */

#pragma once 

#include "main.h"
#include "IRCCommand.h"
#include <string>
class IRCCommand_Topic : public IRCCommand {
public:
    IRCCommand_Topic (std::string cmd, IRCBot *bot, int i);
    void CommandRecieved(std::string from, std::string in);
private:
    bool online = false;
    std::string game = "";
    std::string next = "";
};
