#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include "C:\Users\ameya\Desktop\DemoDelsys\Maker\dummy\p3\CPlusPlus2\CPlusPlus2\addressbook.pb.h"
#include <cstring>
#include <boost/asio.hpp>
using namespace std;
using namespace tutorial;
#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

int main() {
	cout<<"Hello" << endl;

    boost::asio::io_context io_context;

    //// Create a TCP socket
    boost::asio::ip::tcp::socket socket(io_context);

    // Create an endpoint and connect to the server
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234);
    boost::system::error_code error;
    socket.connect(endpoint, error);
    if (error) {
        std::cerr << "Error connecting to server: " << error.message() << std::endl;
        return 1;
    }

    char buffer[1024];
    boost::system::error_code ec;
    std::size_t bytes_received;
    

    std::cout << "Data appended to file" << std::endl;
    while (true) {
        boost::system::error_code error;
        std::size_t bytes_received = socket.read_some(boost::asio::buffer(buffer), error);
        if (error == boost::asio::error::eof) {
            // Connection closed by the server
            break;
        }
        else if (error) {
            std::cerr << "Error receiving data: " << error.message() << std::endl;
            break;
        }
        std::cout << "Received: " << std::string(buffer, bytes_received) << std::endl;
        // Writing to a file
        // Open the file for appending
        std::ofstream outfile("delsys.txt", std::ios::app);

        if (!outfile.is_open()) {
            // If the file can't be opened for appending, try creating it
            outfile.open("delsys.txt");
            if (!outfile.is_open()) {
                std::cerr << "Failed to open file for writing" << std::endl;
                return 1;
            }
        }

        // Append data to the file
        std::string data = string(buffer, bytes_received) + "\n";

        outfile << data;

        // Close the file
        outfile.close();
             }
        if (ec != boost::asio::error::eof) {
        std::cerr << "Error receiving data: " << ec.message() << std::endl;
        return 1;
         }  
    // Close the socket
    socket.close();

    return 0;

}

//---------------------------------------------------------------------------------------
// Second Working Prototype
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <iostream>
//#include <fstream>
//#include "C:\Users\ameya\Desktop\DemoDelsys\Maker\dummy\p3\CPlusPlus2\CPlusPlus2\addressbook.pb.h"
//#include <cstring>
//#include <boost/asio.hpp>
//using namespace std;
//using namespace tutorial;
//
//int main() {
//	cout<<"Hello" << endl;
//
//    boost::asio::io_context io_context;
//
//    //// Create a TCP socket
//    boost::asio::ip::tcp::socket socket(io_context);
//
//    // Create an endpoint and connect to the server
//    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234);
//    boost::system::error_code error;
//    socket.connect(endpoint, error);
//    if (error) {
//        std::cerr << "Error connecting to server: " << error.message() << std::endl;
//        return 1;
//    }
//
//    char buffer[1024];
//    boost::system::error_code ec;
//    std::size_t bytes_received;
//    
//
//    std::cout << "Data appended to file" << std::endl;
//    while ((bytes_received = socket.read_some(boost::asio::buffer(buffer), ec)) > 0) {
//        std::cout << "Received: " << std::string(buffer, bytes_received) << std::endl;
//
//
//        // Writing to a file
//        // Open the file for appending
//        std::ofstream outfile("delsys.txt", std::ios::app);
//
//        if (!outfile.is_open()) {
//            // If the file can't be opened for appending, try creating it
//            outfile.open("delsys.txt");
//            if (!outfile.is_open()) {
//                std::cerr << "Failed to open file for writing" << std::endl;
//                return 1;
//            }
//        }
//
//        // Append data to the file
//        std::string data = string(buffer, bytes_received) + "\n";
//
//        outfile << data;
//
//        // Close the file
//        outfile.close();
//        }
//      if (ec != boost::asio::error::eof) {
//        std::cerr << "Error receiving data: " << ec.message() << std::endl;
//        return 1;
//    }
//
//    socket.close();
//    return 0;
//
//}

//-----------------------------------------------------------------------------------------------
// First Working Prototype
//#include <iostream>
//#include <fstream>
//#include "C:\Users\ameya\Desktop\DemoDelsys\Maker\dummy\p3\CPlusPlus2\CPlusPlus2\addressbook.pb.h"
//#include <cstring>
//#include <boost/asio.hpp>
//using namespace std;
//using namespace tutorial;
//
//int main() {
//	cout<<"Hello" << endl;
//
//    boost::asio::io_context io_context;
//
//    //// Create a TCP socket
//    boost::asio::ip::tcp::socket socket(io_context);
//
//    // Create an endpoint and connect to the server
//    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234);
//    boost::system::error_code error;
//    socket.connect(endpoint, error);
//    if (error) {
//        std::cerr << "Error connecting to server: " << error.message() << std::endl;
//        return 1;
//    }
//
//    char buffer[1024];
//    boost::system::error_code ec;
//    std::size_t bytes_received;
//    while ((bytes_received = socket.read_some(boost::asio::buffer(buffer), ec)) > 0) {
//        std::cout << "Received: " << std::string(buffer, bytes_received) << std::endl;
//    }
//    if (ec != boost::asio::error::eof) {
//        std::cerr << "Error receiving data: " << ec.message() << std::endl;
//        return 1;
//    }
//
//    socket.close();
//    return 0;
//
//
//}