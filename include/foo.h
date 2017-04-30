#ifndef FOO_H
#define FOO_H

struct foo{
	int a;
};

void change_a ( foo *myFoo );
int get_a(const foo *myFoo );

//void change_a ( foo *&myFoo );
//int get_a(const foo *&myFoo );


#endif