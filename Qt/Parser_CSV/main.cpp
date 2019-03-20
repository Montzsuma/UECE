#include <iostream>
#include <string>

#include "CSV_Parser_Class/csv_parser_class.h"

using namespace std;

const std::string file_full_path{"C:/Users/lucas/Documents/Workspaces/Qt/data_Q4_2018/2018-10-01.csv"};
const std::string file_relative_path{"data_Q4_2018\\2018-10-01.csv"};

int main()
{
  CSV_Parser parser(file_full_path);
  std::cout << parser.data_healthy().size() + parser.data_failing().size()
            << std::endl;
  return 0;
}
