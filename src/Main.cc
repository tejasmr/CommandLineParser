#include "CommandLineParser.h"
#include <cassert>

int main( CommandLineArguments ) {
    CommandLineParser clp(ArgumentCount, ArgumentVector);

    clp.print();
    clp.printFlags();
    assert( clp.value("-l").compare("linker") == 0 );
    assert( clp.value("-i").compare("include") == 0 );
}