#include <stdio.h>
#include <string.h>

int main() {
	FILE* fp = fopen("file1","rb");
	while(!feof(fp)) {	
		char ch = fgetc(fp);
		printf("%c", ch);	
	}
	fclose(fp);
}