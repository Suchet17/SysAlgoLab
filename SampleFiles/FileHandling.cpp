#include <iostream>
#include <fstream> //used to write time to a file, to allow python to read
#include <bits/stdc++.h> 
#include <chrono>
#include <unistd.h> //used for sleep

using namespace std;

/* 
Takes 2 arguments from command line:
argv = ["in_file_.txt", "out_file.txt"];
argc = 2; --> number of arguments
argv = ["in_file_.txt", "out_file.txt"]; --> arguments
*/
int main(int argc, char *argv[]){
    if (argc<3){
        cerr << "Input/Output File Names Missing" << endl;
        cout << argc << endl;
        return -1;
    }
    else if (argc>3){
        cerr << "Too Many Arguments Provided" << endl;
        cout << argc << endl;
        return -1;
    }
    else {
        cout << "Input File: " << argv[1] << endl;
        cout << "Output File: " << argv[2] << endl;
    }
    // argv[0] = copmiled code file name
    // argv[1] = input file name
    // argv[2] = output file name

    ifstream fp(argv[1]);
    // Check if file exists
    if (!fp.is_open()){
        cerr << "Error Opening The File";
        return -1;
    }
    else {
        cout << "Input File Exists" << endl;
    }

    const int max_size = 100;
    int arr[max_size];
    int count = 0; // actual size of array
    int num; // value of each line of input iteratively
    while(fp >> num) {
        arr[count++] = num; 
        if (count == max_size)
          break;
      }
      fp.close();

    for (int i = 0; i < count; i++){
        cout << arr[i];
    }
    cout << endl;
    

    ofstream myFile;
    myFile.open(argv[2]);
    myFile << "Test Output" << endl; // print to file
    myFile.close();
    return 0;
}