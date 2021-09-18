#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>

void parse(char*);//
void ls();//
void ls_l(); 
void clear();//
void quit();//
void makedir(char*);//
void cd(char*);
void env(char *en[]);
void rmd(char*);
void pwd();
void history(char*);//history or history <number>
void history_file();


int main(int argc, char *argv[], char *envp[])
{
char buff[FILENAME_MAX];
char *cmd;

//getcwd(buff,FILENAME_MAX);
cmd = (char*)calloc(100, sizeof(char));

while(1){
  getcwd(buff, FILENAME_MAX);
  printf("\n%s>",buff);  //linux prompt - shell
  fgets(cmd, 100, stdin);  //fgets - read ' ' also
  history_file(cmd);
  if(strncmp(cmd, "env", 3)==0)
     env(envp);
  parse(cmd);
}

return 0;
}


void parse(char *cmd)
{
 if(strncmp(cmd, "ls", strlen(cmd)-1)==0)
    ls();
 else if(strncmp(cmd, "ls -l", strlen(cmd)-1)==0)
    ls_l();
 else if(strncmp(cmd, "clear", strlen(cmd)-1)==0)
    clear();
else if(strncmp(cmd, "quit", strlen(cmd)-1)==0)
    quit();
else if(strncmp(cmd, "mkdir", 5)==0)
    makedir(cmd); 
else if(strncmp(cmd, "cd", 2)==0)  //cmd --> cd oslab4
    cd(cmd);
else if(strncmp(cmd, "rmdir", 5)==0)  //cmd-->rmdir oslab4
    rmd(cmd);
else if(strncmp(cmd, "pwd", strlen(cmd)-1)==0)
    pwd();
else if(strncmp(cmd, "history", 7)==0)  //history   or   history <num>
    history(cmd); 
else
    printf("\nInvalid Unix Command..");
}

void history_file(char *cmd)//cwd->ls
{
  FILE *fp = fopen("history.txt", "a");
   
  if(fp==NULL)
  {
    printf("Error...");
    exit(1);
  }

   fprintf(fp, "%s", cmd);
 
   fclose(fp);
}


void ls()
{
  struct dirent *de;
  
  DIR *dr = opendir(".");

  if( dr==NULL )
  {
     printf("Error opening directory...");
     exit(0);
  }
  
  while( (de = readdir(dr))!=NULL )
     printf("%s\n", de->d_name);

  closedir(dr);
  
}

void ls_l()
{
     printf("Implemetation pending.....");
 //  system("ls -l");  //this is expected  

}

void makedir(char *cmd)
{
   //cmd->test001
    char *p;
    int i;

    p = NULL;
    int len = strlen(cmd);
    p = (char*)calloc(50, sizeof(char));
    for( i=1 ; i<=6 ; i++)
        cmd++;

   // printf("%s\n", p);
    strncpy(p, cmd, len-7);
   // printf("%s\n", p);

    if(mkdir(p, 0777) == -1 )
         printf("Invalid Command....");
    else
         printf("directory named %s created", p);

     p=NULL;

}

void cd(char *cmd)  //cmd-->oslab4\n  //p->oslab4
{
    system("cd");
}

void rmd(char *cmd)  //p-->oslab4
{
  printf("Implementation pending...");

}

void clear()
{
 system("clear");  //hacking
}
  

void quit()
{
 exit(0);
}

void  env(char *en[])//en[0]-->   en[1]-->   en[2]-->   ...en[n]=NULL
{
  printf("Implemntation pending...");

}

void pwd()
{
   system("pwd");
}

void history(char *cmd)  //history (or) history <num> eg: history 5
{
  printf("Implementation Pending....");
  
}



