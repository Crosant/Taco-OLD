/*  * File:   IRCConnection.h * Author: Florian * * Created on 20. Februar 2015, 23:14 */#pragma once#include <iostream>#include <string>#include <string.h>#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h#include <netinet/in.h>  // Internet domain address structures and functions#include <sys/socket.h>  // Structures and functions used for socket API#include <netdb.h>       // Used for domain/DNS hostname lookup#include <unistd.h>#include <stdlib.h>#include <errno.h>#include <cerrno>#include <cstring>#include <clocale>#include <algorithm>#include <chrono>#include <thread>//#include "main.h"class IRCConnection {public:    IRCConnection();    IRCConnection(const IRCConnection& orig);    virtual ~IRCConnection();    int connectToIRC(std::string server, int port, std::string name, std::string password);    void sendToIRC(const std::string message);    std::string receiveFromIRC();private:    int socketH;    std::string ReadLine (int fd);    std::string buffer;};