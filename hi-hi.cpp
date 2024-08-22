#include <cstring>
#include <cassert>
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
        if (string1[i] != string2[i]){
            if (tolower(string1[i]) < tolower(string2[i])){
                comparison = -1;
            }
            if (tolower(string1[i]) > tolower(string2[i])){
                comparison = 1;
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
    // Testing "string one" vs. "string two"
    assert(strcmp("string one", "string two") == strcmp_case_insensitive("string one", "string two"));
    cout << "The strcmp_case_insensitive comparison of \"string one\" and \"string two\" returns " << strcmp_case_insensitive("string one", "string two") << ".\n";
    cout << "The strcmp comparison of \"string one\" and \"string two\" returns " << strcmp("string one", "string two") << ".\n";

    // Testing "string one" vs. "string one"
    assert(strcmp("string one", "string one") == strcmp_case_insensitive("string one", "string one"));
    cout << "The strcmp_case_insensitive comparison of \"string one\" and \"string one\" returns " << strcmp_case_insensitive("string one", "string one") << ".\n";
    cout << "The strcmp comparison of \"string one\" and \"string one\" returns " << strcmp("string one", "string one") << ".\n";

    // Testing "string two" vs. "string one"
    assert(strcmp("string two", "string one") == strcmp_case_insensitive("string two", "string one"));
    cout << "The strcmp_case_insensitive comparison of \"string two\" and \"string one\" returns " << strcmp_case_insensitive("string two", "string one") << ".\n";
    cout << "The strcmp comparison of \"string two\" and \"string one\" returns " << strcmp("string two", "string one") << ".\n";

    // Testing "String one" vs. "string tWo"
    assert(strcmp("String one", "string tWo") == strcmp_case_insensitive("String one", "string tWo"));
    cout << "The strcmp_case_insensitive comparison of \"String one\" and \"string tWo\" returns " << strcmp_case_insensitive("String one", "string tWo") << ".\n";
    cout << "The strcmp comparison of \"String one\" and \"string tWo\" returns " << strcmp("String one", "string tWo") << ".\n";

    // Testing "String one" vs. "string One"
    assert(strcmp("String one", "string One") == strcmp_case_insensitive("String one", "string One"));
    cout << "The strcmp_case_insensitive comparison of \"String one\" and \"string One\" returns " << strcmp_case_insensitive("String one", "string One") << ".\n";
    cout << "The strcmp comparison of \"String one\" and \"string One\" returns " << strcmp("String one", "string One") << ".\n";

    // Testing "sTring two" vs. "string onE"
    assert(strcmp("sTring two", "string onE") == strcmp_case_insensitive("sTring two", "string onE"));
    cout << "The strcmp_case_insensitive comparison of \"sTring two\" and \"string onE\" returns " << strcmp_case_insensitive("sTring two", "string onE") << ".\n";
    cout << "The strcmp comparison of \"sTring two\" and \"string onE\" returns " << strcmp("sTring two", "string onE") << ".\n";

    // Testing "string 2" vs. "string two"
    assert(strcmp("string 2", "string two") == strcmp_case_insensitive("string 2", "string two"));
    cout << "The strcmp_case_insensitive comparison of \"string 2\" and \"string two\" returns " << strcmp_case_insensitive("string 2", "string two") << ".\n";
    cout << "The strcmp comparison of \"string 2\" and \"string two\" returns " << strcmp("string 2", "string two") << ".\n";

    // Testing "string two" vs. "string tw"
    assert(strcmp("string two", "string tw") == strcmp_case_insensitive("string two", "string tw"));
    cout << "The strcmp_case_insensitive comparison of \"string two\" and \"string tw\" returns " << strcmp_case_insensitive("string two", "string tw") << ".\n";
    cout << "The strcmp comparison of \"string two\" and \"string tw\" returns " << strcmp("string two", "string tw") << ".\n";
    return 0;
}