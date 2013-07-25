#define NUMBER '0'
#define VARGET '1'
#define VARPUT '2'

//Stack
void push(double);
double pop(void);
double peek(void);
void clear(void);

//Vars
double get(char);
void put(char, double);

int getop(char []);
int getch(void);
void ungetch(int);
