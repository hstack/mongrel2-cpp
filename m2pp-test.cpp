#include <zmq.hpp>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include "m2pp.hpp"

int main(int argc, char *argv[]) {
	std::string sender_id = "82209006-86FF-4982-B5EA-D1E29E55D481";

	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <from> <to>\n"
			"\tExample: " << argv[0] << " 'tcp://127.0.0.1:8988'"
			" 'tcp://127.0.0.1:8989'" << std::endl;
		return 1;
	}

	m2pp::connection conn(sender_id, argv[1], argv[2]);

	while (1) {
		m2pp::request req = conn.recv();

		if (req.disconnect) {
			std::cout << "== disconnect ==" << std::endl;
			continue;
		}

		//std::ostringstream response;
		//response << "OK" << std::endl;

		//std::cout << response.str();

		conn.reply_http(req, "");
	}

	return 0;
}

