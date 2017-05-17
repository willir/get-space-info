#include <string>
#include <iostream>

#include <boost/filesystem.hpp>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

namespace fs=boost::filesystem;

static void printHelp(int argc, char *argv[], std::ostream &os) {
    os << "Usage: " << argv[0] << " path" << endl << endl
       << "ARGUMENTS:" << endl
       << "    path: Path to directory to print its file system space info" << endl;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cerr << "ERROR: Exactly one argument is expected" << endl << endl;
        printHelp(argc, argv, cerr);
        return 1;
    }

    string path = argv[1];

    try {
        const fs::space_info si = fs::space(path);

        cout << "Space Info of: " << path << endl;
        cout << "available:\t" << si.available << endl;
        cout << "capacity:\t" << si.capacity << endl;
        cout << "free:    \t" << si.free << endl;

    } catch (const fs::filesystem_error &e) {
        cerr << "ERROR getting info about: " << path << endl;
        cerr << "Description: " << e.what() << endl << endl;
        printHelp(argc, argv, cerr);
        return 1;
    }
    return 0;
}
