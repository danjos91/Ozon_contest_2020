#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_target(char* text)
{
	int i = 0;
	char numbers_str[11];

	while (text[i] != '\n') {
		numbers_str[i] = text[i];
		i++;
	}
	numbers_str[i] = '\0';
	return (atoi(numbers_str));
}

int main() {
	int fd;
	char buf[1000001];
	int target;
	int ret;

	fd = open("input.txt", O_RDONLY);
	ret = read(fd, buf, 1000000);
	buf[ret] = '\0';
	target = get_target(buf);
	/*-------------GET massiv numbers-------------------------*/
	int numbers_list[10000];
	char value_str[11];
	int i = 0;
	int l = 0;
	int j;
	int value;

	while(buf[i] != '\n'){
		i++;
	}
	while(buf[i]){
		j = 0;
		while(buf[i] != ' ' && buf[i]){
			value_str[j] = buf[i];
			j++;
			i++;
		}
		value_str[j] = '\0';
		value = atoi(value_str);
		if(value < target)
			numbers_list[l++] = value;
		i++;
	}
	/*_____________End Get massiv of numbers______________________*/
	FILE* file;
	file = fopen("output.txt", "w");
	for(int i = 0; i <= l; i++)
	{
			for (int j = i + 1; j <= l; j++)
			{
				if(numbers_list[i] + numbers_list[j] == target){
					fprintf (file, "1");
					fclose(file);
					return 0;
				}
			}
	}
	fprintf (file, "0");
	fclose(file);
	return 0;
}

