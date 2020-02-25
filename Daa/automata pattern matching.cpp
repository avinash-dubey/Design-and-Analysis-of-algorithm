#include<iostream>
#include<map>
#include <string>
using namespace std;
int findVal(string preS, char c, map<string, int> pattern);
int main()
{
string str;
cout << "Enter pattern: \n";
getline(cin, str);
//cout<<"states= "<<str.length<<endl;
cout<<endl<<"Enter the String :";
string str1;
getline(cin, str1);

int patternLenght = str.length(); // counting and displaying the pattern length ie the no of states.
cout<<"states = "<<patternLenght<<endl;
char sym[patternLenght];
int i=0,j=1;
map<char, bool> symbols;
map<string, int> pattern;
map<char, bool>::iterator itr; 
map<string , int>::iterator itr1; 
string s;
for (int k = 0; k<patternLenght; k++) {
	if(symbols.find(str[k])== symbols.end()){ // running the loop till last elements of symbols
        // if not found
		symbols[str[k]] = true; // value assined to every key is 1 and keys are the different inputs i.e alphbet
		sym[i] = str[k]; //storing the pattern in sym character array for future use 
		i++;
	}
    s = s + str[k]; // increasing the combination one by one 
	pattern[s] = j; // giviing states no 
	j++;
}
// symbols store the inputs in transition table
//pattern store the prefix form of the pattern .ie comboination from the 1th to last 
	cout <<"inputs are "; 
	for (itr = symbols.begin(); itr != symbols.end(); ++itr) { 
		cout << '\t' << itr->first ;
			//<< '\t' << itr->second << '\n'; 
	} 
	cout << endl; 
	
	cout << "combination for testing is "<<endl; 
	cout << "\tKEY\tELEMENT\n"; 
	for (itr1 = pattern.begin(); itr1 != pattern.end(); ++itr1) { 
		cout << '\t' << itr1->first 
			<< '\t' << itr1->second << '\n'; 
	} 
	cout << endl; 

//cout<<"inputs"<<pattern<<endl;
cout<<" transition table"<<endl;
int symbolLength = symbols.size();//Returns the number of elements in the map
int table[patternLenght+1][symbolLength];
cout<<"    ";
for(int i=0;i<symbolLength;i++){
    cout<<sym[i]<<"  ";
}

cout<<endl;
string preS;
for(int i=0;i<patternLenght+1;i++){
        cout<<i<<" : "; // printing the states from start to end .i e the  rows no
    for(j=0; j<symbolLength;j++){// now operation on the columns 
        int val = findVal(preS, sym[j], pattern); // passing the pres, sym[j] containing the pattern ,and pattern containing the pattern combinations 
        table[i][j] = val; // assigning the values 
        cout<<val<<"  ";
    }
    preS.append(str,0,i+1);
    cout<<endl;
}


//string str1;
//getline(cin, str1);
j=0;
int count=0;

for(int i=0;i<str1.length();i++) {
	int k;
	for(k=0;k<symbolLength;k++) {
		if(str1[i]==sym[k]) // checking the element by elemnt the string matches with pattern 
			j=table[j][k];
				
	}
	if(j==patternLenght){// if pattern found 
		cout<<endl<<"Found at index: "<<i-patternLenght+1;
		j=0; // setting for multiple checking 
		count++;
	}
	
}
cout<<endl<<"Pattern found "<<count<<" times";

return 0;
}
// function filling trabnsition table 
int findVal(string preS, char c, map<string, int> pattern) {
    preS = preS+c;
    while(pattern.find(preS)==pattern.end() && preS.length() != 0){
        preS = preS.substr(1, preS.length()-1); // storing the pattern till string matches with prefix suffix
    }
    return preS.length(); // returning the length of i.e count 
}
