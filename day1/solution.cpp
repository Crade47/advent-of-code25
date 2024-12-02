#include "../config.h"
#include <unordered_map>
class Solution {

public:
  std::vector<int> leftList;
  std::vector<int> rightList;
  int reconsileList() {
    int sum = 0;
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());
    for (int i = 0; i < leftList.size(); i++) {
      sum += std::abs(leftList[i] - rightList[i]);
    }
    return sum;
  }
  void parseInput(std::string &line) {
    line.erase(0, line.find_first_not_of(" \t\n\r"));
    line.erase(line.find_last_not_of(" \t\n\r") + 1);

    std::istringstream iss(line);
    std::string firstNum, secNum;

    while (iss >> firstNum >> secNum) {
      leftList.push_back(std::stoi(firstNum));
      rightList.push_back(std::stoi(secNum));
    }
 
  }
  int calcSimScore(){
    int sum = 0;
    std::unordered_map<int, int> rightListOc;
    for(auto& num : rightList) rightListOc[num]++;
    /*for(auto& num : rightList) {*/
    /*  std::cout << num << std::endl;*/
    /*}*/
    for(int i = 0; i < leftList.size(); i++){
      if(rightListOc.find(leftList[i]) != rightListOc.end()){
        sum = sum + (leftList[i] * rightListOc[leftList[i]]);
      }
    }
    return sum;
  }
};

int main() {
  std::ifstream inputFile(
      "/Users/devansh/codingStuff/advent-of-code24/day1/dayone.input");
  if (!inputFile) {
    std::cout << "unable to open file. Error" << std::strerror(errno)
              << std::endl;
  }
  Solution *sol = new Solution();

  std::string line;
  while (std::getline(inputFile, line)) {
    sol->parseInput(line);
  }
  /*std::cout << "Sum: " << sol->reconsileList() << std::endl;*/
  std::cout << "Similarity Score: " << sol->calcSimScore() << std::endl;

  delete sol;
  inputFile.close();
  return 0;
}
