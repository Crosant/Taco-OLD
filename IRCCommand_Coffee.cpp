//
//  IRCCommand_Coffee.cpp
//  Taco
//
//  Created by Florian Reichmuth on 14.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#include "IRCCommand_Coffee.h"
#include "IRCConnection.h"
IRCCommand_Coffee::IRCCommand_Coffee(std::string cmd, IRCBot *bot, int i):IRCCommand(cmd, bot, i) {
    this->teas = teas;
}

void IRCCommand_Coffee::CommandRecieved(std::string from, std::string in){
    std::vector<std::string> splitted;
    boost::split(splitted, in, boost::is_any_of(" \t\r\n"), boost::token_compress_on);
    std::string usr;
    if(splitted.size() < 2){
        response = "kocht einen ";
    }
    else{
        response = "kocht " + splitted[1] + " einen ";
    }
    std::string out = response + "Kaffee" + ".";
    bot->queueMessage(from, "\u0001ACTION " + out + "\u0001");
}