#ifndef COMMANDLINEPARSER_COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_COMMANDLINEPARSER_H

#include <iostream>
#include <vector>
#include <string>

#define CommandLineArguments int argc, char** argv
#define ArgumentCount argc
#define ArgumentVector argv

class CommandLineParser {
private:
    void generateFlags();
public:
    int count;
    char** vector;
    std::vector<std::pair<std::string, std::string> > flags;
    
    CommandLineParser( int &_argc, char** &_argv );
    void print();
    std::string value( std::string flag );
    void printFlags();
};
CommandLineParser::CommandLineParser( int &_argc, char** &_argv ) {
    count = _argc;
    vector = _argv;
}

void CommandLineParser::print() {
    std::cout << "ArgumentCount: " << count-1 << std::endl;
    std::cout << "Executable Name: " << vector[0] << std::endl;

    for ( int i=1; i<count; i++ ) {
        std::cout << "Argument " << i << ": " << vector[i] << std::endl;
    }
}

std::string CommandLineParser::value( std::string flag ) {
    for( std::vector<std::pair<std::string, std::string> >::iterator it = flags.begin(); it != flags.end(); it++ ) {
        if( it->first == flag )
            return it->second;
    }
    return "";
}

void CommandLineParser::generateFlags() {
    for( int i=2; i<count; i+=2 ) {
        flags.push_back( std::make_pair( std::string(vector[i-1]), std::string(vector[i]) ) );
    }
}

void CommandLineParser::printFlags() {
    std::cout << "Flags Begin" << std::endl;
    for( std::vector<std::pair<std::string, std::string> >::iterator it = flags.begin(); it != flags.end(); it++ ) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    std::cout << "Flags End" << std::endl;
}

#endif