#ifndef CSV_PARSER_CLASS_H
#define CSV_PARSER_CLASS_H

#include <array>
#include <set>
#include <string>
#include <vector>

class CSV_Parser
{
  struct CSV_Data{
    std::string date{""};
    std::string serial{""};
    std::string model{""};
    uint64_t capacity_in_bytes = 0;
    bool failure{false};
    std::vector<uint64_t> smart_data;
  };
public:
  CSV_Parser(std::string file_full_path);
  const std::vector<CSV_Data> &data_healthy() const;
  const std::vector<CSV_Data> &data_failing() const;
private:
  void ParseLine(const std::string &data_line);
  void FilterAndSaveData(const CSV_Data &data_healthy);
  std::vector<CSV_Data> data_healthy_;
  std::vector<CSV_Data> data_failing_;
};

#endif // CSV_PARSER_CLASS_H
