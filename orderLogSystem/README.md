#  orderLogSystem mini project
The '**orderLogSystem**' is structured to handle transaction verifications. The '**gen**' directory is specifically used for identifier generation, critical for 
transaction security. The system uses '**nlohmann/json.hpp**' for JSON data handling, which implies that transaction data is processed in this format.

-   Regarding compilation command `g++ -std=c++20 -I. main.cpp -o app` to build the project, with the `-std=c++20` flag indicating the use of C++20 features, and
´-I.´ for including the current directory in the header search path.

Lastly, the ´wallet-example.json´ file potentially represents a sample or template JSON structure that the system is capable of generating or utilizing within its 
processing workflow.