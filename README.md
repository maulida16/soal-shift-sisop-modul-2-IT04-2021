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
    
* Diatas merupakan library yang akan digunakan di kode program soal 3 ini.

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

* Di awal program kami membuat fungsi bernama itik. Fungsi itik ini merupakan program caesar chiper untuk mengenkripsi keterangan yang akan dikeluarkan saat program berhasil dijalankan. Kami menggunakan perulangan yang akan mengiterasi huruf pada **message[i]** lalu menambahkannya dengan key.
* Pergeseran kunci berlaku baik untuk huruf kecil maupun huruf besar.
* **symbol = message[i];** digunakan sebagai variabel sementara untuk menampung huruf-huruf yang sudah ditambah oleh key-nya. Setelah pesan dalam variabel **symbol** terenskripsi, semua isinya akan dipindah ke variabel array **encrypted**. Setelah itu akan di tampilkan hasil enkripsinya menggunakan fungsi **printf**.

        void generateKiller(char source[]){
            FILE *target;
            //buka/jalankan file killer.sh
            target = fopen("killer.sh", "w");
            int status;
            
 * Selanjutnya kami membuat fungsi killer untuk mengakhiri program yang dijalankan. Fungsi killer ini akan menyimpan alamat dari **killer.sh** dimana kami akan memanggilnya menggunakan fungsi **fopen** dengan mode "w" yang digunakan untuk membuka file untuk ditulis. 
                
                //mode 1 (-z)
            if (strcmp(source, "-z") == 0)
                fprintf(target, "#!/bin/bash\npkill -9 soal3\nrm killer.sh");
                //mode 2 (-x)
            if (strcmp(source, "-x") == 0)
                fprintf(target, "#!/bin/bash\npkill soal3\nrm killer.sh");

* Fungsi fprintf digunakan untuk menulis string ke dalam file target yaitu **killer.sh**
* Di fungsi **generateKiller** inilah kami memastikan bahwa kedua mode kill dapat dijalankan. Kami menggunakan fungsi strcmp untuk memastikan bahwa string yang dimasukkan adalah benar. Alasan kami menggunakan pkill dibanding dengan kill adalah karena pada saat kami mencoba trial & error nya, pkill bisa mematikan semua proses dengan nama yang sama, sedangkan kill hanya bisa mematikan proses dengan PID yang disebutkan. 

            if(fork() == 0){
              //set permission buat file killer biar 
              char *argv[] = {"chmod", "u+x", "killer.sh", NULL};
              execv("/bin/chmod", argv);
            }
            fclose(target);
        }
        
* Ketika dijalankan dengan mode kedua yang menggunakan parameter "-x", program akan berjalan di background sehingga untuk mengakses killer.sh perlu diganti modenya dengan menambahkan hak eksekusi ke user menggunakan "chmod", "u+x". Jika fungsi killer sudah berjalan dengan baik, maka akan dihentikan menggunakan fungsi **fclose**.

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
* Berikutnya kami membuat program untuk membuat sebuah file bernama **status.txt**.  Pada awalan program kami ................ Selanjutnya, pada file status

* Proses selanjutnya adalah fungsi main dimana kami menggunakan fungsi template **Daemon Proses** dari modul yang telah diberikan.

        int main(int argc, char **argv){
            if(argc != 2){
                puts("argument is not valid");
                exit(EXIT_FAILURE);
            }

* Program main kami akan membutuhkan argv dan argc untuk mengetahui berapa banyak dan apa saja parameter yang digunakan untuk mengeksekusi program. Jika jumlah parameter yang diberikan tidak sama dengan 2, maka program tidak akan berjalan.

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
            
* **time_t** adalah sebuah fungsi yang akan mengembalikan waktu saat ini.
* Kami membuat fungsi mennggunakan <em>time structure</em> yang diberi nama **tm_info**. Fungsi ini berfungsi sebagai sebuah pointer fungsi yang akan mengambil value dari timer.

          //while untuk membuat folder dan zip
                while (1) {
                
* **while(1)** berarti infinite loop

                    timer = time(NULL);
                    tm_info = localtime(&timer);
* Di awal perulangan, timer diset dengan NULL terlebih dahulu, 
                    char folder_name[100];
                    //formatnya beda, jangan luapa diganti
                    strftime(folder_name, 100, "%Y-%m-%d_%H:%M:%S", tm_info);

                    //bikin var pid buat child, jalanin fork()
                    pid_t child_id;
                    child_id = fork();

                    //nggak tau buat apa
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
                                    //bikin var buat timer
                                    time_t file_timer;
                                    //iki lapo mbuh
                                    struct tm* file_tm_info;

                                    file_timer = time(NULL);
                                    file_tm_info = localtime(&file_timer);

                                    //t = waktu epoch
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





