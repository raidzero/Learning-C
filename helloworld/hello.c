#include <stdio.h>
#include <string.h>
#include <unistd.h>

static const char* FILENAME="file1";

//check if file exists using access(). requires unistd.h
int fileExists_ACCESS(const char* filename) {
	//access takes a filename and a result to check for:
	/* 
	F_OK = File exists
	R_OK = File is readable
	W_OK = File is writeable
	X_OK = File in executable
	*/
	if (access(filename,F_OK)) {
		return 0; 
	} else {
		return 1;
	}	
}

//check if file exists using fopen(). does not require unistd.h
int fileExists_FOPEN(const char* filename) {
	FILE * file = fopen(filename, "r"); //will return pointer to the file
	if (file) { 						//check if pointer is valid
		fclose(file); 					//just to be nice
		return 0;
	} else {
		return 1;
	}	
}

//function to copy file
int copyFile(FILE *fp, FILE *tp) {
	char ch; 							//variable to keep a character in it, used as a buffer 
										//to hold each character in the file
	
	//open source file
	if ((fp = fopen(fp, "rb"))==NULL) { //fopen takes FILE* variable and the open type. r for read, b for binary
										//if pointer is NULL, then the file does not exist
		printf("Cannot open source file.\n");
		return 1;
	} 
	
	//open destination file
	if ((tp = fopen(tp, "wb"))==NULL) { //w for write, b for binary 
		printf("Cannot create destination file.\n");
		return 1;
		}
	
	//do the copy work
	while(!feof(fp)) { 				//while not at the EOF in the from file
		ch=fgetc(fp); 				//fgetc pulls a char from a file, each get will increment position in file
		if (ferror(fp)) { 			//detect file error in from
			printf("Error reading from source file.\n");
			return 1;
		}
		if (!feof(fp)) fputc(ch, tp); //if not at the EOF, put contents of ch into the to file
		if (ferror(tp)) {
			printf("Error writing destinaton file.\n");
				return 1;
		}
	}
	
	if (fclose(fp)==EOF) { 
		printf("Error closing source file.\n");
		return 1;
	}	
	
	if (fclose(tp)==EOF) {
		printf("Error closing destination file.\n");
		return 1;
	}
	
	return 0;
}

int main() {
	char *charv = "This is a test string.";
	//strlen is from string.h - it returns the length of a char or char*
	int charv_length = strlen(charv);
	//char* resultString;	// will result in segfault because size of variable is unknown
							//and it cannot be inserted into string or strcat'ed
	
	char resultString[255]; //perfectly valid 
	
	//%i %c %s tokens are int, char, and char* respectively
	//sprintf will create strings instead of printing to stdout
	sprintf(resultString, "Variable: \"%s\" is %i characters long!", charv, charv_length);
	
	printf("\n%s", resultString);
	
	//if comparisons result in either 0 or 1, without a test operand, 1 is true
	if (fileExists_ACCESS(FILENAME)) printf("\nFile %s Exists!\n", FILENAME);
	else printf("File %s Does not exist!\n", FILENAME);
	
	copyFile(FILENAME,"file2");
	
	if (!copyFile(FILENAME,"file2")) printf("file copied!\n"); //if the result of copyFile() is not 1
		
	return 0;
}

