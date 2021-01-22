#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string get_tag(string s, int* pos, char sep){
    string tmp;
    while ((s[(*pos)] != sep) && (s[(*pos)] != '>')) tmp += s[(*pos)++];
    return tmp;
}

string find_query(vector <string> n, string q, vector <string> v){
    for (int p = 0; p < n.size(); p++){
            if (n[p] == q) return v[p];
    }
    return "Not Found!";    
}

int main(){
    int n, q, i;
    string tag, line1, ftag, fname;
    vector <string> names, values;
    cin >> n >> q;
    cin.ignore();
    for (int j = 0; j < n; j++){ 
        i = 1;
        getline(cin, line1);
        if (line1[i] != '/') {
            if (tag.size() > 0) tag += '.'; 
            tag += get_tag(line1, &i, ' ');
            while (i < (line1.length() - 1)){
                i++;
                names.push_back(tag + '~' + get_tag(line1, &i, ' '));
                i += 4;
                values.push_back(get_tag(line1, &i, '"'));
                i++;
            }
        }
        else {
            int pos_point = 0;
            if (tag.find('.') != -1) pos_point = tag.find('.');
            tag.erase(pos_point);
        }    
    }
    for (int j = 0; j < q; j++){
        getline(cin, line1);
        cout << find_query(names, line1, values) << '\n'; 
    }
    return 0;
}
