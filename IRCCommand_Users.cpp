//
//  IRCCommand_Users.cpp
//  Taco
//
//  Created by Florian Reichmuth on 16.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#include "IRCCommand_Users.h"
#include "IRCUser.h"
IRCCommand_Users::IRCCommand_Users(std::string cmd, IRCBot *bot, int lvl) :IRCCommand(cmd, bot, lvl){
   // this->response = response;
}


void IRCCommand_Users::CommandRecieved(std::string from, std::string in){
    std::cout << from << "    " << in << std::endl;
    std::vector<std::string> splitted;
    boost::split(splitted, in, boost::is_any_of(" \t\r\n"), boost::token_compress_on);
    std::string usr;
    if(splitted.size() < 2){
        for(IRCUser* u : bot->users);
           // bot->queueMessage(from, u);
    }
    
    
}