//
//  IRCCommand_Response.cpp
//  Taco
//
//  Created by Florian Reichmuth on 03.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#include "IRCCommand_Response.h"


IRCCommand_Response::IRCCommand_Response(std::string cmd, std::string response, IRCBot *bot, int lvl) :IRCCommand(cmd, bot, lvl){
    this->response = response;
}


void IRCCommand_Response::CommandRecieved(std::string from, std::string in){
    this->bot->queueMessage(from, this->response);
}