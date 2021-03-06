//
// Created by Casie Carl on 12/15/20.
//

#ifndef SERV_CGI_HPP
#define SERV_CGI_HPP
#include <iostream>
#include <fcntl.h>
#include <algorithm>
#include <map>
#include "utils.hpp"
#include "Config.hpp"
#include <sys/time.h>


// 	CGI_scrypt(дочерний процесс)	----->	Server --- > Client(Browser)
								//	<-----		 //<----

class CGI
{
	std::string filename;
	std::string extension;
	std::string tmpFile;
	char		**env;
	char		*args[4];
	char		*buff;
	input		&in;
	Location    location;

	std::string interpretator;
	//настройки конфига
	const ServConf &servConf;

	// запрос от сервера на CGI

	//ответ после обработки

	std::string response;

	std::map<std::string, std::string> envMap;
	std::map<std::string, std::string> responseMap;

    void	    readFromCGI();
    void        initEnvironments();
    void        setUriAttributes();
	void		setHttpHeaders();
	void		createResponseMap();

	void		findInterpretator();


    int         initARGS();

    int     	mapToEnv();

public:
    CGI(const ServConf &_servConf, const Location &location, input &in);

    ~CGI();

	int 	run();

	const std::string &getResponse() const;
	std::map<std::string, std::string> getRespMap() const;

};


#endif //SERV_CGI_HPP
