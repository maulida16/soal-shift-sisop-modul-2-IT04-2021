#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

void generateKiller(char source[]){
    FILE *target;
  	//buka/jalankan file killer.sh
    target = fopen("killer.sh", "w");
    int status;
		
  	//mode 1 (-z)
  	//coba dimodif pake case
    if (strcmp(source, "-z") == 0)
        fprintf(target, "#!/bin/bash\npkill -9 soal3\nrm killer.sh");
		//mode 2 (-x)
    if (strcmp(source, "-x") == 0)
        fprintf(target, "#!/bin/bash\npkill soal3\nrm killer.sh");
		
  	//kalau di child
    if(fork() == 0){
      //set permission baut file killer biar 
      char *argv[] = {"chmod", "u+x", "killer.sh", NULL};
      execv("/bin/chmod", argv);
    }
    //tutup program/file killeh.sh yang tadi dijalanin
    fclose(target);
}

void generate_statustxt(char folder_local[]){

  FILE *status_txt;
  char statuxt[50], status_name[100] = "/status.txt";
  sprintf(statuxt, "%s%s", folder_local, status_name);
  //buka/jalankan file killer.sh
  status_txt = fopen(statuxt, "w");
  //decrypt();
  fprintf(status_txt, "Download success!");
  //set nama file zip
  fclose(status_txt);
}

//argc??? argv???
int main(int argc, char **argv){
  //kalau
  if(argc != 2){
      puts("argument is not valid");
      exit(EXIT_FAILURE);
  }

  generateKiller(argv[1]);

  pid_t pid, sid;

  pid = fork();

  if (pid < 0)
      exit(EXIT_FAILURE);

  if (pid > 0)
      exit(EXIT_SUCCESS);

  umask(0);

  sid = setsid();
  if (sid < 0) 
      exit(EXIT_FAILURE);

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  time_t timer;
  struct tm* tm_info;

  //while untuk membuat folder dan zip
        while (1) {
            timer = time(NULL);
            tm_info = localtime(&timer);

            char folder_name[100];
            //formatnya beda, jangan luapa diganti
            strftime(folder_name, 100, "%Y-%m-%d_%H:%M:%S", tm_info);

            //bikin var pid buat child, jalanin fork()
            pid_t child_id;
            child_id = fork();

            int status;

            //exit klo gagal
            if (child_id < 0) 
            exit(EXIT_FAILURE);

            //klo berhasil bikin child
            if (child_id == 0){ 
                //klo di dalem child (fork() == 0)
                if (fork() == 0){
                    //buat folder namanya sesuai yang diatur di folder_name
                    char *argv[] = {"mkdir", "-p", folder_name, NULL};
                    execv("/bin/mkdir", argv);
                }
                //klo nggak di dalem child
                else {
                    //tunggu childnya mati/exit
                    while ((wait(&status)) > 0);
                    //loop buat donwload sebanyak 10 gambar
                    for (int i = 0; i < 10; i++){
                        //klo di dalem child
                        if (fork() == 0){
                            //ganti pwd ke folde baru tadi
                            chdir(folder_name);
				
                            time_t file_timer;
                            struct tm* file_tm_info;

                            file_timer = time(NULL);
                            file_tm_info = localtime(&file_timer);

                            int t = (int)time(NULL);
                            t = (t % 1000) + 100;

                            char url[100];
                            //url buat donwload gambar persegi txt
                            sprintf(url, "https://picsum.photos/%d", t);

                            char file_name[100];
                            //set nama filenya
                            strftime(file_name, 100, "%Y-%m-%d_%H:%M:%S", file_tm_info);
                            //download filenya
                            char *argv[] = {"wget", url, "-qO", file_name, NULL};
                            execv("/usr/bin/wget", argv);
                        }

                    //loop downloadnya dijalanin tiap 5 detik
                    sleep(5);
                    }
                    
                    generate_statustxt(folder_name);
                    char folder_name_zip[100];
                    sprintf(folder_name_zip, "%s.zip", folder_name);
                    //bikin file zip (compress) namanya sesuai yang udah di set
                    char *argv[] = {"zip", "-qrm", folder_name_zip, folder_name, NULL};
                    execv("/usr/bin/zip", argv);
                }
            }
            else sleep(40);
    }
}
