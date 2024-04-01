// writeToJson.hpp

#ifndef WRITE_TO_JSON_HPP
#define WRITE_TO_JSON_HPP

#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"

void writeToJsonFile(const std::string& filePath){
    std::cout<< "[INSIDE ->] void writeToJsonFile(){} \n";

	//	Create a JSON object with some data
	nlohmann::json j;
	j["ID-key"] = 100;
	j["Credits"] = 0;
	j["Name"] = "Jane Doe";
	std::cout<< "(created JSON object with data) \n";
	
	//	Open a file stream to write
	std::ofstream writeToFile(filePath);
	if(!writeToFile.is_open()){
		std::cerr<< "[error]: Failed to open file for writing: "<< filePath << std::endl;
		return;
	}
	std::cout << "(opened a file stream to write) \n";

	// Write the JSON object to the file with pretty printing.
	writeToFile << j.dump(4);
	writeToFile.close();
	std::cout<< "(written to the JSON object/file) \n";
}

#endif  //  WRITE_TO_JSON_HPP