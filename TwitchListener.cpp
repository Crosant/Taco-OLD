//
//  TwitchListener.cpp
//  Taco
//
//  Created by Florian Reichmuth on 16.05.15.
//  Copyright (c) 2015 Florian Reichmuth. All rights reserved.
//

#include "TwitchListener.h"
#include <curl/curl.h>
#include "IRCUser.h"
#include "IRCConnection.h"
#include <sstream>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
using namespace std::literals::chrono_literals;

TwitchListener::TwitchListener(IRCBot *b, std::vector<std::string> s) {
    this->bot = b;
    for (std::string s2 : s) {
        streams.push_back(std::make_pair(s2, std::make_pair(false, std::make_pair("---","---") )));
    }






    std::thread twitch(&TwitchListener::run, this);

    twitch.join();

}

void TwitchListener::run() {

    while (true) {

        for (IRCUser *u : this->bot->users) {
            std::string user = u->name;
            std::vector < std::pair < std::string, std::pair<bool, std::pair<std::string, std::string>>>> tmp;
            for (std::pair < std::string, std::pair<bool, std::pair<std::string, std::string >>> p : this->streams) {
                std::string name = p.first;
                std::string game = p.second.second.first;
                std::string title = p.second.second.second;
                bool online = p.second.first;

                if (std::find(u->streams.begin(), u->streams.end(), name) == u->streams.end()) {
                    if (std::find(tmp.begin(), tmp.end(), p) == tmp.end()) {
                        tmp.push_back(p);
                    }
                    continue;
                }

                std::string tmp2;
                if (online) {
                    if (!isOnline(name)) {
                        std::this_thread::sleep_for(1min);
                        if (!isOnline(name)) {
                            online = false;
                            this->bot->queueMessage(user, name + " went offline");
                            if (boost::iequals(name, "herrdekay"))
                                bot->connection->sendToIRC("TOPIC #furkay Stream: \u000304OFFLINE\u000F | Game: --- | Next: --- | http://furkay.de\r\n");

                        } else {
                            if (std::find(tmp.begin(), tmp.end(), p) == tmp.end()) {
                                tmp.push_back(p);
                            }
                            continue;
                        }
                    } else {
                        if (game != (tmp2 = getGame(name))) {
                            std::this_thread::sleep_for(1min);
                            if(tmp2 == getGame(name)){
                                game = tmp2;
                                title = getTitle(name);
                                this->bot->queueMessage(user, name + " changed game to " + game + "[http://twitch.tv/" + name + "]");
                                if (boost::iequals(name, "herrdekay"))

                                    bot->connection->sendToIRC("TOPIC #furkay Stream: \u000303ONLINE\u000F | Game: " + game + " | Title: " + title + " | http://furkay.de\r\n");
                            }
                        }
                         if (title != (tmp2 = getTitle(name))) {
                            std::this_thread::sleep_for(1min);
                            if(tmp2 == getTitle(name)){
                                title = tmp2;
                                game = getGame(name);
                                if (boost::iequals(name, "herrdekay"))
                                    bot->connection->sendToIRC("TOPIC #furkay Stream: \u000303ONLINE\u000F | Game: " + game + " | Title: " + title + " | http://furkay.de\r\n");
                            }
                         }
                    }
                } else {
                    if (isOnline(name)) {
                        std::this_thread::sleep_for(1min);
                            if(isOnline(name)){
                                online = true;
                                game = getGame(name);
                                title = getTitle(name);
                                this->bot->queueMessage(user, name + " went online with " + game + "[http://twitch.tv/" + name + "]");
                                if (boost::iequals(name, "herrdekay"))

                                    bot->connection->sendToIRC("TOPIC #furkay Stream: \u000303ONLINE\u000F | Game: " + game + " | Title: " + title + " | http://furkay.de\r\n");
                            }
                         }
                }

                p.second.second.second = title;
                p.second.second.first = game;
                p.second.first = online;
                if (std::find(tmp.begin(), tmp.end(), p) == tmp.end()) {
                    tmp.push_back(p);
                }
            }

            this->streams = tmp;
        }
                std::this_thread::sleep_for(120s);

    }

}

bool TwitchListener::isOnline(std::string stream) {
std::transform(stream.begin(), stream.end(), stream.begin(), ::tolower);

    std::string url = "https://api.twitch.tv/kraken/streams/" + stream;
    std::stringstream is;

    try {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;

        // Set the URL.
        myRequest.setOpt<curlpp::options::Url>(url);

        // Send request and get a result.
        // By default the result goes to standard output.
        //myRequest.perform();
        is << myRequest;



    boost::property_tree::ptree json;
is.seekg(0,is.beg);

    boost::property_tree::read_json(is, json);

    std::string o = json.get("stream.game", "SOMERANDOMNESS");
    if (o != "SOMERANDOMNESS")
        return true;

        } catch (curlpp::RuntimeError & e) {
        std::cout << e.what() << std::endl;
    } catch (curlpp::LogicError & e) {
        std::cout << e.what() << std::endl;
    }
    catch (boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::property_tree::json_parser::json_parser_error> > & e) {
        std::cout << e.what() << std::endl;
    }
    
    return false;
    
}

std::string TwitchListener::getGame(std::string stream) {
    std::transform(stream.begin(), stream.end(), stream.begin(), ::tolower);

    std::string url = "https://api.twitch.tv/kraken/streams/" + stream;
    std::stringstream is;

    try {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;

        // Set the URL.
        myRequest.setOpt<curlpp::options::Url>(url);

        // Send request and get a result.
        // By default the result goes to standard output.
        //myRequest.perform();
        is << myRequest;

    boost::property_tree::ptree json;
is.seekg(0,is.beg);
    boost::property_tree::read_json(is, json);

    std::string o = json.get("stream.game", "SOMERANDOMNESS");
    if (o != "SOMERANDOMNESS")
        return o;
        } catch (curlpp::RuntimeError & e) {
        std::cout << e.what() << std::endl;
    } catch (curlpp::LogicError & e) {
        std::cout << e.what() << std::endl;
    }
    catch (boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::property_tree::json_parser::json_parser_error> > & e) {
        std::cout << e.what() << std::endl;
    }
    return "";
}
std::string TwitchListener::getTitle(std::string stream) {
    std::transform(stream.begin(), stream.end(), stream.begin(), ::tolower);

    std::string url = "https://api.twitch.tv/kraken/streams/" + stream;
    std::stringstream is;

    try {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;

        // Set the URL.
        myRequest.setOpt<curlpp::options::Url>(url);

        // Send request and get a result.
        // By default the result goes to standard output.
        //myRequest.perform();
        is << myRequest;

    boost::property_tree::ptree json;
is.seekg(0,is.beg);
    boost::property_tree::read_json(is, json);

    std::string o = json.get("stream.channel.status", "SOMERANDOMNESS");
    if (o != "SOMERANDOMNESS")
        return o;
        } catch (curlpp::RuntimeError & e) {
        std::cout << e.what() << std::endl;
    } catch (curlpp::LogicError & e) {
        std::cout << e.what() << std::endl;
    }
    catch (boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::property_tree::json_parser::json_parser_error> > & e) {
        std::cout << e.what() << std::endl;
    }
    return "";
}