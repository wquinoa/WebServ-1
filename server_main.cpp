//
// Created by Денис on 13/12/2020.
//
#include <zconf.h>
#include "Net.hpp"

int main()
{
	char buff[13] = "0.0.0.0:8000";
	Net net(buff);
	int listen = net.listen();
	if (listen < 0)
		return (-1);
	std::cout << "Server is listening..." << std::endl;

	while (true)
	{
		std::cout << "Wait for client..." << std::endl;
		int accept = net.accept(listen);
		if (accept < 0)
			return (-1);
		while (true)
		{
			char buff[4096];
			//Приняли
			int len = net.recv(accept, buff, 4096);
			if (len <= 0)
				break ;
			//Отправили клиенту обратно
			std::cout << "Send message: " << buff <<  " to client..." << std::endl;
			net.send(accept, buff, 32);
		}
		net.close(accept);
	}
	net.close(listen);
	return (1);
}

