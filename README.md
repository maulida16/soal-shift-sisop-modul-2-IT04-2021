# soal-shift-sisop-modul-2-IT04-2021

### Kelompok IT-04
* Maulida Meirisdiana 05311940000005
* Dava Aditya Jauhar 05311940000030
* Gerry Putra Fresnando 05311940000031

## Pembahasan Soal

### Soal 1

Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. 

(a) Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg 
(b) untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :). 
(c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta 
(d) memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan).
(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany). 
(f) Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).
Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

#### Note:

* Ulang Tahun Stevany : 09 April Pukul 22.22 WIB
* Semua poin dijalankan oleh 1 script di latar belakang, termasuk mendownload file zip-nya. Jadi cukup jalankan script 1x serta ubah time dan date untuk check hasilnya.
* Tidak boleh menggunakan fungsi system(), mkdir(), dan rename() (Yang di bahasa C) .... FORBIDDENNN!!
* Tidak boleh pake cron !!!
* Menggunakan fork dan exec.

### Penyelesaian 

* Source code lengkap ada di [Soal 1](https://github.com/maulida16/soal-shift-sisop-modul-2-IT04-2021/blob/main/soal1/soal1.c)

```json
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
#include <time.h>
```

* Di atas merupakan library yang akan digunakan untuk menyelesaikan soal 1.

        pid_t pidsup, pidsup1, pidsup2, pidsup3; 
        pid_t pid0, pid1, pid2;
        pid_t pidv0, pidv1, pidv2, pidv3;
        int status, mantab, jiwa;
        
* Pada pendeklarasian variabel, kami mendeklarasikan banyak variabel dengan tipe data pid_t untuk mendapatkan proses ID karena banyaknya fungsi yang berjalan di latar belakang nantinya.

        char* kue[] = {"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", 
                    "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download",
                    "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download"};

        char* hewan[] = {"Musik_for_stefany.zip","Film_for_stefany.zip", "Foto_for_stefany.zip"};
        char* buah[] = {"Musyik", "Fylm", "Pyoto"};
        char* matematika[] = {"MUSIK", "FILM", "FOTO"};
 
* Untuk memudahkan proses, kami menggunakan variabel array yang dapat menampung semua tipe string yang akan dijalankan/dilakukan. 
* Array **kue[]** digunakan untuk menyimpan semua url dari musik, video, dan foto yang dibutuhkan.
* Array **hewan[]** digunakan untuk menyimpan nama zip dari file yang di download. 
* Array **buah[]** digunakan untuk menyimpan nama folder yang disukai Stevany.
* Array **matematika[]** digunakan untuk menyimpan nama folder dari zip yang telah di ekstrak.

        void cobafork(int i){

        pid0 = fork();

            if (pid0 < 0)
            exit(EXIT_FAILURE);

* Kami membuat fungsi bernama **cobafork** dengan parameter integer untuk mengakses value array. Fungsi ini yang akan digunakan untuk proses pengunduhan file hingga memindahkan semua hasil download ke folder yang ditentukan.
* Jika **fork()** dari proses spawning mengembalikan nilai negatif, maka program tidak akan berjalan.

            if (pid0 == 0) {
                printf("child[1] --> pid = %d and ppid = %d\n", getpid(), getppid());
                char *argva[] = {"wget", "--no-check-certificate", kue[i], "-qO", hewan[i], NULL};
                execv("/usr/bin/wget", argva);
            }

* Selanjutnya kami membuat kondisi lanjutan dimana jika **fork()** mengembalikan nilai 0, artinya berhasil membuat child process.
* Berikutnya kami membuat argument values untuk menyimpan paramter yang digunakan untuk mengunduh file-file yang dibutuhkan dari link yang ada di array **kue[i]** dan menyimpannya dengan nama yang ada di variabel **hewan[i]**.
* Lalu kami mengeksekusi parameter tersebut menggunakan fungsi **execv**
           
            else {
                while((wait(&status)) > 0);
                pid1 = fork();
                if (pid1 == 0) {
                    // sleep(2);
                    printf("child[2] --> pid = %d and ppid = %d\n", getpid(), getppid());
                    char *argvb[] = {"unzip", "-q", hewan[i], NULL};
                    execv("/usr/bin/unzip", argvb);
                }
                
* Dibuat kondisi lagi jika fork() mengembalikan nilai positif yang artinya proses sudah kembali lagi ke parent.
* Perulangan **while** dibuat dengan kondisi untuk memastikan bahwa proses child telah berhenti, lalu memanggil fungsi **fork()** lagi untuk menjalankan proses unzip.

                else {
                    while((wait(&status)) > 0);
                      
                        printf("parent --> pid = %d\nppid: %d\n", getpid(), getppid());                    
                        char lapres[5] = "/.", laprak[5] = "/";
                        char fisika[20], kimia[20];
                        strcpy(kimia, matematika[i]); //matematika[] = {"MUSIK", "FILM", "FOTO"};
                        strcpy(fisika, buah[i]); //buah[] = {"Musyik", "Fylm", "Pyoto"};
                        strcat(kimia, lapres); //MUSIK/*                                   
                        char *argvc[] = {"cp", "-r", kimia, fisika, NULL};
                        printf("\n----------OTW Move----------\n");
                        execv("/bin/cp", argvc);
                }
            }


        return;
        }

* Jika semua proses child sudah selesai, maka selanjutnya adalah dijalankannya kembali parent process untuk melakukan pemindahan file ke folder yang telah ditentukan.
* Setelah itu kami membuat variabel array **lapres[5]** yang berisi **/.** untuk memudahkan deklarasi path untuk masuk ke dalam folder yang diinginkan.
* Alasan dibuatnya variabel array **fisika[20]** dan **kimia[20]** adalah untuk penampungan dari variabel **matematika[i]** dan **buah[i]**. Penampungan dilakukan dengan cara mencopy string dalam **buah[i]** dan **matematika[i]** ke dalam sana.
* Lalu kami menggabungkan variabel **lapres[5]** dengan variabel **kimia** sehingga output yang diharapkan akan seperti ini: "MUSIK/"
* Dilanjutkan dengan pembuatan parameter untuk memindahkan semua isi array **fisika** ke array **kimia** sehingga output yang diharapkan menjadi: "MUSIK/Musyik"

        int penutupan(){

            pidv0 = fork();
            if (pidv0 < 0) exit(EXIT_FAILURE);

            if (pidv0 == 0){
                printf("\n---------All files zipped----------\n");
                char *argv0[] = {"zip", "-qr","Lopyu_Stevany.zip", buah[0], buah[1], buah[2], NULL}; //buah[] = {"Musyik", "Fylm", "Pyoto"};
                execv("/usr/bin/zip", argv0);

            }
            else {
                while((wait(&mantab)) > 0);
                printf("\n----------Folder Deleted----------\n");
                char *argv1[] = {"rm", "-r", buah[0], buah[1], buah[2], matematika[0], matematika[1], matematika[2], NULL}; //char* matematika[] = {"MUSIK", "FILM", "FOTO"};
                execv("/bin/rm", argv1);

            }
            return 1;

        }

* Selanjutnya kami membuat fungsi **penutupan**. 
* Di fungsi ini proses child akan me-zip folder yang ada di array **buah[i]** ke dalam **Lopyu_Stevany.zip**.
* Saat proses kembali ke parent, dilakukan penghapusan folder-folder yang ada di array **buah[]** dan **matematika[]**.

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

* Fungsi **deadline** ini digunakan untuk membuat waktu yang dibutuhkan untuk proses otomatis. Fungsi ini diawali dengan pendekalarasian variabel untuk menyimpan data tanggal dan waktu di C.
* **time()** digunakan untuk mengembalikan nilai waktu dari sistem.
* **localtime()** akan mengubah nilai dari **time_t** ke waktu kalender dan mengembalikan pointer ke struktur **tm** dimana setiap isinya mendapatkan value yang sesuai dengan rangenya masing-masing. Sebagai contoh hours akan diisi dengan nilai waktu jam, minutes akan diisi dengan nilai waktu menit, dst.

            if(
                day == 9 &&
                month == 4 &&
                year == 2021 &&
                hours == 16 &&
                minutes == 22 &&
                seconds == 0
            ) return 1;
            
* Dibuat sebuah kondisi yang akan mengembalikan nilai 1 jika waktu yang digunakan memenuhi deklarasi waktu seperti di atas. Waktu di atas adalah waktu di mana semua proses pengunduhan hingga pembuatan folder berjalan secara otomatis.

            else if(
                day == 9 &&
                month == 4 &&
                year == 2021 &&
                hours == 22 &&
                minutes == 22 &&
                seconds == 0
            ) return 2;
            
* Dibuat sebuah kondisi yang akan mengembalikan nilai 2 jika waktu yang digunakan memenuhi deklarasi waktu seperti di atas. Di atas merupakan waktu dimana semua folder-folder dihapus dan hanya menyisakan semua zip.

            else return 0;
        }

