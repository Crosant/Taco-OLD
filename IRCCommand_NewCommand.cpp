/* 
 * File:   IRCCommand_NewCommand.cpp
 * Author: Florian
 * 
 * Created on 25. Februar 2015, 15:58
 */

#include "IRCCommand_NewCommand.h"
#include "IRCCommand_Response.h"
#include <boost/lexical_cast.hpp>

IRCCommand_NewCommand::IRCCommand_NewCommand(std::string cmd, IRCBot *bot, int i) : IRCCommand(cmd, bot, i) {
}


void IRCCommand_NewCommand::CommandRecieved(std::string from, std::string in){
    
    std::vector<std::string> splitted;
    boost::split(splitted, in, boost::is_any_of(" \t\r\n"), boost::token_compress_on);
    if(splitted.size() < 3) return;
int lvl;
      std::string cmd = splitted[1];try{
        lvl = boost::lexical_cast<int>(splitted[2]);
      }
      catch(boost::bad_lexical_cast){
          return;
      }
      if(splitted.size() < 4) return;
      std::string response = in.substr(std::distance(in.begin(), boost::find_nth(in, splitted[3], 0).begin()));
      IRCCommand *c = new IRCCommand_Response(cmd, response, bot, lvl);
      bot->registerCMD(c);
    
    this->bot->stmt->execute("INSERT INTO Commands (cmd,response,userLevel) VALUES ('" + cmd + "', '" + response + "', '" + boost::lexical_cast<std::string>(lvl) +"');");

}
