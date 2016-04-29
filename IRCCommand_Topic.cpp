/* 
 * File:   IRCCommand_Topic.cpp
 * Author: florian
 * 
 * Created on 26. Mai 2015, 16:37
 */

#include "IRCCommand_Topic.h"
#include "IRCConnection.h"

IRCCommand_Topic::IRCCommand_Topic(std::string cmd, IRCBot *bot, int lvl) :IRCCommand(cmd, bot, lvl){
}

void IRCCommand_Topic::CommandRecieved(std::string from, std::string in){
    
    std::vector<std::string> splitted;
    boost::split(splitted, in, boost::is_any_of(" \t\r\n"), boost::token_compress_on);
    std::string usr;
    if(splitted.size() >= 2){
        if(splitted[1] == "toggle"){
            if(online){
                online = false;
                if(game == ""){
                    game = "---";
                }
                bot->connection->sendToIRC("TOPIC " + from + " Stream: \u000304OFFLINE\u000F"+" | Game: " + game + " | Next: | http://furkay.de\r\n");
            }
            else{
                online = true;
                bot->connection->sendToIRC("TOPIC " + from + " Stream: \u000303ONLINE\u000F"+" | Game: " + game + " | http://furkay.de\r\n");
            }
        }
        else if(splitted[1] == "reset"){
            online = false;
            game = "---";
            next = "---";
            bot->connection->sendToIRC("TOPIC " + from + " Stream: \u000304OFFLINE\u000F"+" | Game: " + game + " | Next: " + next + " | http://furkay.de\r\n");
        }
    }
    
    if(splitted.size() >= 4) {
        if(splitted[1] == "set"){
            if(splitted[2] == "game"){
                game = splitted[3];

                for(int i = 4; i<splitted.size(); i++){
                    game += " " + splitted[i];
                }
                if(online){
                                    bot->connection->sendToIRC("TOPIC " + from + " Stream: \u000303ONLINE\u000F"+" | Game: " + game + " | http://furkay.de\r\n");

                }
                else{
                                    bot->connection->sendToIRC("TOPIC " + from + " Stream: \u000304OFFLINE\u000F"+" | Game: " + game + " | http://furkay.de\r\n");

                }
            }
            else if(splitted[2] == "next"){
                next = splitted[3];

                for(int i = 4; i<splitted.size(); i++){
                    next += " " + splitted[i];
                }                if(online){
                    return;
                }
                bot->connection->sendToIRC("TOPIC " + from + " Stream: \u000304OFFLINE\u000F"+" | Game: " + game + " | Next: " + next + " | http://furkay.de\r\n");

            }
        }
    }
}
