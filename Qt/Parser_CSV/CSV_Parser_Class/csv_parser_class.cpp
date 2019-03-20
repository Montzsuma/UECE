#include <iomanip>
#include <iostream>
#include <fstream>

#include "csv_parser_class.h"

const std::string kComma{","};
const std::string kErrorMessageUnableToOpenFile{"Unable to open file"};
const std::string kTrueStr{"1"};
const std::string kFalseStr{"0"};

CSV_Parser::CSV_Parser(std::string file_full_path)
{
  std::ifstream inFile;
  inFile.open(file_full_path);
  if (!inFile) {
    std::cout << kErrorMessageUnableToOpenFile << std::endl;
    exit(-1); // Finish with error
  }

  std::string data_line;
  // Skip first line containing column descriptions
  std::getline(inFile, data_line);
  while (std::getline(inFile, data_line))
    ParseLine(data_line);
  inFile.close();
}

const std::vector<CSV_Parser::CSV_Data> &CSV_Parser::data_healthy() const
{
  return data_healthy_;
}

const std::vector<CSV_Parser::CSV_Data> &CSV_Parser::data_failing() const
{
  return data_failing_;
}

void CSV_Parser::ParseLine(const std::string &data_line)
{
  CSV_Data data;
  std::string aux{""};
  size_t value_start = 0;
  size_t comma_pos = data_line.find_first_of(kComma);
  data.date = data_line.substr(value_start, comma_pos);
  if (value_start == std::string::npos) return;

  value_start = comma_pos + 1;
  comma_pos = data_line.find_first_of(kComma, value_start);
  data.serial = data_line.substr(value_start, comma_pos - value_start);
  if (value_start == std::string::npos) return;

  value_start = comma_pos + 1;
  comma_pos = data_line.find_first_of(kComma, value_start);
  data.model = data_line.substr(value_start, comma_pos - value_start);
  if (value_start == std::string::npos) return;

  value_start = comma_pos + 1;
  comma_pos = data_line.find_first_of(kComma, value_start);
  aux = data_line.substr(value_start, comma_pos - value_start);
  data.capacity_in_bytes = std::stoull(aux);
  if (value_start == std::string::npos) return;

  value_start = comma_pos + 1;
  comma_pos = data_line.find_first_of(kComma, value_start);
  aux = data_line.substr(value_start, comma_pos - value_start);
  data.failure = aux == kTrueStr ? true: false;
  if (value_start == std::string::npos) return;

  while (true) {
    value_start = comma_pos + 1;
    if ((comma_pos = data_line.find_first_of(kComma, value_start)) == std::string::npos)
      break;
    if (value_start < comma_pos) {
      std::string aux_2{data_line.substr(value_start, comma_pos - value_start)};
      uint64_t aux_int = static_cast<uint64_t>(std::stod(aux_2));
      data.smart_data.emplace_back(aux_int);
    } else data.smart_data.emplace_back(0);
  }
  FilterAndSaveData(data);
}

void CSV_Parser::FilterAndSaveData(const CSV_Parser::CSV_Data &data)
{
  if (!data.failure) data_healthy_.emplace_back(data);
  else data_failing_.emplace_back(data);
}
