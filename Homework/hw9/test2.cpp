#include <vector>
#include <iostream>
using namespace std;

int main() {
    // vector<vector <int> > a(500);
    vector<int>*dic=new vector<int>[499];
    dic[0].push_back(15);
    cout<<dic[0][0];
    //vector <int> *a = new vector<int>;
    //a[0].push_back(1);
    //cout<<"beginning of the vector" << &a<<endl;
    //cout<<"element 1" << &a[0]<<endl;
    //cout<<"element 2" << &a[1]<<endl;
    //cout<<"element 3" << &a[2]<<endl;
}