#include <fstream>
#include <iostream>

static void	ft_replace(std::ifstream *input, std::ofstream *output, 
	const std::string &original, const std::string &modified) {
	std::string line;
	
	while(std::getline(*input, line)) {
		int flagReplace = line.find(original);
		if (line.length() < 1) {
			*output << std::endl;
			continue;
		}
		while (flagReplace != std::string::npos) {
			*output << line.substr(0, flagReplace);
			*output << modified;
			line = line.substr(flagReplace + original.length());
			flagReplace = line.find(original);
		}
		*output << line;
		if (!input->eof())
			*output << std::endl;
	}
}

int main(int argc, char **argv) {
	if (argc <= 3) {
		std::cout << "Error: invalid number of parameters!" << std::endl;
		return (1);
	}
	
	std::string 	inputFile(argv[1]);
	std::ifstream	input(inputFile.c_str());
	
	if (!input) {
		std::cout << "Error: insert a valid filename!" << std::endl;
		return (1);
	}

	std::string		s1(argv[2]);
	std::string		s2(argv[3]);

	if (s1.length() < 1) {
		std::cout << "Error: string to replace cannot be empty!" << std::endl;
		return (1);
	}
	
	std::string		outputFile = inputFile + ".replace"; 
	std::ofstream	output(outputFile, std::ios::app);
	
	if (!output) {
		std::cout << "Error: unable to create output file!" << std::endl;
		return (1);
	}
	
	ft_replace(&input, &output, s1, s2);
	
	input.close();
	output.close();
	return (0);
}

///////////////////////////////////////////////////

std::string replace(const std::string &source, const std::string &find,
                        const std::string &replace) {
  std::string newString;
  newString.reserve(source.length());
  size_t lastPos = 0;
  size_t findPos;
  while ((findPos = source.find(find, lastPos)) != std::string::npos) {
    newString.append(source, lastPos, findPos - lastPos);
    newString += replace;
    lastPos = findPos + find.length();
  }
  newString += source.substr(lastPos);
  return newString;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return 1;
  }
  std::ifstream inputFile(argv[1]);
  if (!inputFile) {
    std::cerr << "Failed to open " << argv[1] << std::endl;
    return 1;
  }
  std::string content((std::istreambuf_iterator<char>(inputFile)),
                      std::istreambuf_iterator<char>());
  std::ofstream outputFile((std::string(argv[1]) + ".replace").c_str());
  if (!outputFile) {
    std::cerr << "Failed to create output file." << std::endl;
    return 1;
  }
  if (content.size())
    outputFile << replace(content, argv[2], argv[3]);
  else
    std::cerr << "Empty file." << std::endl;
  return 0;
}


////////////////////////////////////////////////////////////////////
int main(int ac, char **av)
{
    if (ac != 4)
    {
		std::cout << "Bad number of inputs" << std::endl;
		return (0);
    }

    //necessary variables
    std::string out_name = std::string(av[1]) + ".replace";
    std::string buffer;
    std::string temp;
    std::string str_search = av[2];
    std::string str_replace = av[3];
    size_t      start;
    size_t      index;
    size_t      len;

    //preparing files and open error checking
    std::remove(out_name.c_str());
    std::ifstream infile(av[1]);
    std::ofstream outfile(out_name.c_str());

    if (!infile.is_open())
    {
		std::cerr << "Error: infile open failed" << std::endl;
		return (1);
    }
    if (!outfile.is_open())
    {
		std::cerr << "Error: outfile open failed" << std::endl;
		infile.close();
		return (1);
    }

    // main block
    len = str_search.size();
	if (len == 0)
	{
    	infile.close();
    	outfile.close();
   		return (0);
	}
    start = 0;
    index = 0;
    while (std::getline(infile, temp))
    {
		//Getline "extracts and discards" the '\n', if it finds a '\n',
		//it will stop there but won't receive an eof indication.
		//So, no eof means there is a newline that was discarded.
		//Add it back to the string cause it may be part of the "str_search".
		if (!infile.eof())
	    	temp += "\n";

		// merge the leftovers of the buffer with what was read now
		buffer = buffer.substr(start) + temp;
		start = 0;
		index = 0;
		while (1)
		{
	    	// moved past the buffer, ask for more characters from std::getline
	    	if (start >= buffer.size())
				break ;

	    	// find str_search in the buffer
	    	index = buffer.find(str_search, start);
	    	if (index != std::string::npos)
	    	{
				outfile << buffer.substr(start, index - start);
				outfile << str_replace;
				start += (index - start + len);
	    	}
	    	//str_search wasn't found, but "\n" may be a part of the substring
	    	//dump all except len of str_search to guarantee you don't cut a
	    	//potential candidate in half
	    	else if (start + len < buffer.size())
	    	{
				outfile << buffer.substr(start, buffer.size() - len - start);
				start = buffer.size() - len;
				break ;
	    	}
	    	// buffer is smaller than len str_search, take no risks and ask for more
	    	// characters to std::getline
	    	else
				break ;
		}
    }
    // dump whatever is left on the buffer to outfile
    if (start < buffer.size())
		outfile << buffer.substr(start);

    //clean up
    infile.close();
    outfile.close();

    return (0);
}