* Jika tidak memenuhi dua kriteria waktu di atas, maka akan dikembalikan nilai 0.

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

* Menuju ke fungsi main, kami ambil code di atas dari proses Daemon yang sudah diberikan pada modul 2.

            while (1){
                int batas = deadline();
                if (batas > 0 && batas == 1){
                    printf("----------Masuk 1----------\n");
                    
* Fungsi **deadline** yang mengembalikan nilai 1 digunakan sebagai parameter program untuk menjalankan fungsi **cobafork**.

                    pidsup = fork();
                 
                    if (pidsup < 0)
                    exit(EXIT_FAILURE);

                    if (pidsup == 0) {
                        char *argv[] = {"mkdir", "-p", "Musyik", "Fylm", "Pyoto", NULL};
                        execv("/bin/mkdir", argv);
                    }

* Ketika fungsi main berhasil membuat child process, dibuatlah parameter untuk membuat folder.

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
                            }

                            else {
                                while((wait(&mantab)) > 0);
                                pidsup3 = fork();
                                if (pidsup3 == 0){
                                    cobafork(2);
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
                
 * Jika sudah keluar dari child process, program akan menjalankan fungsi **coba fork** dari nilai **i** 0-2.

                if(batas > 0 && batas == 2){
                    printf("----------Masuk 2----------\n");
                    // penutupan();
                    if (penutupan() == 1) break;

                }

* Setelah semua proses **cobafork** selesai, selanjutnya digunakan parameter fungsi deadline yang mengembalikan nilai 2, akan dijalankan fungsi **penutupan**

                else printf("Waiting...\n");
                sleep(1);
            }


        }


### Soal 2

Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

* Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.
* Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip. Contoh: Jenis peliharaan kucing akan disimpan dalam “/petshop/cat”, jenis peliharaan kura-kura akan disimpan dalam “/petshop/turtle”.
* Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan. Contoh: “/petshop/cat/joni.jpg”. 
* Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “dog;baro;1_cat;joni;2.jpg” dipindah ke folder “/petshop/cat/joni.jpg” dan “/petshop/dog/baro.jpg”.
* Di setiap folder buatlah sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut. Format harus sesuai contoh.

    nama : joni
    umur  : 3 tahun

    nama : miko
    umur  : 2 tahun

#### Note

* Setiap data peliharaan disimpan sebagai nama foto dengan format [jenis peliharaan]:[nama peliharaan]:[umur peliharaan dalam tahun]. Jika terdapat lebih dari satu peliharaan, data dipisahkan menggunakan underscore(_).
* Tidak boleh menggunakan fungsi system(), mkdir(), dan rename().
* Menggunakan fork dan exec.

### Penyelesaian


## Soal 3

Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.
* Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].
* Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.
* Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.
* Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan program bash.
* Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).
Ranora meminta bantuanmu untuk membantunya dalam membuat program tersebut. Karena kamu anak baik dan rajin menabung, bantulah Ranora dalam membuat program tersebut!

