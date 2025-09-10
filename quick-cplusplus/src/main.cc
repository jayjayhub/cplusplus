#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

namespace fs = std::filesystem;

using WordVector = std::vector<std::string>;
using WordCountPair = std::pair<std::string, std::size_t>;
using CountedWordsMap = std::map<std::string, std::size_t>;

// std::string readFile(std::string path) {
//   std::ifstream file(path);
//   if (!file) {
//     throw std::runtime_error("Cannot open file: " + path);
//   }
//   std::string content;
//   std::string line;
//   while (std::getline(file, line)) {
//     content += line + '\n';
//   }
//   return content;
// }

#include <sstream>
std::string readFile(const std::string& filepath) {
  std::ifstream file(filepath);
  if (!file) {
    throw std::runtime_error("Cannot open file: " + filepath);
  }

  std::ostringstream buffer;
  std::string line;
  while (std::getline(file, line)) {
    buffer << line << '\n';
  }
  return buffer.str();
}

// // C++20 approach
// std::vector<std::string> split(const std::string& str, char separator) {
//     std::vector<std::string> tokens;

//     for (const auto& token : str | std::views::split(separator)) {
//         tokens.emplace_back(token.begin(), token.end());
//     }

//     return tokens;
// }

// C++11/17
// #include <regex>
// std::vector<std::string> split(const std::string& str, const std::string&
// separator) {
//     std::regex regex(separator);
//     return std::vector<std::string>(
//         std::sregex_token_iterator(str.begin(), str.end(), regex, -1),
//         std::sregex_token_iterator()
//     );
// }

// C++11
WordVector split_text(const std::string& str, char separator) {
  WordVector tokens;
  std::stringstream ss(str);
  std::string token;

  // std::getline reads until it finds the separator character
  while (std::getline(ss, token, separator)) {
    tokens.push_back(token);
  }

  return tokens;
}

template <typename T>
void print_vector(const std::vector<T>& vec) {
  for (std::size_t i = 0; i < vec.size() - 1; i++) {
    std::cout << vec[i] << ", ";
  }
  std::cout << vec[vec.size() - 1] << std::endl;
}

CountedWordsMap count_words(const WordVector& tokens) {
  auto result = CountedWordsMap{};
  for (const auto& token : tokens) {
    result[token]++;
  }
  return result;
}

template <typename T, typename U>
void print_map(const std::map<T, U> map) {
  for (const auto& [key, value] : map) {
    std::cout << key << ": " << value << "\n";
  }
}

int main() {
  auto current_path = fs::current_path();
  current_path /= "data/text.txt";
  std::cout << current_path << std::endl;
  std::string path = current_path.string();
  auto text = readFile(path);
  std::cout << text << '\n' << '\n';

  auto splitted_text = split_text(text, ' ');
  print_vector(splitted_text);

  // /* Your exercise here */
  auto counted_words = count_words(splitted_text);
  print_map(counted_words);

  return 0;
}
