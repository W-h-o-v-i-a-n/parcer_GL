/* --version, -v   -->   prints version
 * --value, -V     -->   takes int argument
 * --list, -l      -->   takes list of int arg
 * --message       -->   prints secret message
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

struct allArgs {
    char version;  /*-v option*/
    char value;    /*-V option*/
    int *val1;
    int list;     /*-L option*/
    char *vlist;
    char message;  /*secret message*/
} allArgs;

static const char *optString = "vV:L:h";

static const struct option longOpts[] = {
    {"version", no_argument, NULL, 'v'},
    {"value", required_argument, NULL, 'V'},
    {"list", required_argument, NULL, 'L'},
    {"message", no_argument, NULL, 0},
    {"help", no_argument, NULL, 'h'},
    {NULL, no_argument, NULL, 0}
};

void display_usage(void){
    puts("--version, -v   -->   prints version");
    puts("--value, -V     -->   takes an int argument");
    puts("--list, -l      -->   takes list of int arg");
    puts("--message       -->   prints secret message");
    puts("--help          -->   prints this message");

    exit( EXIT_FAILURE );
};

void executeit(void){
    if (allArgs.version == 1) {
        puts("version 1.0.0");
        puts("all rights reserved");
        puts("BRO corporation\n");
    };

    if (allArgs.value == 1) {
        printf("Arg: V = ");
	puts(allArgs.val1);
    };

    if (allArgs.list == 1){
        printf("Arg L = "); 
	puts(allArgs.vlist);
    };
};

int main (int argc, char **argv)
{
    int opt = 0;
    int long_index = 0;

    allArgs.version = 0;
    allArgs.value = 0;
    allArgs.val1 = NULL;
    allArgs.list = 0;
    allArgs.vlist = NULL;
    allArgs.message = 0;


    opt = getopt_long(argc, argv, optString, longOpts, &long_index);
    while ( opt != -1) {
        switch (opt) {
            case 'v':
                allArgs.version = 1;
                break;
            case 'V':
		allArgs.value = 1;
                allArgs.val1= optarg;
                break;
            case 'L':
		allArgs.list = 1;
                allArgs.vlist = optarg;
                break;
            case 'h':
                display_usage();
                break;
            case '?':
                display_usage();
                break;
            case 0:
                if( strcmp( "message", longOpts[long_index].name ) == 0 ) {
                    puts("Hello world");
                }
            default:
                break;
        }

        opt = getopt_long( argc, argv, optString, longOpts, &long_index );
    }

    executeit();
    return 0;
}
