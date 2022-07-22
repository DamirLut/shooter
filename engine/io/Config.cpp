#include "Config.h"


bool Config::open(std::string filename) {
	try {
		std::ifstream file(filename);

		std::string line;

		while (std::getline(file, line))
		{
			/// Trimming string

			auto whitespace = " \t";
			auto strBegin = line.find_first_not_of(whitespace);

			if (strBegin == std::string::npos) continue;

			auto strEnd = line.find_last_not_of(whitespace);
			auto strRange = strEnd - strBegin + 1;

			line = line.substr(strBegin, strRange);
			///

			if ( line[0] != '#') {
				std::string var = line.substr(0, line.find("="));
				std::string value = line.substr(line.find("=") + 1, line.length());
				std::cout << var + " = " + value << std::endl;
				Config::data[var] = value;
			}
		}

		file.close();
		Config::loaded = true;
		return true;
	}
	catch (int) {
		return false;
	}
}

