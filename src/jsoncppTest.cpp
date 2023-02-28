#include <jsoncpp/json/json.h>
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

int main(int argc, char const *argv[])
{
    Json::Reader reader;
    Json::Value Root;
    string path = "../config/config.json";
    std::ifstream ifs;
    ifs.open(path);
    assert(ifs.is_open());

    if(!reader.parse(ifs, Root)) {
        cerr << "parse failed \n";
		return -1; 
    }
    if(Root["name"].isString()) {
        auto name = Root["name"];
        cout << name << endl;
    }
    if(Root["age"].isInt()) {
        auto age = Root["age"];
        cout << age << endl;
    }
    if(Root["sex"].isString()) {
    auto sex = Root["sex"];
    cout << sex << endl;
    }
    if(Root["Point"].isArray()) {
    auto Point = Root["Point"];
    cout << Point[0]  << " " << Point[1] << " "<< Point[2] << endl;
    }    
    ifs.close();
    return 0;
}
