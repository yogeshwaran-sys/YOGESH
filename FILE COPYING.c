#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int src, dest, n;
    char buffer[100];

    src = open("source.txt", O_RDONLY);
    dest = open("dest.txt", O_WRONLY | O_CREAT, 0644);

    while((n = read(src, buffer, sizeof(buffer))) > 0)
    {
        write(dest, buffer, n);
    }

    close(src);
    close(dest);

    printf("File copied successfully\n");
    return 0;
}
