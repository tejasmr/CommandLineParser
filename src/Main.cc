#include "CommandLineParser.h"

int main( CommandLineArguments ) {
    CommandLineParser clp(ArgumentCount, ArgumentVector);

    clp.print();
}