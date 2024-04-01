// writeToJson.hpp

/*Function Description: writeToJsonFile(){}:

The function writeToJson is designed to create a JSON object and write it to a 
file. The JSON object is constructed using provided parameters such as 'name', 
'ID', and 'credits'. These parameters are assigned to respective keys within 
the JSON object. After creating the JSON object, the function attempts to open a 
file stream with the given file path. If successful, it writes the JSON objet to the file
with indentation for readability. If the file cannot be opened, an error message is 
displayed and the function returns early without attempting to write.

Here is an example call to such a function:

writeToJson("path to file", "John Doe", 123, 45.67);

In this call, "path to file" should be replaced with the actual pth to th file you want to
create or overwrite, "John Doe" is the "name", "123", is the "ID" and "45.67" is the
credits value.
*/

#ifndef WRITE_TO_JSON_HPP
#define WRITE_TO_JSON_HPP

#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"
#include <string>

void writeToJsonFile(const std::string& filePath, std::string name, int ID, double credits){
    std::cout<< "[INSIDE ->] void writeToJsonFile(){} \n";

	//	Create a JSON object with some data
	nlohmann::json j;
	j["ID-key"] = ID;
	j["Credits"] = credits;
	j["Name"] = name;
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