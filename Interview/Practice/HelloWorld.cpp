/**
 * Question: How to print out Hello World without using semicolon
 * 
 * Author Yifan Yuan
 * Date 2022-03-14
 * 
 * Source: geeksforgeeks
 */

// use macros
#define print printf("Hello world")

int main () {
    if (print) {

    }
}

// use if (or switch with prinf)
using namespace std;
int main () {
    if (cout << "Hello Wolrd" << endl) {

    }
}