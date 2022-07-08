#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define MSG_MIN 0
#define MSG_MAX 10

// global variables
char troll_msg[11][BUFSIZ] = {
    "no",
    "yohoooo",
    "pffffdfffdfs",
    "when life gives you lemons, make lemonade",
    "i LOVE the energy, but let's bring it down a notch :)",
    "is everything okay?",
    "be happi",
    "jeez, you didn't have to be rude!",
    "sorry, not sorry",
    "bae.",
    "ayo"
};
 
// function declarations
void term(int signum);
void print_troll(char *fname, char troll_msg[10][BUFSIZ]);
static void sigintHandler(int sig);
static void sigtermHandler(int sig);

// function definitions 
static void sigintHandler(int sig){
    print_troll("troll.txt", troll_msg);
}

static void sigtermHandler(int sig){
    print_troll("troll.txt", troll_msg);
}

void print_troll(char *fname, char troll_msg[10][BUFSIZ]){
    FILE *fp = fopen(fname, "r");
    char c;
        
    while((c = fgetc(fp)) != EOF) fputc(c, stdout);
 
    int num = (rand() % (MSG_MAX - MSG_MIN + 1) + MSG_MIN);
    printf("%d\n", num); //db
    printf("                      %s\n\n", troll_msg[num]);
    
    fclose(fp);
    return;
}

int main(int argc, char *argv[]){

    srand(time(0));

    print_troll("troll.txt", troll_msg);
    
    while(1){
        signal(SIGINT, sigintHandler);
        signal(SIGTERM, sigtermHandler);
    }
    
    return 0;
}
