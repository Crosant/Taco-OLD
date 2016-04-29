//
//  IRCCommand_Tea.cpp
//  Taco
//
//  Created by Florian Reichmuth on 03.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#include "IRCCommand_Tea.h"
#include "IRCConnection.h"
IRCCommand_Tea::IRCCommand_Tea(std::string cmd, IRCBot *bot, std::vector<std::string> teas, int i):IRCCommand(cmd, bot, i) {
    this->teas = teas;
}

void IRCCommand_Tea::CommandRecieved(std::string from, std::string in){
    std::vector<std::string> splitted;
    boost::split(splitted, in, boost::is_any_of(" \t\r\n"), boost::token_compress_on);
    std::string usr;
//    if(splitted.size() < 3){
    if(splitted.size() < 2){
        response = "kocht einen ";
    }
    else{
        if(splitted[1] == "..__.."){
            
            std::string out;
            
            for(std::string t : teas){
                out += " " + t;
            }
            
            bot->queueMessage(from, out);
            return;
            
        }
        response = "kocht " + splitted[1] + " einen ";
    }
//    }
//    else{
//        if(splitted[1] == "add"){
//            bot->stmt->execute("INSERT INTO Teas (name) VALUES ('" + splitted[2] + "');");
//        }
//    }
    std::string out = response + teas[rand() % teas.size()] + ".";
    bot->queueMessage(from, "\u0001ACTION " + out + "\u0001");
}