#### Note
* Tidak boleh menggunakan system() dan mkdir()
* Program utama merupakan SEBUAH PROGRAM C
* Wajib memuat algoritma Caesar Cipher pada program utama yang dibuat

### Penyelesaian

* Source code lengkap ada di [Soal 3](https://github.com/maulida16/soal-shift-sisop-modul-2-IT04-2021/blob/main/soal3/soal3.c)
* Di bawah ini merupakan library yang akan digunakan di kode program soal 3 ini.

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
    

* Di awal program kami membuat fungsi bernama itik. Fungsi itik ini merupakan program caesar chiper untuk mengenkripsi keterangan yang akan dikeluarkan saat program berhasil dijalankan. Kami menggunakan perulangan yang akan mengiterasi huruf pada **message[i]** lalu menambahkannya dengan key.
* Pergeseran kunci berlaku baik untuk huruf kecil maupun huruf besar.
* **symbol = message[i];** digunakan sebagai variabel sementara untuk menampung huruf-huruf yang sudah ditambah oleh key-nya. Setelah pesan dalam variabel **symbol** terenskripsi, semua isinya akan dipindah ke variabel array **encrypted**. Setelah itu akan di tampilkan hasil enkripsinya menggunakan fungsi **printf**.

        char sandi[100];

        void itik(char message[100], int key){

        char encrypted[100], symbol;

        for(int i = 0; message[i] != '\0'; ++i){
        symbol = message[i];

        if(symbol >= 'a' && symbol <= 'z'){
            symbol = symbol + key;

            if(symbol > 'z'){
                symbol = symbol - 'z' + 'a' - 1;
            }

            encrypted[i] = symbol;
        }
        else if(symbol >= 'A' && symbol <= 'Z'){
            symbol = symbol + key;

            if(symbol > 'Z'){
                symbol = symbol - 'Z' + 'A' - 1;
            }

            encrypted[i] = symbol;
        }
      }
      strcpy(sandi, encrypted);
      printf("%s", sandi);
      }

 * Selanjutnya kami membuat fungsi killer untuk mengakhiri program yang dijalankan. Fungsi killer ini akan menyimpan alamat dari **killer.sh** dimana kami akan memanggilnya menggunakan fungsi **fopen** dengan mode "w" yang digunakan untuk membuka file untuk ditulis. 
                
        void generateKiller(char source[]){
            FILE *target;
            //buka/jalankan file killer.sh
            target = fopen("killer.sh", "w");
            int status;

* Fungsi fprintf digunakan untuk menulis string ke dalam file target yaitu **killer.sh** yang merupakan program bash.
* Di fungsi **generateKiller** inilah kami memastikan bahwa kedua mode kill dapat dijalankan. Kami menggunakan fungsi strcmp untuk memastikan bahwa string yang dimasukkan adalah benar. Alasan kami menggunakan pkill dibanding dengan kill adalah karena pada saat kami mencoba trial & error nya, pkill bisa mematikan semua proses dengan nama yang sama, sedangkan kill hanya bisa mematikan proses dengan PID yang disebutkan. 
            
                //mode 1 (-z)
            if (strcmp(source, "-z") == 0)
                fprintf(target, "#!/bin/bash\npkill -9 soal3\nrm killer.sh");
                //mode 2 (-x)
            if (strcmp(source, "-x") == 0)
                fprintf(target, "#!/bin/bash\npkill soal3\nrm killer.sh");
* Ketika dijalankan dengan mode kedua yang menggunakan parameter "-x", program akan berjalan di background sehingga untuk mengakses killer.sh perlu diganti modenya dengan menambahkan hak eksekusi ke user menggunakan "chmod", "u+x". Jika fungsi killer sudah berjalan dengan baik, maka akan dihentikan menggunakan fungsi **fclose**.

            if(fork() == 0){
              //set permission buat file killer biar 
              char *argv[] = {"chmod", "u+x", "killer.sh", NULL};
              execv("/bin/chmod", argv);
            }
            fclose(target);
        }
        
* Berikutnya kami membuat program untuk membuat sebuah file bernama **status.txt**. File inilah yang akan menyimpan string "Download Success" yang kemudian dienkripsi menggnakan fungsi **itik**. 

        void generate_statustxt(char folder_local[]){

            FILE *status_txt;

            char statuxt[50], status_name[100] = "/status.txt";
            sprintf(statuxt, "%s%s", folder_local, status_name);

            //buka/jalankan file killer.sh
            status_txt = fopen(statuxt, "w");

            char puyuh[100] = "Download Success";
            itik(puyuh, 5);

            fprintf(status_txt, "%s", sandi);

            //set nama file zip
            fclose(status_txt);
        }

* Proses selanjutnya adalah fungsi main dimana kami menggunakan fungsi template **Daemon Proses** dari modul yang telah diberikan.

* Program main kami akan membutuhkan argv dan argc untuk mengetahui berapa banyak dan apa saja parameter yang digunakan untuk mengeksekusi program. Jika jumlah parameter yang diberikan tidak sama dengan 2, maka program tidak akan berjalan.

        int main(int argc, char **argv){
            if(argc != 2){
                puts("argument is not valid");
                exit(EXIT_FAILURE);
            }
* **time_t** adalah sebuah fungsi yang akan mengembalikan waktu saat ini.
* Kami membuat fungsi mennggunakan <em>time structure</em> yang diberi nama **tm_info**. Fungsi ini berfungsi sebagai sebuah pointer fungsi yang akan mengambil value dari timer.

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
            
* **while(1)** berarti infinite loop.

          //while untuk membuat folder dan zip
                while (1) {
                
* Di awal perulangan, timer diset dengan NULL terlebih dahulu, lalu di tm_info akan diisi waktu oleh jadwal kalender saat itu juga.

                    timer = time(NULL);
                    tm_info = localtime(&timer);
                    
* Di sini kami membuat folder yang namanya berdasarkan waktu saat ini, dan waktunya diambil dari **tm_info**
                    
                    char folder_name[100];
                    //formatnya beda, jangan luapa diganti
                    strftime(folder_name, 100, "%Y-%m-%d_%H:%M:%S", tm_info);
                    
* Selanjutnya kami membuat variabel untuk menjalankan fork.

                    //bikin var pid buat child, jalanin fork()
                    pid_t child_id;
                    child_id = fork();
                    
* Di sini kami membuat deklarasi untuk exit function yaitu dengan **int status**. "status" bertujuan untuk menutup semua proses yang berjalan dan setiap child proses yang mendapat nilai 1, program akan dijalankan dan parent process akan memanggil sinyal SIGCHLD.

                    int status;
                    
* Selanjutnya dibuat kondisi jika spawning proses gagal dijalankan, atau fork mengembalikan nilai negatif, maka program akan terhenti.

                    //exit klo gagal
                    if (child_id < 0) 
                    exit(EXIT_FAILURE);
                    
* Dilanjutkan dengan kondisi jika program berhasil membuat child process dan jika fork berhasil mengembalikan nilai 0 yang dapat memastikan bahwa child process benar-benar berjalan, maka selanjutnya yang terjadi adalah dibuatnya sebuah argument values yang membuat sebuah folder dengan nama yang akan diatur di **folder_name**.

                    //klo berhasil bikin child
                    if (child_id == 0){ 
                        //klo di dalem child (fork() == 0)
                        if (fork() == 0){
                            //buat folder namanya sesuai yang diatur di folder_name
                            char *argv[] = {"mkdir", "-p", folder_name, NULL};
                            execv("/bin/mkdir", argv);
                        }
                                    
* Jika program sudah tidak berada dalam child process atau fork mengembalikan nilai positif yang mana PID dari child akan dikembalikan ke parent, maka program akan membuat perulangan untuk mendownload gambar hingga 10 gambar. Program akan mendownload gambar jika fork berhasil membuat child proses dan selanjutnya program akan berpindah ke direktori dari folder yang sudah dibuat tadi.

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
                                   
* Kami menggunakan library **time.h** yang berfungsi sebagai penyimpanan waktu download file.

                                    //bikin var buat timer
                                    time_t file_timer;
                                    struct tm* file_tm_info;
                                    file_timer = time(NULL);
                                    file_tm_info = localtime(&file_timer);
                                  
* Deklarasi variabel ini digunakan untuk menyimpan ukuran dari gambar yang akan di download dimana **t** sendiri diambil dari detik waktu Epoch UNIX.                               
                                    
                                    //t = waktu epoch
                                    int t = (int)time(NULL);
                                    t = (t % 1000) + 100;
                                    
* Selanjutnya kami mendeklarasikan variabel url untuk menyimpan url dari website yang digunakan untuk mendownload gambar. Kami memasukkan url tersebut ke file url menggunakan fungsi **sprintf**.

                                    char url[100];
                                    //url buat donwload gambar persegi txt
                                    sprintf(url, "https://picsum.photos/%d", t);
                                    
* Setelah itu kami membuat variabel untuk menyimpan nama file yang berisi waktu lokal yang didapatkan dari file_tm_info. Lalu mendownload filenya menggunakan parameter **wget** dari variabel url tadi dan dieksekusi menggunakan **execv**.

                                    char file_name[100];
                                    //set nama filenya
                                    strftime(file_name, 100, "%Y-%m-%d_%H:%M:%S", file_tm_info);
                                    //download filenya
                                    char *argv[] = {"wget", url, "-qO", file_name, NULL};
                                    execv("/usr/bin/wget", argv);
                                }
* Ketika child process ini sudah selesai dijalankan, process akan dinonaktifkan selama 5 detik lalu kembali melakukan iterasi hingga jumlah gambar yang ter-download mencapai 10 gambar.

                            //loop downloadnya dijalanin tiap 5 detik
                            sleep(5);
                            }
                            
* Jika sepuluh gambar sudah terdownload, maka program akan menjalankan fungsi **generate_statustxt** untuk membuat file berisi string "Download Success" yang telah dienkripsi.
* Setelah itu membuat zip dengan nama yang sama dengan folder dan mengeksekusi perintah ini menggunakan parameter **zip**.

                            generate_statustxt(folder_name);
                            char folder_name_zip[100];
                            sprintf(folder_name_zip, "%s.zip", folder_name);
                            //bikin file zip (compress) namanya sesuai yang udah di set
                            char *argv[] = {"zip", "-qrm", folder_name_zip, folder_name, NULL};
                            execv("/usr/bin/zip", argv);
                        }  
                        

* Ketika program sudah melakukan semua perintah iterasi download gambar hingga me-zip folder, program akan dinonaktifkan selama 40 detik sebelum kembali menjalankan program.
                    
                    }
                    else sleep(40);
            }
        }
