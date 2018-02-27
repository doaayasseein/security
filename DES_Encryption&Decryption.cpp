#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int  binaryInput [48];  // used only in sbox case
int positions [8];
int permutationBinaryOutput[48];    // used in DES round
string initialPermutation="58 50 42 34 26 18 10 2 60 52 44 36 28 20 12 4 62 54 46 38 30 22 14 6 64 56 48 40 32 24 16 8 57 49 41 33 25 17 9 1 59 51 43 35 27 19 11 3 61 53 45 37 29 21 13 5 63 55 47 39 31 23 15 7";
string inversePermutation="40 8 48 16 56 24 64 32 39 7 47 15 55 23 63 31 38 6 46 14 54 22 62 30 37 5 45 13 53 21 61 29 36 4 44 12 52 20 60 28 35 3 43 11 51 19 59 27 34 2 42 10 50 18 58 26 33 1 41 9 49 17 57 25";
string PC1="57 49 41 33 25 17 9 1 58 50 42 34 26 18 10 2 59 51 43 35 27 19 11 3 60 52 44 36 63 55 47 39 31 23 15 7 62 54 46 38 30 22 14 6 61 53 45 37 29 21 13 5 28 20 12 4";
string PC2= "14 17 11 24 1 5 3 28 15 6 21 10 23 19 12 4 26 8 16 7 27 20 13 2 41 52 31 37 47 55 30 40 51 45 33 48 44 49 39 56 34 53 46 42 50 36 29 32";
string  GeneratedKeys[16];
void hex_string_to_binary(string input, int inputTable[],int size){
	for(int i=0;i<input.length();i++){
		switch (input[i]){
		case ('0'):    { inputTable[4*i]=0;
			inputTable[4*i+1]=0;
			inputTable[4*i+2]=0;
			inputTable[4*i+3]=0;
			break;
					   }
		case ('1'):    { inputTable[4*i]=0;
			inputTable[4*i+1]=0;
			inputTable[4*i+2]=0;
			inputTable[4*i+3]=1;
			break;
					   }
		case ('2'):    { inputTable[4*i]=0;
			inputTable[4*i+1]=0;
			inputTable[4*i+2]=1;
			inputTable[4*i+3]=0; 
			break;

					   }
		case ('3'):    { inputTable[4*i]=0;
			inputTable[4*i+1]=0;
			inputTable[4*i+2]=1;
			inputTable[4*i+3]=1;
			break;

					   }
		case ('4'):    { inputTable[4*i]=0;
			inputTable[4*i+1]=1;
			inputTable[4*i+2]=0;
			inputTable[4*i+3]=0;
			break;

					   }
		case ('5'):    { inputTable[4*i]=0;
			inputTable[4*i+1]=1;
			inputTable[4*i+2]=0;
			inputTable[4*i+3]=1;
			break;

					   }

		case ('6'):    { inputTable[4*i]=0;
			inputTable[4*i+1]=1;
			inputTable[4*i+2]=1;
			inputTable[4*i+3]=0;
			break;

					   }
		case ('7'):    { inputTable[4*i]=0;
			inputTable[4*i+1]=1;
			inputTable[4*i+2]=1;
			inputTable[4*i+3]=1;
			break;

					   }
		case ('8'):    { inputTable[4*i]=1;
			inputTable[4*i+1]=0;
			inputTable[4*i+2]=0;
			inputTable[4*i+3]=0;
			break;

					   }
		case ('9'):    { inputTable[4*i]=1;
			inputTable[4*i+1]=0;
			inputTable[4*i+2]=0;
			inputTable[4*i+3]=1;
			break;

					   }

		case ('A'):    { inputTable[4*i]=1;
			inputTable[4*i+1]=0;
			inputTable[4*i+2]=1;
			inputTable[4*i+3]=0;
			break;

					   }
		case ('B'):    { inputTable[4*i]=1;
			inputTable[4*i+1]=0;
			inputTable[4*i+2]=1;
			inputTable[4*i+3]=1;
			break;

					   }
		case ('C'):    { inputTable[4*i]=1;
			inputTable[4*i+1]=1;
			inputTable[4*i+2]=0;
			inputTable[4*i+3]=0;
			break;

					   }
		case ('D'):    { inputTable[4*i]=1;
			inputTable[4*i+1]=1;
			inputTable[4*i+2]=0;
			inputTable[4*i+3]=1;
			break;

					   }
		case ('E'):    { inputTable[4*i]=1;
			inputTable[4*i+1]=1;
			inputTable[4*i+2]=1;
			inputTable[4*i+3]=0;
			break;
					   }
		case ('F'):    { inputTable[4*i]=1;
			inputTable[4*i+1]=1;
			inputTable[4*i+2]=1;
			inputTable[4*i+3]=1;
			break;
					   }
		}
	}
/*for(int i=0;i<size;i++){
	cout<<inputTable[i]<<"\t";}*/
}
char binary_to_hexOrDecimal (string element ,int & out1){ 
	char out='\0';   // out is to convert to hex and out1 to convert to decimal
	  if (element=="0000") { out='0';  out1=0;}
	else if (element=="0001") { out='1';  out1=1;}
	else if (element=="0010") {out='2';  out1=2;}
	else if (element=="0011") {out='3'; out1=3;}
	else if (element=="0100") {out='4';  out1=4;}
	else if (element=="0101") {out='5'; out1=5;}
	else if (element=="0110") {out='6'; out1=6;}
	else if (element=="0111") {out='7';  out1=7;}
	else if (element=="1000") {out='8';  out1=8;}
	else if (element=="1001") {out='9';  out1=9;}
	else if (element=="1010") {out='A';  out1=10;}
	else if (element=="1011") {out='B'; out1=11;}
	else if (element=="1100") {out='C';   out1=12;}
	else if (element=="1101") {out='D';  out1=13;}
	else if (element=="1110") {out='E'; out1=14;}
	else if (element=="1111") {out='F';   out1=15;}

return out;
}
char decimal_hex(int x){
	switch(x){
	case(0): {return '0'; break;}
	case(1): {return'1'; break;}
	case(2): {return'2'; break;}
	case(3): {return'3'; break;}
	case(4): {return'4'; break;}
	case(5): {return'5'; break;}
	case(6): {return'6'; break;}
	case(7): {return'7'; break;}
	case(8): {return'8'; break;}
	case(9): {return'9'; break;}
	case(10): {return'A'; break;}
	case(11) :{return'B'; break;}
	case(12): {return'C'; break;}
	case(13): {return'D'; break;}
	case(14): {return'E'; break;}
	case(15): {return'F'; break;}

	}}
