/*Look through this example script, for ideas you can isolate in header files
and make them independent where you can include them and build out a bigger 
library for your value-transferring system.*/

#include <iostream>
#include <fstream>
#include <string>

#include "nlohmann/json.hpp" // header library downloaded for handling JSON files
#include "jsonLib/write_to_json.hpp"	//	write_to_json.hpp creates JSON value holder files.
#include "gen/idgen.hpp" // library for generating ID-keys.

int main(){
	std::cout<<"[inside int main() function] \n";

	// writeToJsonFile("wallet.json", "Marco", 100, 500.50);

	return 0;
}
