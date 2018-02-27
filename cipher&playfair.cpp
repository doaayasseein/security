#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
void cipher1(){
	int key ; cin >>key;
	string input ;
   cin>>input;
	char* output;
	output=new char[input.length()];
	if (key>25){key=key%26;}
	for(int i=0; i<input.length();i++){
		output[i]=input[i]+key;
		if((input[i]+key)>90){
		output[i]=(input[i]+key)-26;}
			cout<<output[i];
	}
cout<<endl;

}
void playfair(){
	
	string key,input ;
	cin >>key;
	cin>>input;
		int keyLenght= key.length();
				/* remove repeated chars from key */
		for(int i=0;i<key.length();i++){
		if(key[i]==key[i+1]) {key.erase(i+1,1); 
		keyLenght--;
		break;}
							}
			//for(int i=0;i<key.length();i++){cout<<key[i]<<endl;}

		/* HANDLING REPEATED CHARS IN INPUT AND INPUT LENGHT either including  repeated x or not */
		for(int i=0;i<input.length();i++){if((input[i]==input[i+1]) && (i%2==0) && (input[i]=='X') ){
			input.insert(i+1,"V");   
		}}
		for(int i=0;i<input.length();i++){if((input[i]==input[i+1]) && (i%2==0)){
			input.insert(i+1,"X");
		}}
		if ((input.length()%2!=0) && (input[input.length()-1]!='X')){input.insert(input.length(),"X");}
		else if((input.length()%2!=0) && (input[input.length()-1]=='X'))  {input.insert(input.length(),"V");}

	
	//for(int i=0;i<input.length();i++){cout<<input[i]<<endl;}  cout<<endl; 
		char alphabits [26];

		/* alphabits array */
	for(int j=0;j<26;j++){
	 for(int i=0;i<keyLenght;i++){
					if(key[i]==65+j){
						alphabits[j]='#';}}
	 if(alphabits[j]!='#'){
		 alphabits[j]=65+j;}}
	int flag=0;
	if(input.find('J')<input.length()) flag=1;
	char matrix[5][5];
		int k=0;
		/* FILLING MATRIX*/
			for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if((i*5+j)<keyLenght){
				matrix[i][j]=key[j+i*5];}
			else {   
				while(alphabits[k]=='#')    {k++;}
				{ 
				matrix[i][j]=alphabits[k];
				k++;}
				if (flag==1) {if (alphabits[k]=='I') k++;	}
				else if (alphabits[k]=='J') k++;		
			}}
		}
	/*	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){cout<<matrix[i][j]<<"\t";}
		cout<<endl;}*/

		/*INPUT DIVISION*/
	int inputpairs= input.length()/2;
	char **inputMatrix;
	 inputMatrix = new char* [inputpairs];
	 for(int i=0;i<inputpairs;i++)
	 {inputMatrix[i]= new char [2];}
			for(int i=0;i<inputpairs;i++){
				for(int j=0;j<2;j++ ){
					inputMatrix[i][j]=input[j+i*2];
				//cout<<inputMatrix[i][j]<<"\t";
				}}
			
			/* ENCRYPTION */
				int col0,col1,row0,row1;
				for(int k=0;k<inputpairs;k++){
				for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(inputMatrix[k][0]==matrix[i][j]){
			col0=j;
			row0=i;}
			if(inputMatrix[k][1]==matrix[i][j]){
			col1=j;
			row1=i;}
					}}
			/* HANDLING SAME ROW OR COLUMN*/
			if(row0==row1){
					if(col0==4)   {
					inputMatrix[k][0]=matrix[row0][0];
				inputMatrix[k][1]=matrix[row1][col1+1];
					}
					 else if(col1==4)   {
					inputMatrix[k][0]=matrix[row0][col0+1];
				inputMatrix[k][1]=matrix[row1][0];
					}
					 else {	inputMatrix[k][0]=matrix[row0][col0+1];
					 inputMatrix[k][1]=matrix[row1][col1+1];}
				}
			 else if(col0==col1){
				 if(row0==4)   {
					inputMatrix[k][0]=matrix[0][col0];
				inputMatrix[k][1]=matrix[row1+1][col1];
					}
				 else if(row1==4)   {
					inputMatrix[k][0]=matrix[row0+1][col0];
				inputMatrix[k][1]=matrix[0][col1];
					}
			 else{	inputMatrix[k][0]=matrix[row0+1][col0];
				inputMatrix[k][1]=matrix[row1+1][col1];}
			 }

			else{	inputMatrix[k][0]=matrix[row0][col1];
				inputMatrix[k][1]=matrix[row1][col0];}
				}
			for(int i=0;i<inputpairs;i++){
				for(int j=0;j<2;j++ ){
				cout<<inputMatrix[i][j];}
			//cout<<endl ;
				}
}

	
int main(){
	playfair();
system("pause");
	return 0;
	}
