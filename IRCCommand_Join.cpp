/* 
 * File:   IRCCommand_Join.cpp
 * Author: Florian
 * 
 * Created on 25. Februar 2015, 21:50
 */

#include "IRCCommand_Join.h"
#include "IRCBot.h"

IRCCommand_Join::IRCCommand_Join(std::string cmd, IRCBot *bot, int i) : IRCCommand(cmd, bot, i) {
}

void IRCCommand_Join::CommandRecieved(std::string from, std::string in){
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
    std::transform(from.begin(), from.end(), from.begin(), ::tolower);
    std::vector<std::string> splitted;
    boost::split(splitted, in, boost::is_any_of(" \t\r\n,."), boost::token_compress_on);
    bot->join(splitted[1]);
    try {

    this->bot->stmt->execute("INSERT INTO Chans (chan) VALUES ('" + splitted[1] + "');");
        
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
