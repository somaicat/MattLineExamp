// g++ ./mle.cpp -o ./mle
 
#include <fstream>
#include <iostream>
#include <vector>

class LineFile {
public:
LineFile(const std::string &filename = std::string("out.txt")) : _filename(filename) { }

// Add a string to the vector
void AddString(const std::string string) {
  _strings.push_back(string);
}

// Write out the vector of strings to a file
void WriteStringsToFile() {
  std::ofstream file(_filename, std::ios::out | std::ios::trunc); // Open file for output (std::ios::out flag), if one doesn't exist, create it, if it does exist, wipe existing contents (std::ios::trunc flag)

  for (auto str : _strings) { // Loop through the strings vector
    file << str << std::endl; // write the string out with a newline
  }
  file.flush(); // flush output to file
}

// Print all the strings we currently have in memory
void PrintStrings() const {
  unsigned int i=0;
  for (auto str : _strings) {
    std::cout
    << "Line " << i << " \""
    << str << "\"" << std::endl;

    i++;
  }
}

const std::string GetFilename() { return _filename; } // This function is called a getter, in c++, you often don't want to provide direct access to members of a class, it is more flexible and robust to instead provide access to members of a class via getter and setter methods like this one

private:
std::vector<std::string> _strings;
const std::string &_filename;
};

int main() // in C you usually write a main that takes no argument as main(void), for obscure technical reasons you don't need to do that in c++, although you can if you prefer to as a matter of style.
{
  using namespace std; // I have put this here so I don't have to put std:: in front of everything. I could have put it at the beginning of the file but I wanted the LineFile class to not have it so it could be easily moved to a header if prefered.
  LineFile lineFile; // We haven't supplied a file name, so out.txt will be the default, if we want though we could instance the object with LineFile lineFile("someothername.txt");

  cout 
  << "Welcome to Matts Line Example, currently writing to "
  << lineFile.GetFilename()
  << endl
  << "Enter an empty line to exit the program"
  << endl; 
    
  string input;

  do {
    cout << "Enter line: ";
    getline(std::cin, input); // Get a line from cin and put it in the input string
    lineFile.AddString(input); // Add it to the lineFile
  } while (input.length() != 0); // While input string has a length above zero, read in lines. when it hits a line of zero, we're done

  cout << endl << "Finished, you entered the following lines" << endl;
  lineFile.PrintStrings();
  cout << endl << "Writing them to file..." << endl;
  lineFile.WriteStringsToFile();
  cout << endl << "Complete!" << endl;

  return 0;
}