string permutation(string table , int tableSize, string input,int inputSize){
	
	int * inputTable;  inputTable=new int[inputSize];
	int *permutationTable;
	permutationTable=new int [tableSize];
	/*preparing the permutation table*/
	int i=0,j=0;
	while (table[i]!='\0'){
		if(table[i]==' '){
			string	element= table.substr(0,i);
			permutationTable[j]=stoi(element,nullptr,10);
			j++;
			table.erase(0,i+1);
			i=0;
		}
		else i++;
		if (table.find(' ')>table.length())  permutationTable[tableSize-1]= stoi(table,nullptr,10);
	}
	//for(int i=0;i<tableSize;i++){  cout<<permutationTable[i]<<"\t";}

	/*convert the input to binary */
	hex_string_to_binary(input, inputTable ,inputSize);
		/*ENCRYPTION*/
	int *output;
	output=new int [tableSize];
	for(int i=0;i<tableSize;i++){
		output[i]=inputTable[permutationTable[i]-1];    }
	string out; 
	for(int i=0;i<tableSize;i++){
		out.insert(out.length(),1,(output[i]+48));
	}
	string hexoutput;
	i=0;
	/*PARSING THE OUTPUT TO CHANGE TO BINARY  */
	while(out[i]!='\0'){
		string	element= out.substr(i,4);
		int k=0;  // not used just to pass as 2ndarguement 
		hexoutput.insert(hexoutput.length(),1,binary_to_hexOrDecimal(element,k));
		i+=4;
		
	}
	return hexoutput;

}
void key_generation(string inputKey){
//string inputKey ;   cin >> inputKey;  // input key 16 heaxa 
string PC1_output=permutation(PC1 , 56, inputKey,64);
int* binary_PC1_output;    binary_PC1_output=new int[56];
int RotaionsInput1[28],RotaionsInput2[28];                 // hn2sm el array l noseen 2bl m n2ml shift

hex_string_to_binary(PC1_output, binary_PC1_output,56);
for(int i=0;i<56;i++){
	if(i<28){RotaionsInput1[i]=binary_PC1_output[i];}
	if(i>27){RotaionsInput2[i-28]=binary_PC1_output[i];}
		}
int Rotations[16]= { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
for (int i=0;i<16;i++){
	/*first shift*/
	int temperory1 =RotaionsInput1[0];
	int temperory2 =RotaionsInput2[0];
	for(int j=0;j<28;j++){
		RotaionsInput1[j]=RotaionsInput1[j+1];
		RotaionsInput2[j]=RotaionsInput2[j+1];
	}
	RotaionsInput1[27]=temperory1;
	RotaionsInput2[27]=temperory2;
	   /*second shift*/
	 if(Rotations[i]==2){
	int temperory3 =RotaionsInput1[0];
	int temperory4 =RotaionsInput2[0];
	for(int j=0;j<28;j++){
		RotaionsInput1[j]=RotaionsInput1[j+1];
		RotaionsInput2[j]=RotaionsInput2[j+1];
	}
	RotaionsInput1[27]=temperory3;
	RotaionsInput2[27]=temperory4;
 		}
	 /****************************************/
		else{}
		/*summing the pc1 out put afer shifting its two halves*/
		for(int i=0;i<56;i++){
	if(i<28){binary_PC1_output[i]=RotaionsInput1[i];}
	if(i>27){binary_PC1_output[i]=RotaionsInput2[i-28];}
		}
		if(i==0) {for(int j=0;j<56;j++){ binary_PC1_output[j];  system("pause");}}
		string PC2_input,generatedKey;
		for(int k=0;k<56;k+=4){
		string temp;
		temp.insert(temp.length(),1,(binary_PC1_output[k]+48));
		temp.insert(temp.length(),1,(binary_PC1_output[k+1]+48));
		temp.insert(temp.length(),1,(binary_PC1_output[k+2]+48));
		temp.insert(temp.length(),1,(binary_PC1_output[k+3]+48));
	int q=0;
		PC2_input.insert(PC2_input.length(),1 , binary_to_hexOrDecimal (temp ,q));
		}
		generatedKey=permutation(PC2 , 48, PC2_input,56);
		GeneratedKeys[i]=generatedKey;
	}
		}
string  sbox(string input){
	/* sbox1*/
	int s1_row0[16]={14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
	int s1_row1[16]={0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8};
	int s1_row2[16]={4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0};
	int s1_row3[16]={15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};
	/*sbox2*/
	int s2_row0[16]={15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10};
	int s2_row1[16]={3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5};
	int s2_row2[16]={0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15};
	int s2_row3[16]={13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};
	/*sbox3*/
	int s3_row0[16]={10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8};
	int s3_row1[16]={13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1};
	int s3_row2[16]={13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7};
	int s3_row3[16]={1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};
	/*sbox4*/
	int s4_row0[16]={7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15};
	int s4_row1[16]={13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9};
	int s4_row2[16]={10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4};
	int s4_row3[16]={3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};
	/*sbox5*/
	int s5_row0[16]={2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9};
	int s5_row1[16]={14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6};
	int s5_row2[16]={4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14};
	int s5_row3[16]={11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};
	/*sbox6*/
	int s6_row0[16]={12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11};
	int s6_row1[16]={10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8};
	int s6_row2[16]={9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6};
	int s6_row3[16]={4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};
	/*sbox7*/
	int s7_row0[16]={4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1};
	int s7_row1[16]={13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6};
	int s7_row2[16]={1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2};
	int s7_row3[16]={6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};
	/*sbox8*/
	int s8_row0[16]={13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7};
	int s8_row1[16]={1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2};
	int s8_row2[16]={7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8};
	int s8_row3[16]={2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};
	/*********************************************/

	//string input;  cin>>input;
	string finaloutput;
	hex_string_to_binary(input,binaryInput,48);   // convert the input from hexa to binary 
	string boxesInput[8];
	/*distributing the input around the 8 sboxes  */
	for (int i=0;i<8;i++){
		for(int j=0;j<6;j++){
			boxesInput[i].insert(j,1,(binaryInput[6*i+j]+48));}}
		//for(int i=0;i<8;i++) {cout<<boxesInput[i]<<"\t";}
	
	/*calculating output*/
		int decimalOutput[8];
	for (int i=0;i<8;i++){
		/*sbox1*/
		if(i==0 && boxesInput[i][0]=='0' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);   
		decimalOutput[i]=s1_row0[positions[i]];   finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i])); 
		}
		else if(i==0 && boxesInput[i][0]=='0' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);      binary_to_hexOrDecimal(boxesInput[i],positions[i]);  
		decimalOutput[i]=s1_row1[positions[i]];   finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i])); 
		}
		else if(i==0 && boxesInput[i][0]=='1' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);  
		decimalOutput[i]=s1_row2[positions[i]];    finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i])); 
		}
		else if(i==0 && boxesInput[i][0]=='1' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s1_row3[positions[i]];    finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i])); 
		}
		/*sbox2*/
		else if(i==1 && boxesInput[i][0]=='0' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s2_row0[positions[i]];     finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==1 && boxesInput[i][0]=='0' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s2_row1[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}

		else if(i==1 && boxesInput[i][0]=='1' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s2_row2[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==1 && boxesInput[i][0]=='1' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s2_row3[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		/*sbox3*/
		else if(i==2 && boxesInput[i][0]=='0' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s3_row0[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==2 && boxesInput[i][0]=='0' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s3_row1[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==2 && boxesInput[i][0]=='1' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]); //cout<<"\n"<<positions[i]<<"\t";
		decimalOutput[i]=s3_row2[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==2 && boxesInput[i][0]=='1' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s3_row3[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
			/*sbox4*/
		else if(i==3 && boxesInput[i][0]=='0' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s4_row0[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==3 && boxesInput[i][0]=='0' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s4_row1[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}	
		else if(i==3 && boxesInput[i][0]=='1' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s4_row2[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}	
		else if(i==3 && boxesInput[i][0]=='1' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s4_row3[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}	
		/*sbox5*/
		if(i==4 && boxesInput[i][0]=='0' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s5_row0[positions[i]];   finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==4 && boxesInput[i][0]=='0' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s5_row1[positions[i]];   finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==4 && boxesInput[i][0]=='1' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s5_row2[positions[i]];    finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==4 && boxesInput[i][0]=='1' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s5_row3[positions[i]];    finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		/*sbox6*/
		else if(i==5 && boxesInput[i][0]=='0' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s6_row0[positions[i]];     finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==5 && boxesInput[i][0]=='0' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s6_row1[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}

		else if(i==5 && boxesInput[i][0]=='1' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s6_row2[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==5 && boxesInput[i][0]=='1' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s6_row3[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		/*sbox7*/
		else if(i==6 && boxesInput[i][0]=='0' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s7_row0[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==6 && boxesInput[i][0]=='0' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s7_row1[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==6 && boxesInput[i][0]=='1' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s7_row2[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==6 && boxesInput[i][0]=='1' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s7_row3[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
			/*sbox8*/
		else if(i==7 && boxesInput[i][0]=='0' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s8_row0[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}
		else if(i==7 && boxesInput[i][0]=='0' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s8_row1[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}	
		else if(i==7 && boxesInput[i][0]=='1' && boxesInput[i][5]=='0')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s8_row2[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}	
		else if(i==7 && boxesInput[i][0]=='1' && boxesInput[i][5]=='1')
		{ boxesInput[i].erase(boxesInput[i].begin());   boxesInput[i].erase(boxesInput[i].end()-1);  binary_to_hexOrDecimal(boxesInput[i],positions[i]);
		decimalOutput[i]=s8_row3[positions[i]];      finaloutput.insert(finaloutput.length(),1,decimal_hex(decimalOutput[i]));
		}	
	}
	return finaloutput;
}
void inverse_permutation(){

	int tableSize;  string table;
	cin>>tableSize;  cin.ignore();
	int *permutationTable;
	permutationTable=new int [tableSize];
	int *inversedPermutationTable;
	inversedPermutationTable=new int [tableSize];
	getline(cin,table);    // THE TABLE IS GIVEN AS STRING
	/*preparing the permutation table*/
	int i=0,j=0;
	while (table[i]!='\0'){
		if(table[i]==' '){
			string	element= table.substr(0,i);
			permutationTable[j]=stoi(element,nullptr,10);
			j++;
			table.erase(0,i+1);
			i=0;
		}
		else i++;
		if (table.find(' ')>table.length())  permutationTable[tableSize-1]= stoi(table,nullptr,10);
	}
	//for(int i=0;i<tableSize;i++){  cout<<permutationTable[i]<<"\t";}
	bool  reversable =true;
	for(int i=0;i<tableSize;i++){
		for(int j=i+1;j<tableSize;j++){
			if (permutationTable[i]==permutationTable[j]){
				reversable=false;
				break; break;
			}}}

	if (reversable==true){
		for(int i=1;i<tableSize+1;i++){
			int index=0;
			for(int j=0;j<tableSize;j++){
				if(permutationTable[j]==i) { index=j;  break;}
			}
			inversedPermutationTable[i-1]=index+1;
			if (i==tableSize) cout<<inversedPermutationTable[i-1];
			else cout<<inversedPermutationTable[i-1]<<" ";
		}}
	else cout<<"IMPOSSIBLE";
}
string DES_Round(string input,string key){
 string leftInput,rightInput;
	int key_binary[48];
	leftInput=input.substr(0,8);
	rightInput=input.substr(8,8);
	hex_string_to_binary(key,key_binary,48);
	string permutationOutput;
	string expansion = "32 1 2 3 4 5 4 5 6 7 8 9 8 9 10 11 12 13 12 13 14 15 16 17 16 17 18 19 20 21 20 21 22 23 24 25 24 25 26 27 28 29 28 29 30 31 32 1";  //48 table 
	string straight="16 7 20 21 29 12 28 17 1 15 23 26 5 18 31 10 2 8 24 14 32 27 3 9 19 13 30 6 22 11 4 25"; //32 table
	permutationOutput=permutation(expansion,48,rightInput,32);
	//cout<<permutationOutput<<endl;
	hex_string_to_binary(permutationOutput,permutationBinaryOutput,48);
	for(int i=0;i<48;i++){
		permutationBinaryOutput[i]=permutationBinaryOutput[i]^key_binary[i];
	
	}
string	sboxinput,sboxoutput;
	for(int i=0;i<12;i++){
	string temp; int k=0;
	for(int j=0;j<4;j++){
		char x=permutationBinaryOutput[4*i+j]+48;
		temp.insert(j,1,x);
}
	sboxinput.insert(sboxinput.length(),1,binary_to_hexOrDecimal(temp,k));
	}
	
	sboxoutput=sbox(sboxinput);    //cout<<sboxoutput;
	string desRoundOutput=rightInput;
	sboxoutput=permutation(straight,32,sboxoutput,32);
	int binarySboxOutput[32],binaryLeftInput[32] ;
	hex_string_to_binary(sboxoutput,binarySboxOutput,32);
	hex_string_to_binary(leftInput,binaryLeftInput,32);
	for( int i=0;i<32;i++){
			binarySboxOutput[i]=binarySboxOutput[i]^binaryLeftInput[i];
			
	}
	for(int i=0;i<8;i++){
	string temp;
	for(int j=0;j<4;j++){
		char x=binarySboxOutput[4*i+j]+48;
		temp.insert(j,1,x);
		}
	int k=0;
	
	desRoundOutput.insert(desRoundOutput.length(),1,binary_to_hexOrDecimal(temp,k));
	}
	return desRoundOutput;
	}


void Full_DES(){
	string input , key;  int encryptionTimes;
    cin>>key;
	cin>> input;
	cin>>encryptionTimes;
	key_generation(key);
	string tempInput=input;
	for(int i=0;i<encryptionTimes;i++){
	tempInput=permutation(initialPermutation,64,tempInput,64);
	string roundOutput=DES_Round(tempInput,GeneratedKeys[0]);
	for(int  j=1;j<16;j++){
	roundOutput=DES_Round(roundOutput,GeneratedKeys[j]);}
	
	/* 32 SWAP */
	string temp=roundOutput.substr(0,8);
	roundOutput=roundOutput.substr(8,8);
	roundOutput=roundOutput.append(temp);
	/**********************/
	roundOutput=permutation(inversePermutation,64,roundOutput,64);
	//cout<<roundOutput<<endl;
	tempInput=roundOutput;
					}
	cout<<tempInput<<endl;
}
void Decryption(){
	string input , key;  int encryptionTimes;
    cin>>key;
	cin>> input;
	cin>>encryptionTimes;
	key_generation(key);
	string tempInput=input;
	for(int i=0;i<encryptionTimes;i++){
	tempInput=permutation(initialPermutation,64,tempInput,64);
	string roundOutput=DES_Round(tempInput,GeneratedKeys[15]);
	for(int  j=1;j<16;j++){
	roundOutput=DES_Round(roundOutput,GeneratedKeys[15-j]);}
	
	/* 32 SWAP */
	string temp=roundOutput.substr(0,8);
	roundOutput=roundOutput.substr(8,8);
	roundOutput=roundOutput.append(temp);
	/**********************/
	roundOutput=permutation(inversePermutation,64,roundOutput,64);
	//cout<<roundOutput<<endl;
	tempInput=roundOutput;
					}
	cout<<tempInput<<endl;

}
int main(){
	Decryption();
   // Full_DES();
	system("pause");
	return 0;
}