/* 
 * File:   IRCCommand_User.cpp
 * Author: florian
 * 
 * Created on 26. Mai 2015, 22:33
 */

#include <boost/lexical_cast.hpp>

#include "IRCCommand_User.h"

IRCCommand_User::IRCCommand_User(std::string cmd, IRCBot *bot, int lvl) :IRCCommand(cmd, bot, lvl){
}


void IRCCommand_User::CommandRecieved(std::string from, std::string in){

    std::vector<std::string> splitted;
    boost::split(splitted, in, boost::is_any_of(" \t\r\n"), boost::token_compress_on);
    std::string usr;
    if(splitted.size() < 2){ //!user
        
    }
    
    else if(splitted.size() < 3){ //!user add //!user remove
        
    }
    
    else if(splitted.size() < 4){ //!user add name //!user remove name

    }
    
    else if(splitted.size() < 5){ //!user add name host

    }
    
    else if(splitted.size() < 6){//!user add name host lvl
        if(splitted[1] == "add"){
            try{
            this->bot->addUser(splitted[2], "!" + splitted[3], boost::lexical_cast<int>( splitted[4] ), {});
            }
                  catch(boost::bad_lexical_cast){
          return;
      }try {

    this->bot->stmt->execute("INSERT INTO User (name, host, level, streams) VALUES ('" + splitted[2] + "', '" + "!" +splitted[3] + "', '" + splitted[4] + "', '{\"streams\": [\"\"]}');");
    this->bot->queueMessage(from, "Added " + splitted[2] +"!" + splitted[3] +" with access level "+ splitted[4] + "\r\n");
    }
    catch(sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        /* what() (derived from std::runtime_error) fetches error message */
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
   
    }
        } 
    }

}