#include <iostream>
#include <boost/program_options.hpp>
#include <functional>
#include <fstream>

using namespace boost::program_options;

void init_options(int argc, char* argv[], std::string& filepath, int& parameter, int& numbilets);
int get_hash_in_range(const std::string& fio, const int& parameter, const int& n);

std::hash<std::string> s_hash;

int main(int argc, char* argv[]) {
    std::string filepath;
    int parameter, num;
    init_options(argc, argv, filepath, parameter, num);
    std::ifstream file{filepath};
    if (!file) {
        throw std::runtime_error("No such file");
    }
    for (std::string line; std::getline(file, line);) {
            std::cout << line << ": " <<  get_hash_in_range(line, parameter, num) << std::endl;
    }
    return 0;
}


void init_options(int argc, char* argv[], std::string& filepath, int& parameter, int& numbilets){
    options_description desc{"Options"};
    desc.add_options()
            ("help,h", "Show help")
            ("file,f",value<std::string>(&filepath)->default_value("fio.txt"), "set path to file")
            ("numbilets,n", value<int>(&numbilets)->default_value(10), "set number of bilets")
            ("parameter,p", value<int>(&parameter)->default_value(0), "set value of parameter");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);
}

int get_hash_in_range(const std::string& fio, const int& parameter, const int& n){
    auto r1 = s_hash(fio);
    auto r2 = s_hash(std::to_string(parameter));

    size_t x = 3571;    // prime number

    return (r1 * x * x + r2 * x) % n + 1;
}