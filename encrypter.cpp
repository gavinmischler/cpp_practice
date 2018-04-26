/* Encrypter and Decrypter
* Takes in a text file and encrypts it, outputs it to a file.
* Then it takes that encrypted file and decrypts it to a new file.
*/

#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

string encodeLine(string &message)
{
  for (int i = 0; i < message.length(); i++)
  {
    if (i%2)
    {
      message[i]++;
    } else
    {
      message[i] += 4;
    }
  }
  return message;
}

string decodeLine(string &encodedmessage)
{
  for (int i = 0; i < encodedmessage.length(); i++)
  {
    if (i%2)
    {
      encodedmessage[i]--;
    } else
    {
      encodedmessage[i] -= 4;
    }
  }
  return encodedmessage;
}

int main()
{
  ifstream in;
  string filename;
  cout << "Enter the name of a text file to be encrypted: ";
  cin >> filename;
  in.open(filename.c_str());
  if (in.fail())
  {
  	cout << ("Couldn't find read text file");
  	return 1;
  }
  //Encrypt each line and output to file
  ofstream outf ("EncryptedMessage.txt");
  while (in.peek() != EOF)
  {
  	string lineoftext;
  	getline(in, lineoftext);
    string encodedline = encodeLine(lineoftext);
    outf << encodedline << "\n";
  }
  in.close();
  outf.close();

  //Decrypt each line and output to a different file
  in.open("EncryptedMessage.txt");
  if (in.fail())
  {
    cout << ("Couldn't find read enctryped message file") << "\n";
  	return 1;
  }

  ofstream outf2("DecryptedMessage.txt");
  while (in.peek() != EOF)
  {
  	string lineofencodedtext;
  	getline(in, lineofencodedtext);
    string decodedline = decodeLine(lineofencodedtext);
    outf2 << decodedline << "\n";
  }
  in.close();
  outf2.close();

  return 0;


}
