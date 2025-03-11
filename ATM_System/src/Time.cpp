#include <iostream> // in/out stream
#include <sstream> // string stream
#include <vector> // container to save accounts && transactions
#include <memory> // for smart pointer (shared)
#include <string_view> // lightweight string lib
#include <algorithm> // sorting algorithms
#include <ctime> // get current time
#include <iomanip> // manipulation formating of time


std::string getCurrentTime()
{
    std::ostringstream oss; // format time output
    std::time_t now = std::time(nullptr); // get current system time
    oss << std::put_time(std::localtime(&now), "%Y-%M-%D %H:%M:%S"); // YYYY - MM - DD  HH:MM:SS
    return oss.str();
}
