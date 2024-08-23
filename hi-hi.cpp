#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

int strcmp_case_insensitive(string string1, string string2) {
    int comparison, shortestString;
    comparison = 0;

    // Setting a common range
    shortestString = string1.length();
    if (string2.length() < string1.length()){
        shortestString = string2.length();
    }

    // Comparing each charachter in the common range
    for (int i = 0; i < shortestString; i++){
        if (comparison == 0) {
            if (string1[i] != string2[i]){
                if (tolower(string1[i]) < tolower(string2[i])){
                    comparison = -1;
                }
                if (tolower(string1[i]) > tolower(string2[i])){
                    comparison = 1;
                }
            }
        }
    }

    // Acounting for the case that the strings are of different lengths
    if (string1.length() != string2.length()) {
        if (string1.length() < string2.length() && comparison == 0) {
            comparison = -1;
        }
        if (string1.length() > string2.length() && comparison == 0) {
            comparison = 1;
        }
    }
    return comparison;
}

int main() {
    // the stricmp() / abs(stricmp()) is because stricmp() returns values exceding -1 to 1
    // Testing "string one" vs. "string two"
    cout << "The strcmp_case_insensitive comparison of \"string one\" and \"string two\" returns " << strcmp_case_insensitive("string one", "string two") << ".\n";
    cout << "The strcmp comparison of \"string one\" and \"string two\" returns " << stricmp("string one", "string two")/abs(stricmp("string one", "string two")) << ".\n";
    assert(stricmp("string one", "string two")/abs(stricmp("string one", "string two")) == strcmp_case_insensitive("string one", "string two"));

    // Testing "string one" vs. "string one"
    cout << "The strcmp_case_insensitive comparison of \"string one\" and \"string one\" returns " << strcmp_case_insensitive("string one", "string one") << ".\n";
    cout << "The strcmp comparison of \"string one\" and \"string one\" returns " << stricmp("string one", "string one") << ".\n";
    assert(stricmp("string one", "string one") == strcmp_case_insensitive("string one", "string one"));

    // Testing "string two" vs. "string one"
    cout << "The strcmp_case_insensitive comparison of \"string two\" and \"string one\" returns " << strcmp_case_insensitive("string two", "string one") << ".\n";
    cout << "The strcmp comparison of \"string two\" and \"string one\" returns " << stricmp("string two", "string one") / abs(stricmp("string two", "string one")) << ".\n";
     assert(stricmp("string two", "string one") / abs(stricmp("string two", "string one")) == strcmp_case_insensitive("string two", "string one"));

    // Testing "String one" vs. "string tWo"
    cout << "The strcmp_case_insensitive comparison of \"String one\" and \"string tWo\" returns " << strcmp_case_insensitive("String one", "string tWo") << ".\n";
    cout << "The strcmp comparison of \"String one\" and \"string tWo\" returns " << stricmp("String one", "string tWo") / abs(stricmp("String one", "string tWo")) << ".\n";
    assert(stricmp("String one", "string tWo") / abs(stricmp("String one", "string tWo")) == strcmp_case_insensitive("String one", "string tWo"));

    // Testing "String one" vs. "string One"
    cout << "The strcmp_case_insensitive comparison of \"String one\" and \"string One\" returns " << strcmp_case_insensitive("String one", "string One") << ".\n";
    cout << "The strcmp comparison of \"String one\" and \"string One\" returns " << stricmp("String one", "string One") << ".\n";
    assert(stricmp("String one", "string One") == strcmp_case_insensitive("String one", "string One"));

    // Testing "sTring two" vs. "string onE"
    cout << "The strcmp_case_insensitive comparison of \"sTring two\" and \"string onE\" returns " << strcmp_case_insensitive("sTring two", "string onE") << ".\n";
    cout << "The strcmp comparison of \"sTring two\" and \"string onE\" returns " << stricmp("sTring two", "string onE") / abs(stricmp("sTring two", "string onE")) << ".\n";
    assert(stricmp("sTring two", "string onE") / abs(stricmp("sTring two", "string onE")) == strcmp_case_insensitive("sTring two", "string onE"));

    // Testing "string 2" vs. "string two"
    cout << "The strcmp_case_insensitive comparison of \"string 2\" and \"string two\" returns " << strcmp_case_insensitive("string 2", "string two") << ".\n";
    cout << "The strcmp comparison of \"string 2\" and \"string two\" returns " << stricmp("string 2", "string two") / abs(stricmp("string 2", "string two")) << ".\n";
    assert(stricmp("string 2", "string two") / abs(stricmp("string 2", "string two")) == strcmp_case_insensitive("string 2", "string two"));

    // Testing "string two" vs. "string tw"
    cout << "The strcmp_case_insensitive comparison of \"string two\" and \"string tw\" returns " << strcmp_case_insensitive("string two", "string tw") << ".\n";
    cout << "The strcmp comparison of \"string two\" and \"string tw\" returns " << stricmp("string two", "string tw")/abs(stricmp("string two", "string tw")) << ".\n";
    assert(stricmp("string two", "string tw")/abs(stricmp("string two", "string tw")) == strcmp_case_insensitive("string two", "string tw"));
    return 0;
}