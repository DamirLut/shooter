#include <fstream>
#include <map>
#include <string>
#include <iostream>


class Config {
private:
	typedef std::map<std::string, std::string> _map;
	inline static _map data;

public:
	static bool open(std::string filename);
	template<typename T>
	static T get(const std::string& key) {
		std::istringstream ss(Config::data[key]);
		T value;
		ss >> value;
		return value;
	};

};