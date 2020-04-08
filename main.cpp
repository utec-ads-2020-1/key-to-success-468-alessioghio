#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

void countAndMap(string input, vector<pair<char, int>>& myMap);

int main(){
    string coded, decoded, temp;
    stringstream ss;
    int iter;
    vector<pair<char, int>> chCntCoded, chCntDecoded;
    getline(cin, coded);
    ss.str(coded);
    ss >> iter;
    ss.clear();
    getline(cin, coded); // Ignore blank line
    
    for (int i = 0; i < iter; i++){
        getline(cin, coded);
        sort(coded.begin(), coded.end());
        countAndMap(coded, chCntCoded);
        sort(chCntCoded.begin(), chCntCoded.end(),
            [](pair<char, int> a, pair<char, int> b){ return (a.second < b.second);});
        getline(cin, decoded);
        temp = decoded;
        sort(temp.begin(), temp.end());
        countAndMap(temp, chCntDecoded);
        sort(chCntDecoded.begin(), chCntDecoded.end(),
            [](pair<char, int> a, pair<char, int> b){ return (a.second < b.second);});
        // Decode
        for(char& c : decoded){
            for (int idx = 0; idx < chCntDecoded.size(); idx++){
                if(c == chCntDecoded[idx].first){
                    c = chCntCoded[idx].first;
                    break;
                }
            }
            cout << c;
        }
        cout << endl;
        if(i!=iter-1){
            cout << endl;
            getline(cin, coded); // ignore blank line
        }
        chCntCoded.clear();
        chCntDecoded.clear();
    }
    
    return EXIT_SUCCESS;
}

void countAndMap(string input, vector<pair<char, int>>& myMap){
    char ch = ' ';
    int idx = -1;
    for (int i = 0; i < input.size(); i++){
        if(ch!=input[i]){
            idx++;
            ch = input[i];
            myMap.push_back(make_pair(ch, 1));
        }else{
            myMap[idx].second += 1;
        }
    }
}