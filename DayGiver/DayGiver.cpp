
#include <iostream>
#include <time.h>

//https://cpp.hotexamples.com/examples/-/-/localtime_s/cpp-localtime_s-function-examples.html
//https://www.w3schools.com/cpp/cpp_switch.asp

int main()
{
    time_t rawtime;
    struct tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);

    //tm_wday is 'days since Sunday', Sunday being 0
    int dayNum = timeinfo.tm_wday;

    switch (dayNum) {
    case 1:
        std::cout << "Monday";
        break;
    case 2:
        std::cout << "Tuesday";
        break;
    case 3:
        std::cout << "Wednesday";
        break;
    case 4:
        std::cout << "Thursday";
        break;
    case 5:
        std::cout << "Friday";
        break;
    case 6:
        std::cout << "Saturday";
        break;
    case 0:
        std::cout << "Sunday";
        break;
    }

}
