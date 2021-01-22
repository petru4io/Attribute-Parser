#include <iostream>
#include <vector>
#include <string>
using namespace std;

string get_tag(string s, int* pos, char sep){
    string tmp;
    while (s[*pos] != sep) tmp += s[(*pos)++];
    return tmp;
}




int main(){
    int n, q, i = 1;
    string tag, line;
    vector <string> tags;
    vector <vector <string>> names, values;
    names.resize(5);
    values.resize(5);
    //cin >> n >> q;
    // getline(cin, line);
    line = "<tag1 v1 = \"ad\" v2 = \"gd\">";
    if (line[i] != '/') {
        if (tag.size() > 0) tag += '.'; 
        tag += get_tag(line, &i, ' ');
        tags.push_back(tag);
        while (i < (line.size() - 1)){
            i++;
            names[0].push_back(get_tag(line, &i, ' '));
            i += 4;
            values[0].push_back(get_tag(line, &i, '"'));
            i++;
        }
    }
    cout << tags[0] << '\n' << values[0][0] << '\n'<< values[0][1];
    

    return 0;
}
