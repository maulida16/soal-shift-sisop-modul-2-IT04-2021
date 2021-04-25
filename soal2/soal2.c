#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

//fungsi membuat folder sesuai kategori hewan
void folder(char *nama)
{
    char target[40];
    sprintf(target, "%s", nama);

    DIR *folder = opendir(nama);
    if(folder){
        return;
    }

    pid_t pid;
    pid = fork();
    if(pid == 0){
        char *argv[] = {"mkdir", target, NULL};
        execv("/usr/bin/mkdir", argv);
        exit(EXIT_SUCCESS);
    }
    while(wait(NULL) != pid);
}

//fungsi copy gambar hewan ke folder sesuai kategori
void copy(char *folder, char *asal, char *tujuan)
{
    char source[30];
    sprintf(source, "%s", asal);

    char destination[40];
    sprintf(destination, "%s/%s.jpg", folder, tujuan);

    pid_t pid;
    pid = fork();
    if(pid == 0){
        char *argv[] = {"cp", source, destination, NULL};
        execv("/usr/bin/cp", argv);
        exit(EXIT_SUCCESS);
    }
    while(wait(NULL) != pid);
}

//fungsi membuat file keterangan yang berisi nama dan umur hewan
void keterangan(char *folder, char *nama_hewan, char *umur_hewan)
{
    char ket[50];
    sprintf(ket, "%s/keterangan.txt", folder);

    pid_t pid;
    pid = fork();

    if(pid == 0){
        FILE *txt;
        txt = fopen(ket, "a");
        fprintf(txt, "nama: %s\numur: %s tahun\n\n", nama_hewan, umur_hewan);
        fclose(txt);
        exit(EXIT_SUCCESS);
    }
    while(wait(NULL) != pid);
}

int main()
{
    pid_t pid1, pid2, pid3;
    char dari[] = "/home/gerry/Downloads/pets.zip";
    char text[] = "/home/gerry/modul2/petshop";
    
    chdir("/home/gerry/modul2/");
    
    pid1 = fork();
    if (pid1 == 0)
    {
    	//membuat folder petshop
        char *argc[]={"mkdir", "-p", text, NULL};
        execv("/usr/bin/mkdir",argc);
    }
    while(wait(NULL) != pid1);
    
    pid2 = fork();
    if(pid2 == 0)
    {
    	//unzip petshop.zip ke folder petshop
        char *arg[] = {"unzip", "-q", dari, "-d", text, NULL};
        execv("/usr/bin/unzip", arg);
    }
    while(wait(NULL) != pid2);

    struct dirent *cek;
    DIR *dir = opendir(text);

    if(!dir)
    {
        exit(EXIT_FAILURE);
    }

    chdir(text);

    while (cek = readdir(dir))
    {
        if(strcmp(cek->d_name, ".") != 0 && strcmp(cek->d_name, "..") != 0)
        {
            char *source = cek->d_name;
            char file[40];
            sprintf(file, "%s", source);

            DIR *dir2 = opendir(source);

            char hapus[40], asal[40];
            sprintf(hapus, "%s", source);
            sprintf(asal, "%s", source);

            if(dir2)
            {
                pid_t pid3;

                pid3 = fork();
                if(pid3 == 0)
                {
                    //menghapus folder yang tidak dibutuhkan
                    char *argv[] = {"rm", "-rf", hapus, NULL};
                    execv("/usr/bin/rm", argv);
                    exit(EXIT_SUCCESS);
                }
                while(wait(NULL) != pid3);
            }else
            {
                char *token, *nama_file[3];
                token = strtok(source, ";_");
                while(token != NULL){
                    //memisah nama file menjadi jenis, nama, dan umur
                    int i = 0;
                    while(i<3)
                    {
                        nama_file[i] = token;
                        token = strtok(NULL, ";_");
                        i++;
                    }

                    char *jenis = nama_file[0];
                    char *nama = nama_file[1];
                    char *umur = nama_file[2];
		     
		     //menghilangkan jpg pada umur
                    char *jpg;
                    jpg = strstr(umur, ".jpg");
                    if(jpg != NULL)
                    {
                        int counter = jpg - umur;
                        sprintf(umur, "%.*s", counter, umur);
                    }

                    folder(jenis);
                    copy(jenis, asal, nama);
                    keterangan(jenis, nama, umur);
                }
            }
            closedir(dir2);
        }
    }
}
