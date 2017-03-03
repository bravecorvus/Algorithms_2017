
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#include"elapsed_time.h"

struct Dictionary {
  vector<string> wordArray;   // store the data

  vector<string>* dic; //

  Dictionary(const char *filename);  // constructor

  bool inWordArray(string &s);       // single query
  void check(const char *filename);  // multiple queries
  void ana();
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

int hashfunction(string &arg) {
  int hash =0;
  for(int i=0; i<arg.size();++i){
    hash=(137*hash + arg[i])%479833;
  }
  return hash;
}

Dictionary::Dictionary( const char *filename )
{
  dic=new vector<string> [479833];

  ifstream f(filename);
  if ( ! f.good() ) {
    cerr << "Error:  unable to open " << filename << endl;
    exit(-1);
  }
  string s;
  
  while ( f >> s ) dic[hashfunction(s)].push_back(s);//make a dictionry

  //getWords(filename, wordArray);
}

bool Dictionary::inWordArray(string &s){
  //int n = wordArray.size();
    int index=hashfunction(s);
    for(int n=0; n<(dic[index].size()); n++){
      if(s==dic[index][n]){
        return true;
      }
    }
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

void Dictionary::ana(){
  int counter=0;
  int max=0;
  int min=600;
  for(int n=0;n<479833;n++){
    if(dic[n].size()!=0){
      if(dic[n].size()>max){
        max=dic[n].size();
      }
      if(dic[n].size()<min){
        min=dic[n].size();
      }
    }
    //cout<<"index"<<n<<" "<<dic[n].size()<<" "<<endl;
  else
    counter++;
  }
  cout<<"max "<<max<<endl;
  cout<<"min "<<min<<endl;
  cout<<"0 "<<counter<<endl;
}
int main(int argc, char **argv)
{
  if ( argc != 3 ) {
    cerr << "Usage: spellCheck dictionaryFile inputFile" << endl;
    exit(0);
  }
  Dictionary d(argv[1]);
  d.check(argv[2]);
  cout<<"checked"<<endl;
  d.ana();






}