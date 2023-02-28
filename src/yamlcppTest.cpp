#include <yaml-cpp/yaml.h>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    std::cout << argv[0] << std::endl;
    // load 和终端路径有关
    YAML::Node config = YAML::LoadFile("../config/config.yaml");
    std::cout << "name:" << config["name"].as<std::string>() << std::endl;
    std::cout << "sex:" << config["sex"].as<std::string>() << std::endl;
    std::cout << "age:" << config["age"].as<int>() << std::endl;
    return 0;
}
