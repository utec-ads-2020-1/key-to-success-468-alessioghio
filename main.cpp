#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

void countAndMap(string input, map<char, int>& myMap);

int main(){
    string coded, decoded;
    stringstream ss;
    int iter;
    map<char, int> chCntCoded;
    map<char, int> chCntDecoded;
    while (getline(cin, coded)){
        ss.str(coded);
        ss >> iter;
        ss.clear();

        getline(cin, coded); // Ignore blank line
        for (int i = 0; i < iter; i++){
            getline(cin, coded);
            sort(coded.begin(), coded.end());
            countAndMap(coded, chCntCoded);            
            getline(cin, decoded);
            countAndMap(decoded, chCntDecoded);
            if(i!=iter-1){
                getline(cin, coded); // ignore blank line
            }
        }
        
    }
    
    return EXIT_SUCCESS;
}

void countAndMap(string input, map<char, int>& myMap){
    char ch = ' ';
    for (int i = 0; i < input.size(); i++){
        if(ch!=input[i]){
            ch = input[i];
            myMap.insert(make_pair(ch, 1));
        }else{
            myMap[ch] += 1;
        }
    }
}