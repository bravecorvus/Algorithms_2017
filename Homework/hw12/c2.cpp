#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int converttoascii(string arg, int index) {
    int i = arg[index];
    return(i);
}

int binarysearch(vector<string>array, string query) {
    int midpoint = array.size()/2;
    for (vector<string>::iterator z=array.begin(); z !=array.end(); ++ z) {
        cout << ' ' << *z;
    }
    cout << "\n" << endl;
    int index = 0;
    if (array.size() == 2) {
        if (array[0].length() == array[1].length()) {
            int a0 = converttoascii(array[0], 0); int a1 = converttoascii(array[1], 0);
            if ((a0 == converttoascii(query, 0)) && (query.length() == array[0].length())) {
                bool z = true;
                for (int i = 0; i < query.length(); ++i) {
                    if (converttoascii(query, i) != converttoascii(array[0], i)) {
                        z = false;
                        break;
                    }
                }
                if (z) {
                    index = 0;
                }
            }
            if ((a1 == converttoascii(query, 0)) && (query.length() == array[1].length())) {
                bool z = true;
                for (int i = 0; i < query.length(); ++i) {
                    if (converttoascii(query, i) != converttoascii(array[1], i)) {
                        z = false;
                        break;
                    }
                }
                if (z) {
                    index = 1;
                } else {
                    index = -1;
                }
            }
        } else {
            if (query.length() == array[0].length()) {
                bool z = true;
                for (int i = 0; i < query.length(); ++i) {
                    if (converttoascii(query, i) != converttoascii(array[0], i)) {
                        z = false;
                        break;
                    }
                }
                if (z) {
                    index = 0;
                }
            }
            if (query.length() == array[1].length()) {
                bool z = true;
                for (int i = 0; i < query.length(); ++i) {
                    if (converttoascii(query, i) != converttoascii(array[1], i)) {
                        z = false;
                        break;
                    }
                }
                if (z) {
                    index = 1;
                }
            } else {
                index = -1;
            }
        }
    } else if (array.size() == 1) {
        cout << "array size = 1" << endl;
        bool z = true;
        if (array[0].length() > query.length()) {
            cout << "array > query" << endl;
            for(int i = 0; i < query.length(); ++i) {
                if (converttoascii(array[0], i) != converttoascii(query, i)) {
                    z = false;
                    break;
                }
            }
            if (z) {
                index = 0;
            } else {
                index = -1;
            }
        } else if (array[0].length() <= query.length()) {
            cout << "array <= query" << endl;
            for(int i = 0; i < array[0].length(); ++i) {
                if (converttoascii(array[0], i) != converttoascii(query, i)) {
                    z = false;
                    break;
                }
            }
            if (z) {
                index = 0;
            } else {
                index = -1;
            }
        }
    } else {
        cout << "ELSE" << endl;
        cout << "midpoint " << midpoint << endl;
        int midpointascii = converttoascii(array[midpoint], 0);
        int queryascii = converttoascii(query, 0);
        if (midpointascii > queryascii) {
            cout << "if (midpointascii > queryascii)" << endl;
            vector<string> newarray(&array[0],&array[midpoint]);
            index = binarysearch(newarray, query);
        } else if (midpointascii < queryascii) {
            cout << "else if (midpointascii < queryascii)" << endl;
            vector<string> newarray(&array[midpoint+1],&array[array.size()]);
            index = binarysearch(newarray, query);
            if (index >= 0) {
                index += midpoint;
            }
        } else if (midpointascii == queryascii) {
            // (array[midpoint].length() == query.length())
            if (query.size() == array[midpoint].size()) {
                int tempindex = 0;
                bool tempbool = true;
                for (int i = 0; i < query.size(); ++i) {
                    ++tempindex;
                    if (converttoascii(query, i) != converttoascii(array[midpoint], i)) {
                        ++tempindex;
                        tempbool = false;
                        break;
                    }
                }
                if (tempbool) {
                    index = midpoint;
                } else {
                    if (converttoascii(array[midpoint], tempindex) > converttoascii(query, tempindex)) {
                        vector<string> newarray(&array[0],&array[midpoint]);
                        index = binarysearch(newarray, query);
                    } else if (converttoascii(array[midpoint], tempindex) < converttoascii(query, tempindex)){
                        vector<string> newarray(&array[midpoint+1],&array[array.size()]);
                        index = binarysearch(newarray, query);
                        if (index >= 0) {
                            index += midpoint;
                        }
                    }
                }
            } else if (query.size() > array[midpoint].size()) {
                int tempindex = 0;
                bool tempbool = true;
                for (int i = 0; i < array[midpoint].size(); ++i) {
                    ++tempindex;
                    if (converttoascii(query, i) != converttoascii(array[midpoint], i)) {
                        ++tempindex;
                        break;
                    }
                }
                if (converttoascii(array[midpoint], tempindex) > converttoascii(query, tempindex)) {
                    vector<string> newarray(&array[0],&array[midpoint]);
                    index = binarysearch(newarray, query);
                } else if (converttoascii(array[midpoint], tempindex) < converttoascii(query, tempindex)) {
                    vector<string> newarray(&array[midpoint+1],&array[array.size()]);
                    index = binarysearch(newarray, query);
                    if (index >= 0) {
                        index += midpoint;
                    }
                }
            } else if (query.size() < array[midpoint].size()) {
                int tempindex = 0;
                bool tempbool = true;
                for (int i = 0; i < query.size(); ++i) {
                    ++tempindex;
                    if (converttoascii(query, i) != converttoascii(array[midpoint], i)) {
                        ++tempindex;
                        break;
                    }
                }
                if (converttoascii(array[midpoint], tempindex) > converttoascii(query, tempindex)) {
                    vector<string> newarray(&array[0],&array[midpoint]);
                    index = binarysearch(newarray, query);
                } else if (converttoascii(array[midpoint], tempindex) < converttoascii(query, tempindex)) {
                    vector<string> newarray(&array[midpoint+1],&array[array.size()]);
                    index = binarysearch(newarray, query);
                    if (index >= 0) {
                        index += midpoint;
                    }
                }
            }
        }
    }
    return(index);
}

void arrayhandler(vector<string>array, string query) {
    int result = binarysearch(array, query);
    if (result < 0) {
        cout << "Query not found in array\n" << endl;
    } else {
        cout << "Query found in array at index " << result << "\n" <<endl;
    }
}

int main() {
    vector<string> array;
    string p[] = {"abdel-rahmanmadkour", "anderswahlberg", "andrewlee", "andrewaltmaier", "biditsharma", "deandrebauswell", "deepakshah", "elifyurtseven", "jesuscaballero", "johnhamby", "johnstone", "jonathanlenz", "josephpeterson", "joshuacarlin", "lukezimmerman", "mazenabusharkh", "muchenge", "nadiaelmouldi", "nikeshyadav", "olafhall-holt", "rachelfrantsen", "rossnesbit", "tianyupang", "wassimaskoul", "yankuntai"};
    size_t size = sizeof(p)/sizeof(string);
    cout << size << endl;
    for (int i = 0; i < sizeof(p)/sizeof(string); ++i) {
        array.push_back(p[i]);
    }
    string userinput;
    while(true) {
        cout << "enter search query" << endl;
        cin >> userinput;
        arrayhandler(array, userinput);
    }
}