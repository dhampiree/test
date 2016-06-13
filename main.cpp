#include <iostream>
#include <string>

using namespace std;

class Vizhener 
{
public:
  static string encodeStringWithKey(string stringToEncode, string key)
  {
    int stringLength = stringToEncode.length();
    int keyLength = key.length();
    int numberOfAlpha;
    int numberOfKey;
    char symbol;
    char keySymbol;
    bool isBig;
    bool keySymbolIsBig; 
    
    for (int i = 0; i < stringLength; i++) 
    {
      symbol = stringToEncode[i];

      if (isalpha(symbol) == false)
        continue;

      isBig = isupper(symbol);
      keySymbol = key[i % keyLength];
      keySymbolIsBig = isupper(keySymbol);

      numberOfAlpha = symbol - (isBig ? 'A' : 'a');
      numberOfKey   = keySymbol - (keySymbolIsBig ? 'A' : 'a');
      symbol = (numberOfAlpha + numberOfKey) % 26;

      stringToEncode[i] = symbol + (isBig ? 'A' : 'a');
    }

    return stringToEncode;
  }
};

int main(int argc, char* argv[])
{ 
  if (argc != 2)
    return 1;

  string key = argv[1];
  for (int i = 0; i < key.length(); i++) {
    if (!isalpha(key[i]))
      return 1;
  }

  string stringToEncode;
  cin >> stringToEncode; 

  cout << Vizhener::encodeStringWithKey(stringToEncode, key);
  
  system("pause");
  return 0;
}
