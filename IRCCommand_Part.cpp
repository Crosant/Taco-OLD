/* 
 * File:   IRCCommand_Part.cpp
 * Author: Florian
 * 
 * Created on 25. Februar 2015, 21:50
 */

#include "IRCCommand_Part.h"
#include "IRCBot.h"

IRCCommand_Part::IRCCommand_Part(std::string cmd, IRCBot *bot, int i) : IRCCommand(cmd, bot, i) {
}

void IRCCommand_Part::CommandRecieved(std::string from, std::string in){
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
    std::transform(from.begin(), from.end(), from.begin(), ::tolower);
    std::vector<std::string> splitted;
    std::string chan;
    boost::split(splitted, in, boost::is_any_of(" \t\r\n"), boost::token_compress_on);
    if(splitted.size() < 2){
        chan = from;
    }
    else{
        chan =splitted[1] ;
    }
    try{
    this->bot->stmt->execute("DELETE FROM Chans WHERE chan='" + chan + "';");
    }
     catch(sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        /* what() (derived from std::runtime_error) fetches error message */
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
   
    }
      bot->part(chan);

}
