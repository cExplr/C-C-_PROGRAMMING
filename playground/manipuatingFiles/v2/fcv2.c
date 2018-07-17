#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<string.h>

int option = 0;

int outputFlag = 0;
int fileFlag = 0;
int encodeFlag = 0;
int decodeFlag = 0;
int keyFlag = 0;

char pathToFile[1000];
char pathToOutput[1000];
char key[1000] = "";
int keyLength=0;
int keyPos = 0;

void print_usage(char filename[1000]);
void checkInput(char filename[1000]);

int currentByte = 0;
unsigned char *bPtr = (unsigned char *)&currentByte;
int newByte = 0;
int firstFourBits;
int lastFourBits;


int main(int argc, char **argv){

	//This program needs to either have a (d)ecode or (e)ncode and not both
	//This program needs (o)utput path and (f)ile path

	while((option = getopt(argc, argv,"def:o:k:"))!=-1){

		switch(option){

			case 'f':
				fileFlag++;
				strcpy(pathToFile,optarg);
//				printf("Using file %s",pathToFile);
				break;
			case 'o':
				outputFlag++;
				strcpy(pathToOutput,optarg);
				break;
			case 'd':
				decodeFlag = 1;
				break;
			case 'e':
				encodeFlag = 1;
				break;
			case 'k':
				keyFlag = 1;
				strcpy(key,optarg);
				printf("KEY ::::: %s",key);
				break;
			default:
				strcpy(key,"");
				break;
		}
	}

	checkInput(argv[0]);
	
	FILE *fp;
	FILE *fp_out;
	fp = fopen(pathToFile,"rb");
	fp_out = fopen(pathToOutput,"wb");

	if(fp == NULL){
		printf("Error Opening file");
		exit(1);
	}


//	keyLength = strlen(key);
//	keyPos = 0;

	if(encodeFlag){
		keyLength = strlen(key);
	        keyPos = 0;
		while(!feof(fp)){
			fread(bPtr,1,1,fp);
			//xor first then reverse
			if(strcmp(key,"")!=0){
				currentByte ^= key[keyPos];
                        	keyPos = (keyPos+1)%keyLength;

			}
//			currentByte ^= key[keyPos];
//			keyPos = (keyPos+1)%keyLength;

			firstFourBits = currentByte >> 4;
                	lastFourBits = currentByte - (firstFourBits << 4);
			newByte = (firstFourBits + (lastFourBits<<4));
			fwrite(&newByte,1,1,fp_out);
//			printf("%X ",(unsigned int)newByte);
		}
	}
	if(decodeFlag){
		keyLength = strlen(key);
	        keyPos = 0;
		while(!feof(fp)){
			fread(bPtr,1,1,fp);
			firstFourBits = currentByte >> 4;
                        lastFourBits = currentByte - (firstFourBits << 4);
                        newByte = (firstFourBits + (lastFourBits<<4));
			if(strcmp(key,"")!=0){
				newByte ^= key[keyPos];
				keyPos = (keyPos+1)%keyLength;
			}
			fwrite(&newByte,1,1,fp_out);
//			printf("%X ",(unsigned int)newByte);
		}
	}
	fclose(fp_out);
	fclose(fp);
	return 0;
}








void print_usage(char filename[100]){
        printf("\nUsage: %s [-d | -e] -f  <file> -o <outputfile> [-k <key>] \n\n",filename);
        exit(2);
}

void checkInput(char filename[1000]){
	if(encodeFlag + decodeFlag != 1 ){
                // Either e and d is supplied or none is supplied
                printf("\nPlease indicate whether you want to (-d)ecode or (-e)ncode\n");
		print_usage(filename);
        }
        else if(outputFlag == 0){
                printf("\nYou have a missing -o flag\n");
		print_usage(filename);
        }
        else if(fileFlag == 0){
                printf("\nYou have a missing -f flag\n");
		print_usage(filename);
        }
	else if(strcmp(pathToFile,"")==0){
		printf("\nPlease input option for -f flag\n");
		print_usage(filename);
	}

	else if(strcmp(pathToOutput,"")==0){
                printf("\nPlease input option for -o flag\n");
                print_usage(filename);
        }
	else printf("\nConverting file : %s\nWrite to : %s\nUsing key : %s\n",pathToFile,pathToOutput,key);
}
