#include <iostream>

#define APP_NAME "MyTool"
//#define DEBUG

int main() {
    std::cout << APP_NAME << '\n';

#ifdef DEBUG 
    std::cout << "debug mode\n";
#endif

}