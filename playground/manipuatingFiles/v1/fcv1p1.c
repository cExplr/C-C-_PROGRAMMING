#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	char pathToFile[1000];
	char pathToOutput[1000];

	FILE *fp;
	FILE *fp_out;

	int currentByte = 0;
        unsigned char *bPtr = (unsigned char *)&currentByte;
	int firstFourBits;
	int lastFourBits;
	int newByte = 0;

	printf("\nPath to file : ");
	scanf("%s",pathToFile);
	printf("Path to output : ");
	scanf("%s",pathToOutput);

	printf("\n\nDouble confirm? \n=============================\nEdit %s\nWrite to %s\n\n",pathToFile,pathToOutput);
	char choice = 'n';
	scanf("\n%c",&choice);
	if (choice == 'y' || choice == 'Y'){
		//continue on
		if((fp = fopen(pathToFile,"rb")) == NULL){
			printf("Error opening the file");
			exit(1);
		}

		fp_out = fopen(pathToOutput,"wb");

		while(!feof(fp)){
			fread(bPtr,1,1,fp);
			firstFourBits = currentByte >> 4;
			lastFourBits = currentByte - (firstFourBits << 4);
//			printf("%X%X ",(unsigned int)firstFourBits,(unsigned int)lastFourBits);
			newByte = (firstFourBits + (lastFourBits<<4));
			fwrite(&newByte,1,1,fp_out);
		}
		//First reverse say 0x43 to 0x34
		/*
			
			
		*/
		
	//	int currentByte = 0;
	//	unsigned char *bPtr = (unsigned char *)&currentByte;
		//Second, reverse the order backwords say 0xaa 0xbb to 0xbb 0xaa and write them in the file
		

	}
	else{
		return 1; //Receive error
	}
	fclose(fp_out);
	fclose(fp);
	return 0;
}
