#include <iostream>
using namespace std;

int strcmp_case_insensitive(string string1, string string2) {
    int comparison;
    comparison = string1 == string2;  
    return comparison;
}

int main() {
    cout << "string1, string2 = " << strcmp_case_insensitive("string1", "string2") <<"\n";
    cout << "string1, string1 = " << strcmp_case_insensitive("string1", "string1") <<"\n";
    cout << "string2, string2 = " << strcmp_case_insensitive("string2", "string2") <<"\n";
    cout << "String1, string2 = " << strcmp_case_insensitive("String1", "string2") <<"\n";
    cout << "String1, string1 = " << strcmp_case_insensitive("String1", "string1") <<"\n";
    cout << "String2, string2 = " << strcmp_case_insensitive("String2", "string2") <<"\n";
}