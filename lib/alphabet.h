#include <vector>

class Alphabet {
 private:
  std::vector <char> letters_; // Set of letters
 public:
  /**
   * @brief Construct a new Alphabet object by default
   * 
   */
  Alphabet(){}
  /**
   * @brief Default fill Alphabet with {A-Z} U {a-z} symbols
   * 
   */
  void SetAlphabet() {
    for (unsigned int ascii = 65; ascii <= 90; ascii++)
      InsertSymbol(char(ascii));
    for (unsigned int ascii = 97; ascii <= 122; ascii++)
      InsertSymbol(char(ascii));
  }
 /**
  * @brief Insert a symbol (letter) into an alphabet
  * 
  * @param c Symbol/letter/character
  */
  void InsertSymbol(char c) {letters_.push_back(c);}
  /**
   * @brief Check if letter 'c' ⊆ Alphabet  
   * 
   * @param c letter
   * @return true 
   * @return false 
   */
  bool CheckSymbol(char c) {
    bool is_true;
    for (unsigned int value = 0; value < letters_.size(); value++) {
      if (c == letters_[value])
        is_true = true;
    }
    return is_true;
  }
  ~Alphabet(){}
};