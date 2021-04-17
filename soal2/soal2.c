#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            char baru[255] = "";
            strcpy(baru, dp->d_name);
            strtok(baru, ";_");
            char asalFile[255] = "/home/gerry/modul2/petshop/";
            strcat(asalFile, baru);
        }
    }
    closedir(dir);
}

int main()
{
    pid_t pid1, pid2;
    int status;

    char text[100] = {"/home/gerry/modul2/petshop"};

     pid1 = fork();
     if (pid1 == 0)
     {
        char *arg[]={"unzip", "/home/gerry/Downloads/pets.zip", "-d", text, NULL};
        execv("/usr/bin/unzip",arg);
        sleep(2);
     }
     else
     {
        pid2 = fork();
        if (pid2 == 0)
        {
           char *argc[]={"mkdir", "-p", text, NULL};
           execv("/usr/bin/mkdir",argc);
        }
        else
        {
           while ((wait(&status) > 0));
           char *arga[]={"rm", "-r", "petshop/apex_cheats", "petshop/musics", "petshop/unimportant_files", NULL};
           execv("/usr/bin/rm",arga);
        }
     }
    char path[255] = {"/home/gerry/modul2/petshop"};
    listFilesRecursively(path);

}
