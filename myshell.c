#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main(){
    
    char *input = NULL;
    char *array[20];
    char * word;
    ssize_t bufsize = 32;
    int frk,execvReturn,ampersanIndex,frk2,execvReturn2;
    char *sendData[2];
   
    while(1){
        printf("myshell>>");
        bool isThereAmpersan = false;
        getline(&input, &bufsize, stdin);
        word= strtok(input," ");
        int i = 0;
        
        while(word != NULL){
            array[i]= word;
            if(strncmp(array[i],"&",1)==0){
                isThereAmpersan = true;
                ampersanIndex = i;//ampersanın bulunduğu indexi aldım. Bir sonraki index ikinci programın ismini tutacak.
               //  printf("ampesan vaaar!\n");
            }
            //printf("array[%d]:%s >>",i,array[i]);
            i++; 
            word= strtok(NULL," ");
        }
        
        if(strncmp(array[0],"exit",4)==0){//newargv ile diğer stringin ilk 4 karakteri karşılaştırılıyor  exit komutu
                printf("myshell sonlandırıldı!\n");
                 break;
        }
        
        frk = fork();
        if(frk == 0){
            if(strncmp(array[0],"clear",5)==0){// 'clear' komutu için
                system("clear");            
            }
            else if(strncmp(array[0],"rakam",5)==0){// 'rakam' komutu için
                sendData[0] = array[1];
                sendData[1] = NULL;
                execvReturn = execv("rakam",sendData);
                perror("execve failed!");
            }
            else if(strncmp(array[0],"mul",3)==0){// 'mul' komutu için
                sendData[0] = array[1];
                sendData[1] = array[2];
                execvReturn = execv("mul",sendData);
                perror("execve failed!");
            }
            else if(strncmp(array[0],"div",3)==0){// 'div' komutu için
                sendData[0] = array[1];
                sendData[1] = array[2];
                execvReturn = execv("div",sendData);
                perror("execve failed!");
            }
            else if(strncmp(array[0],"cat",3)==0){// 'cat' komutu için
                printf("cat: %s",array[1]);            
            }
            else{
                printf("yanlis bir komut girdiniz!\n");                           
            }
            
            exit(0); //child proses işini bitirince sonsuz döngüye girmesin diye yazdım.
        }
        else{//ILK FORK SONRASI PARENTIN GİRDİGİ BOLGE
             if(strncmp(array[0],"rakam",5)==0){//do nothing //hoca özel olarak rakamı beklemesin dediği için yazdım
             }
             else{wait(0);wait(&execvReturn);}  
 
             if(isThereAmpersan == true){//arada ampersan varsa ikinci program çalışacak
                frk2 = fork();//AMPERSAN VARSA PARENT 2.KEZ FORK YAPACAK
                if(frk2 == 0){//2.FORK SONUCU OLUSAN COCUK
                    if(strncmp(array[ampersanIndex+1],"clear",5)==0){// 'clear' komutu için
                    system("clear");            
                        }
                     else if(strncmp(array[ampersanIndex+1],"rakam",5)==0){// 'rakam' komutu için
                            sendData[0] = array[ampersanIndex+2];
                            sendData[1] = NULL;
                            execvReturn2 = execv("rakam",sendData);
                            perror("execve failed!");
                    }
                      else if(strncmp(array[ampersanIndex+1],"mul",3)==0){// 'mul' komutu için
                        sendData[0] = array[ampersanIndex+2];
                        sendData[1] = array[ampersanIndex+3];
                        execvReturn2 = execv("mul",sendData);
                        perror("execve failed!");
                  }
                      else if(strncmp(array[ampersanIndex+1],"div",3)==0){// 'div' komutu için
                        sendData[0] = array[ampersanIndex+2];// +2 &'dan sonraki ikinci karakter oluyor. amperanındex=& ampersanındex+1=ampersandan sonra gelen programın adı ampersanındex+2 programın ilk degeri ampersanındex+2= programın ikinci degeri
                        sendData[1] = array[ampersanIndex+3];
                        execvReturn2 = execv("div",sendData);
                        perror("execve failed!");
                    }
                       else if(strncmp(array[ampersanIndex+1],"cat",3)==0){// 'cat' komutu için
                        printf("cat: %s",array[ampersanIndex+2]);            
                      }
                        else{
                             printf("yanlis bir komut girdiniz\n");                           
                            }
                        exit(0);
                  }
                  else{//2.FORKTAN SONRA PARENTIN GIRDIGI YER
                    if(strncmp(array[ampersanIndex+1],"rakam",5)==0){//do nothing //hoca özel olarak rakamı beklemesin dediği için yazdım
                    }
                    else{wait(0);wait(&execvReturn2);} 
            }

            }
            //2.FORKTAN SONRA PARENTIN GIRDIGI YEr parantezi
        }//IF AMPERSANIN PARANTEZI
    }

return 0;
}
