#include "./alphabet.h"
#include <string>

class Word {
 private:
  std::vector<char> word_;
 public:
 /**
  * @brief Construct a new Word object Default
  * 
  */
  Word();
  /**
   * @brief Construct a new Word object using parameter word
   * 
   * @param word 
   */
  Word(std::string word) {SetWord(word);}
  /**
   * @brief Cast a splited word into char vector
   * 
   * @param word 
   */
  void SetWord(std::string word) {
    word_.resize(word.size());
    for (unsigned int i; i < word.size(); i++) {
      word_[i] = word[i];
    }
  }
  /**
   * @brief Cast char vector into a string
   * 
   * @return std::string 
   */
  std::string GetWord() {
    std::string word;
    for (unsigned int i; i < word_.size(); i++) {
      word.push_back(word_[i]);
    }
    return word;
  }
  /**
   * @brief Check if a word is the result of symbols combination (Combinatorics on words)
   * 
   * @param alphabet Set itself
   * @return true 
   * @return false 
   */
  bool CheckAlphabet(Alphabet &alphabet) {
    unsigned int count = 0;
    for (unsigned int value = 0; value < word_.size(); value++) {
      if (alphabet.CheckSymbol(word_[value])) {
        count ++;
      }
    }
    if (count == word_.size()) {
      return true;
    } else {
      return false;
    }
  }
  ~Word();
};