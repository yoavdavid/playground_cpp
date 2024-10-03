
#include <unordered_map>
#include <string>
#include "basics.h"

using namespace std;

int main() {
    unordered_map<std::string, string> my_map;

    test();

    my_map["woot"] = "woot";
    return 0;
}