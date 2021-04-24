#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <wait.h>
#include <dirent.h>
#include <time.h>

pid_t pidsup, pidsup1, pidsup2, pidsup3; 
pid_t pid0, pid1, pid2;
pid_t pidv0, pidv1, pidv2, pidv3;
int status, mantab, jiwa;

char* kue[] = {"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", 
            "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download",
            "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download"};

char* hewan[] = {"Musik_for_stefany.zip","Film_for_stefany.zip", "Foto_for_stefany.zip"};
char* buah[] = {"Musyik", "Fylm", "Pyoto"};
char* matematika[] = {"MUSIK", "FILM", "FOTO"};


void cobafork(int i){

    pid0 = fork();

        if (pid0 < 0)
        exit(EXIT_FAILURE);

        if (pid0 == 0) {
            printf("child[1] --> pid = %d and ppid = %d\n", getpid(), getppid());
            char *argva[] = {"wget", "--no-check-certificate", kue[i], "-qO", hewan[i], NULL};
            execv("/usr/bin/wget", argva);
        }
    
        else {
            while((wait(&status)) > 0);
            pid1 = fork();
            if (pid1 == 0) {
                // sleep(2);
                printf("child[2] --> pid = %d and ppid = %d\n", getpid(), getppid());
                char *argvb[] = {"unzip", "-q", hewan[i], NULL};
                execv("/usr/bin/unzip", argvb);
            }
            else {
                while((wait(&status)) > 0);
                    // sleep(2);
                    printf("parent --> pid = %d\nppid: %d\n", getpid(), getppid());
                    // sleep(6);
                    char orkom[20];
                    if (i == 0){
                        strcpy(orkom, "*.mp3"); 

                    }
                    else if (i == 1){
                        strcpy(orkom, "*.mp4");

                    }
                    else{       
                        strcpy(orkom, "*.jpg");

                    }
                    char lapres[5] = "/.", laprak[5] = "/";
                    char fisika[20], kimia[20];
                    strcpy(kimia, matematika[i]);
                    strcpy(fisika, buah[i]);

                    char *argvc[] = {"find", kimia, "-name", orkom, "-exec", "mv", "{}", fisika, ";", NULL};

                    printf ("kimia: %s orkom: %s fisika: %s argcv: %s", kimia, orkom, fisika, argvc[8]);
                    printf("\n----------OTW Move----------\n");
                    // char *argvc[] = {"cp", "-r", "kimia", "fisika", NULL};
                    execv("/usr/bin/find", argvc);
                    // char *argvc[] = {"sh", "move.sh", NULL};
                    // execv("/bin/bash", argvc);
            }
        }


    return;
}

int penutupan(){

    pidv0 = fork();
    if (pidv0 < 0) exit(EXIT_FAILURE);

    if (pidv0 == 0){
        printf("\n---------All files zipped----------\n");
        char *argv0[] = {"zip", "-qr","Lopyu_Stevany.zip", buah[0], buah[1], buah[2], NULL};
        execv("/usr/bin/zip", argv0);

    }
    else {
        while((wait(&mantab)) > 0);
        printf("\n----------Folder Deleted----------\n");
        char *argv1[] = {"rm", "-r", buah[0], buah[1], buah[2], matematika[0], matematika[1], matematika[2], NULL};
        execv("/bin/rm", argv1);

    }
    return 1;

}

int deadline(){

    time_t now;
    int hours, minutes, seconds, day, month, year;

    time(&now);
    // printf("Now time: %s\n", ctime(&now));

    struct tm *local = localtime(&now);

    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;

    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;

    // printf("Time details: %02d %02d %02d\n", hours, minutes, seconds);
    // printf("Date details: %02d %02d %02d\n", day, month, year);

    if(
        day == 9 &&
        month == 4 &&
        year == 2021 &&
        hours == 16 &&
        minutes == 22 &&
        seconds == 0
    ) return 1;
    
    else if(
        day == 9 &&
        month == 4 &&
        year == 2021 &&
        hours == 22 &&
        minutes == 22 &&
        seconds == 0
    ) return 2;

    else return 0;
}

int main(){

    pid_t pid, sid;
    int value;

    pid = fork();

    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }


    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1){
        int batas = deadline();
        if (batas == 1){
            printf("----------Masuk 1----------\n");
            pidsup = fork();

            if (pidsup < 0)
            exit(EXIT_FAILURE);

            if (pidsup == 0) {
                char *argv[] = {"mkdir", "-p", "Musyik", "Fylm", "Pyoto", NULL};
                execv("/bin/mkdir", argv);
                // sleep(bobok);
                
                // if (fork() == 0){
                //     char *argvc[] = {"rm", hewan[0], hewan[1], hewan[2], NULL};
                //     execv("/bin/rm", argvc);

                // }
                
            }
        
            else {
                while((wait(&mantab)) > 0);
                pidsup1 = fork();
                if (pidsup1 == 0){
                    cobafork(0);
                }

                else{
                    while((wait(&mantab)) > 0);
                    pidsup2 = fork();
                    if (pidsup2 == 0){
                        cobafork(1);
                        // sleep(bobok);
                    }

                    else {
                        while((wait(&mantab)) > 0);
                        pidsup3 = fork();
                        if (pidsup3 == 0){
                            cobafork(2);
                            // sleep(bobok);
                        }
                        else{
                            while((wait(&mantab)) > 0);
                            printf("----------Selesai----------\n");
                            continue;

                        }
                    }

                }
                
            }

        }

        if(batas == 2){
            printf("----------Masuk 2----------\n");
            // penutupan();
            if (penutupan() == 1) break;

        }
        else printf("Waiting...\n");
        sleep(1);
    }


}
