#include "test.h"

/*
    最終的に使う側はこんな感じになります
*/
int main(void)
{
    
    Interface* Interface = CreateInterface( 1024, 512 );
    Interface->PrintData( Interface );
    ReleaseInterface( Interface );
    
    return 0;
}

/*	ここまで	*/