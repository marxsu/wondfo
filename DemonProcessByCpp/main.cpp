#include<pthread.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/syslog.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <memory.h>

#define PROC_FILE_PATH "/usr/local/app/"
#define PROC_NAME_CLIENT "FineCarePlus114"

//#define PROC_FILE_PATH "/root/build-QIAnalyzer-unknown-Debug/"
//#define PROC_NAME_CLIENT "app-multi"

int start_proc_by_name(const char* procname)
{
    pid_t pid, child_pid;
    char  filename[100];
    sprintf(filename, "%s%s", PROC_FILE_PATH, procname);
    child_pid = 0;

    if (access(filename, X_OK | F_OK) != 0) {                                  /* 如果文件存在，并且可执行 */
        return 0;
    }

    char  cmd[100];
    sprintf(cmd,"./%s",procname);
//    system(cmd);//会创建一个bash子进程执行命令


    pid = fork();                                                              /* 首先要fork一个进程出来 */

    if (pid < 0) {
        return 0;
    } else if (pid == 0) {                                                     /* 创建进程成功，此处是子进程的代码 */
        if (execl(filename,cmd,"-qws",NULL) != -1) {
            exit(0);
        } else {
            exit(1);
        }
    } else {                                                                   /* 创建进程成功，此处是父进程代码 */
        child_pid = pid;
    }

    return (int)child_pid;
}
int cmd_system(const char* command)
{
    int state;char *result = "";
    FILE *fpRead;
    fpRead = popen(command, "r");
    if(fpRead != NULL)
    {
        char buf[1024];
        memset(buf,'\0',sizeof(buf));
        while(fgets(buf,1024-1,fpRead)!=NULL)
        {
            result = buf;
        }
        if(fpRead!=NULL)
            pclose(fpRead);
        std::string strResult(result);
        if(strResult.empty())
        {
            state = 1;
        }else
        {
            state = 2;
        }
    }else
    {
        state = 0;
    }
    return state;
}


int proc_watch(const char *procname)
{
    int  result, state;
    char cmd[100];
    sprintf(cmd, "pidof %s", procname);

    state = cmd_system(cmd);

    switch (state)
    {
        case 0:
            result = -1;
            break;

        case 1:
            result = start_proc_by_name(procname);
            break;

        case 2:
            result = 0;
            break;

        default:
            break;
    }

    return result;
}

int init_daemon(void)
{
    int pid;
    int i;

    signal(SIGTTOU,SIG_IGN);
    signal(SIGTTIN,SIG_IGN);
    signal(SIGTSTP,SIG_IGN);
    signal(SIGHUP ,SIG_IGN);


    if( pid=fork() )
    {
        exit(0);
    }else if(pid< 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }


    setsid();


    if( pid=fork() )
    {
        exit(0);
    }else if(pid< 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    for(i=0; i< NOFILE; ++i)
    {
        close(i);
    }
    chdir("/tmp");
    umask(0);
    signal(SIGCHLD,SIG_IGN);
    return 0;
}

int main(int argc, char *argv[])
{
    init_daemon();
    while(1)
    {
        int result;
        printf("time to check process...\n");

        result = proc_watch(PROC_NAME_CLIENT);
        if (result == -1) {
            printf("popen cmd exec faild...\n");
        } else if (result == 0) {
            printf("process running ok...\n");
        } else {
            printf("process has gone! but restarted...\n");
        }
        sleep(6);
    }

    return 0;
}
