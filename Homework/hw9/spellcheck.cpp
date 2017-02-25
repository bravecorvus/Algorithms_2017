#include <typeinfo>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#include"elapsed_time.h"

int hashfunction(string arg) {
    char b[arg.size()];
    for(int i = 0; i < arg.size(); ++i) {
        b[i] = arg[i];
    }
    int first = b[0];
    int last = b[sizeof(b)/sizeof(char)-1];
    int second;
    if (sizeof(b)/sizeof(char) == 1) {
        second = last;
    } else {
        second = b[1];
    }
    int modthis = 499;
    return(second * (first+last)%modthis);
}

struct Dictionary {
  vector<string> wordArray;   // store the data
  vector<string> *hasheddictionary;
  Dictionary(const char *filename);  // constructor

  bool inWordArray(string &s);       // single query
  void getWordsFromDictionary(const char *, vector<string>*);
  void check(const char *filename);  // multiple queries
};

void getWords( const char *filename, vector<string> &vec )
{
  ifstream f(filename);
  if ( ! f.good() ) {
    cerr << "Error:  unable to open " << filename << endl;
    exit(-1);
  }
  string s;
  while ( f >> s ) vec.push_back(s);
}

void getWordsFromDictionary( const char *filename,  vector<string> *hasheddictionary)
{
  ifstream f(filename);
  if ( ! f.good() ) {
    cerr << "Error:  unable to open " << filename << endl;
    exit(-1);
  }
  string s;
  // while ( f >> s ) gethash()
  while ( f >> s ) {
    hasheddictionary[hashfunction(s)].push_back(s);
    // cout << typeid((hasheddictionary[hashfunction(s)])).name() << endl;
  }
}

Dictionary::Dictionary( const char *filename )
{
  hasheddictionary = new vector <string> (500);
  getWordsFromDictionary(filename, hasheddictionary);
}

bool Dictionary::inWordArray(string &s)
{
  int index = hashfunction(s);
  int n = hasheddictionary[index].size();
  for (int i = 0; i < n; ++i)
    if ( s == hasheddictionary[index][i] ) return true;
  return false;
}



void Dictionary::check( const char *filename )
{
  vector<string> query;
  getWords(filename, query);

  start_timer();  // from elapsed_time.h

  int counter = 0, n = query.size();
  for ( int i = 0; i < n; ++i ) {
    if ( ! inWordArray(query[i]) ) {
      // cout << query[i] << " ";
      ++counter;
    }
  }
  cout << "Misspelled " << counter << " words." << endl;

  double cycles = elapsed_time();
  cout << " Total cycles: " << cycles << endl;
}

int main(int argc, char **argv)
{
  if ( argc != 3 ) {
    cerr << "Usage: spellCheck dictionaryFile inputFile" << endl;
    exit(0);
  }
  Dictionary d(argv[1]);
  d.check(argv[2]);
}