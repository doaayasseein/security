#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;
void multiplication( int **matrixA , int matrixB[], int matrixC[] ,int m ){
	for(int i=0;i<m;i++){
		        matrixC[i]=0;
        for(int k=0;k<m;k++){
			matrixC[i]=matrixC[i]+(matrixA[i][k] * matrixB[k]);} 
		//cout<<matrixC[i]<<"\t";}
	}
}
void HillCipher(){
	float length;   int rows,columns;
	cin>>length;
	rows= columns= sqrt(length);
	int **keymatrix;
	keymatrix= new int*[rows];
	for(int i=0;i<sqrt(length);i++){
		keymatrix[i]=new int [columns];	}
	
	/* preparing key matrix*/
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			 cin>>keymatrix[i][j];
			 keymatrix[i][j]=keymatrix[i][j]%26;
							}
		}
		string plaintext;  cin >>plaintext; 
	/* dividing the plain text into no of iterations according to key */
	int iterations=0;
		 if(plaintext.length()%rows==0)
	{ iterations= plaintext.length()/rows;}
	if (plaintext.length()%rows!=0)
	{ iterations= (plaintext.length()/rows)+1;
	plaintext.insert(plaintext.length(),(rows-plaintext.length()%rows),'X');}
	/*plaintext encryption*/
	for(int i=0;i<iterations;i++){
				int *matrix1;
		matrix1=new int [rows];
		for(int j=0;j<rows;j++){
			matrix1[j]= plaintext[(i*rows)+j] -65;
		}
		int *matrix2;
		matrix2=new int [rows];
		multiplication(keymatrix,matrix1,matrix2,rows);
			for(int j=0;j<rows;j++){
		matrix2[j]= matrix2[j]%26;
		//cout<<matrix2[j]<<"\t";
		}
		for(int j=0;j<rows;j++){
			plaintext[(i*rows)+j] = (matrix2[j]+65);
			cout<<plaintext[(i*rows)+j];}
			}
	 	
}
std::string string_to_hex(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

void polyAlphabeticCiphers(){
	string key,plaintext,plaintext2;
cin >>key;    
 cin>>plaintext;  plaintext2=plaintext;
int iterations = plaintext.length()/ key.length();
string modifiedKey;

/*updating the key according to plaintext length*/
for(int i=0;i<iterations;i++){
	modifiedKey.insert(modifiedKey.length(),key);
}
if (( plaintext.length()%key.length())!=0){
	for(int i=0;i<( plaintext.length()%key.length());i++){
		modifiedKey.insert(modifiedKey.length(),1,key[i]);}
	}
/*ENCRYPTION using vigenere*/
cout<<"Vigenere: ";
for(int i=0;i<plaintext.length();i++){
	plaintext[i]=plaintext[i]-65;
	modifiedKey[i]=modifiedKey[i]-65;
	plaintext[i]=(plaintext[i]+modifiedKey[i])%26;
    plaintext[i]=plaintext[i]+65;
	cout<<plaintext[i];
}
cout<<endl; 
/*ENCRYPTION USING VERNAM*/
for(int i=0;i<plaintext2.length();i++){
	plaintext2[i]=plaintext2[i]^(modifiedKey[i]+65);
	}
cout<<"Vernam: ";
string output=string_to_hex(plaintext2);
for(int i=0;i<output.length();i++){
cout<<output[i];
}
cout<<endl;
if(key.length()==plaintext.length()){cout<<"One-Time Pad: YES";}
else {cout<<"One-Time Pad: NO";}
}

int main(){
	polyAlphabeticCiphers();
	//HillCipher();
	
	//system("pause");
return 0;}