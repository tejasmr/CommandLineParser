# CommandLineParser: Single Header file to encapsulte the Command Line Arguments

## Header File
Find the file in include/CommandLineParser.h

## Docs
```cpp
// Argumant Count
int count;
// Argument Vector
char** vector;
// List of flags with their corresponding values
std::vector<std::pair<std::string, std::string> > flags;

// Print the CommandLineArguments
void print();
// Value for a flag
std::string value( std::string flag );
// Print all the flags with their corresponding values
void printFlags();
```

## Usage

### Build and run
```bash
g++ Main.cc -o application
./application -l linker -i include
```

### Using CommandLineParser

```cpp
int main() {
    CommandLineParser clp(ArgumentCount, ArgumentVector);

    std::string lValue = clp.value("-l"); // linker
    std::string iValue = clp.value("-i"); // include
}
```