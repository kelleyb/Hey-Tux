#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

void print_help(const char* name) {
	std::cout << "Usage: " << std::endl;
	std::cout << "    " << name << " tux, question..." << std::endl;
	exit(1);
}

int main(int argc, const char* argv[]) {

	if (argc < 3) {
		print_help(argv[0]);
	} else {
		if (std::string(argv[1]) != std::string("tux,")) {
			// They don't even know who they're asking. Let's teach them.
			std::string query = std::string("xdg-open http://lmgtfy.com/?q=what's+the+name+of+linux's+mascot? > /dev/null");
			popen(query.c_str(), "r");
			print_help(argv[0]);
			exit(1);
		}
	}

	std::string query;

	for (int i = 2; i < argc; ++i) {
		// Create the end part of the url, separate words by '+'
		if (i != 2) {
			query += '+';
		}
		query += argv[i];
	}

	// Build and run query
	query = std::string("xdg-open http://lmgtfy.com/?q=") + query;
	query += std::string(" > /dev/null");
	popen(query.c_str(), "r");

	return 0;
}